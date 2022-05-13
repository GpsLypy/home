/*
 *  本程序用于处理全国气象站点观测的分钟数据，并保存到数据库的T_SURFDATA表中。
 *  与psurfdata.cpp不同，本程序只支持xml格式。
 *  作者：码农有道 日期：20190905
*/
#include "_public.h"
#include "_ooci.h"
#include "_shqx.h"

CLogFile logfile;

CDir Dir;

// 处理数据文件
bool _psurfdata();

connection conn;

void EXIT(int sig);

int main(int argc,char *argv[])
{
  if (argc!=5)
  {
    printf("\n本程序用于处理全国气象站点观测的分钟数据，并保存到数据库的T_SURFDATA表中。\n");
    printf("与psurfdata.cpp不同，本程序只支持xml格式。\n");
    printf("/htidc/shqx/bin/psurfdata1 数据文件存放的目录 日志文件名 数据库连接参数 程序运行时间间隔\n");
    printf("例如：/htidc/shqx/bin/psurfdata1 /data/shqx/sdata/surfdata /log/shqx/psurfdata1.log shqx/pwdidc@snorcl11g_198 10\n");
    return -1;
  }

  // 关闭全部的信号和输入输出
  CloseIOAndSignal();

  // 处理程序退出的信号
  signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

  if (logfile.Open(argv[2],"a+")==false)
  {
    printf("打开日志文件失败（%s）。\n",argv[2]); return -1;
  }

  logfile.Write("程序启动。\n");

  while (true)
  {
    // logfile.Write("开始扫描目录。\n");

    // 扫描数据文件存放的目录，匹配"SURF_ZH_*.xml"
    if (Dir.OpenDir(argv[1],"SURF_ZH_*.xml",1000,true,true)==false)
    {
      logfile.Write("Dir.OpenDir(%s) failed.\n",argv[1]); sleep(atoi(argv[4])); continue;
    }

    // 逐个处理目录中的数据文件
    while (true)
    {
      if (Dir.ReadDir()==false) break;
  
      if (conn.m_state==0)
      {
        if (conn.connecttodb(argv[3],"Simplified Chinese_China.ZHS16GBK")!=0)
        {
          logfile.Write("connect database(%s) failed.\n%s\n",argv[3],conn.m_cda.message); break;
        }
        // logfile.Write("连接数据库成功。\n");
      }
  
      logfile.Write("开始处理文件%s...",Dir.m_FileName);
  
      // 处理数据文件
      if (_psurfdata()==false) 
      {
        logfile.WriteEx("失败。\n"); break;
      }
    }

    // 断开与数据库的连接
    if (conn.m_state==1) conn.disconnect(); 

    sleep(atoi(argv[4]));
  }

  return 0;
}

void EXIT(int sig)
{
  logfile.Write("程序退出，sig=%d\n\n",sig);

  exit(0);
}
     

// 处理数据文件
bool _psurfdata()
{
  // 打开文件
  CFile File;

  if (File.Open(Dir.m_FullFileName,"r")==false)
  {
    logfile.Write("(File.Open(%s) failed.\n",Dir.m_FullFileName); return false;
  }

  CSURFDATA SURFDATA(&conn,&logfile);

  // 读取文件中的每一行记录
  // 写入数据库的表中
  char strBuffer[301];

  while (true)
  {
    memset(strBuffer,0,sizeof(strBuffer));

    if (File.FFGETS(strBuffer,300,"<endl/>")==false) break;

    // logfile.Write("str=%s=\n",strBuffer);

    // logfile.Write("%s\n",strBuffer);
    
    if (SURFDATA.SplitBuffer1(strBuffer)==false) { logfile.Write("%s\n",strBuffer); continue; }

    long rc=SURFDATA.InsertTable();

    // 只要不是数据库session的错误，程序就继续。
    if ( (rc>=3113) && (rc<=3115) ) return false;

    if (rc != 0) { logfile.Write("%s\n",strBuffer); continue; }
  }

  // 提交事务
  conn.commit();

  // 关闭文件指针，并删除文件
  File.CloseAndRemove();

  logfile.WriteEx("成功(total=%d,insert=%d,update=%d,invalid=%d)。\n",SURFDATA.totalcount,SURFDATA.insertcount,SURFDATA.updatecount,SURFDATA.invalidcount);

  return true;
}



