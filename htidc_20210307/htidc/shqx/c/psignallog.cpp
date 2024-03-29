/*
 *  本程序用于处理分区预警信号发布日志，并保存到数据库的T_SIGNALLOG表中。
 *  作者：码农有道 日期：20190905
*/
#include "_public.h"
#include "_ooci.h"
#include "_shqx.h"

CLogFile logfile;

CDir Dir;

// 处理数据文件
bool _psignallog();

connection conn;

void EXIT(int sig);

int main(int argc,char *argv[])
{
  if (argc!=5)
  {
    printf("\n本程序用于处理分区预警信号发布日志，并保存到数据库的T_SIGNALLOG表中。\n");
    printf("/htidc/shqx/bin/psignallog 数据文件存放的目录 日志文件名 数据库连接参数 程序运行时间间隔\n");
    printf("例如：/htidc/shqx/bin/psignallog /data/shqx/sdata/wpfiles /log/shqx/psignallog.log shqx/pwdidc@snorcl11g_198 10\n");
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

    // 扫描数据文件存放的目录，只匹配"WP20*.DTB"
    if (Dir.OpenDir(argv[1],"WP20*.DTB",1000,true,true)==false)
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
      if (_psignallog()==false) 
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
bool _psignallog()
{
  // 打开文件
  CFile File;

  if (File.Open(Dir.m_FullFileName,"r")==false)
  {
    logfile.Write("(File.Open(%s) failed.\n",Dir.m_FullFileName); return false;
  }

  CSIGNALLOG SIGNALLOG(&conn,&logfile);

  // 读取文件中的每一行记录
  // 写入数据库的表中
  char strBuffer[301];

  while (true)
  {
    memset(strBuffer,0,sizeof(strBuffer));

    // 从文件中获取一行记录
    if (File.Fgets(strBuffer,300,true)==false) break;

    // 每行预警信号发布的记录的最后都是用"000="结束的。
    if (strstr(strBuffer,"000=")==0) continue;

    UpdateStr(strBuffer,"  "," ",true);  // 把内容中的两个空格替换成一个空格
    // logfile.Write("%s\n",strBuffer);
    
    // 把用逗号分隔的记录拆分到结构体中
    if (SIGNALLOG.SplitBuffer(strBuffer)==false) { logfile.Write("%s\n",strBuffer); continue; }

    // 把vsignallog容器中的值更新到T_SIGNALDATA表中。
    long rc=SIGNALLOG.InsertTable();

    // 只要不是数据库session的错误，程序就继续。
    if ( (rc>=3113) && (rc<=3115) ) return false;

    if (rc != 0) { logfile.Write("%s\n",strBuffer); continue; }
  }

  // 提交事务
  conn.commit();

  // 关闭文件指针，并删除文件
  File.CloseAndRemove();

  logfile.WriteEx("成功(total=%d,insert=%d,update=%d,invalid=%d)。\n",SIGNALLOG.totalcount,SIGNALLOG.insertcount,SIGNALLOG.updatecount,SIGNALLOG.invalidcount);

  return true;
}



