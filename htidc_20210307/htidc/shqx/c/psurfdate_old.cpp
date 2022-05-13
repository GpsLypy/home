//未优化前的程序
#include "_public.h"
#include "_shqx.h"
#include "_ooci.h"

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
    printf("/htidc/shqx/bin/psurfdate_old 数据文件存放的目录 日志文件名 数据库连接参数 程序运行时间间隔\n");
    printf("例如：/htidc/shqx/bin/psurfdate_old /data/shqx/sdata/surfdata /log/shqx/psurfdate_old.log shqx/pwdidc 10\n");
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
 
 logfile.Write("程序开始启动...\n");
 while(true)
 {
//   logfile.Write("开始扫描目录...\n");
     // 1-扫描数据文件存放的目录
   if (Dir.OpenDir(argv[1],"SURF_ZH_*.txt",1000,true,true)==false)
   {
     logfile.Write("Dir.OpenDir(%s) failed.\n",argv[1]);sleep(atoi(argv[4]));continue;
   } 

      // 2-逐个处理目录中的数据文件
      while (true)
       {
         if (Dir.ReadDir()==false) break;//文件已读完
 
         if(conn.m_state==0)//
          { 
           if (conn.connecttodb(argv[3],"Simplified Chinese_China.ZHS16GBK")!=0)
            {
             logfile.Write("connect database(%s) failed.\n%s\n",argv[3],conn.m_cda.message); break;
            }
    //       logfile.Write("连接数据库成功\n");
          }


         logfile.Write("开始处理文件%s...",Dir.m_FullFileName);
  
         // 处理数据文件
         if (_psurfdata()==false)  {logfile.WriteEx("失败。\n"); break;}
      
         logfile.WriteEx("成功。\n");
     
       }
    
  if(conn.m_state==1) {conn.disconnect();}
    //logfile.Write("断开与数据库的连接。\n")//处理一批文件之后，断开与数据库的连接。
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
 
  // 读取文件中的每一行记录
  // 写入数据库的表中
  char strBuffer[301];
  CCmdStr CmdStr;//拆分类
  struct st_surfdata stsurfdata;
  
  int iccount=0;
  sqlstatement stmtsel(&conn);
  stmtsel.prepare("select count(*) from T_SURFDATA where obtid=:1 and ddatetime=to_date(:2,'yyyy-mm-dd hh24:mi:ss')");
  
  stmtsel.bindin( 1, stsurfdata.obtid,5);
  stmtsel.bindin( 2, stsurfdata.ddatetime,19);
  stmtsel.bindout(1,&iccount); 

  sqlstatement stmtins(&conn);
  stmtins.prepare("insert into T_SURFDATA(obtid,ddatetime,t,p,u,wd,wf,r,vis,crttime,keyid) values(:1,to_date(:2,'yyyy-mm-dd hh24:mi:ss'),:3,:4,:5,:6,:7,:8,:9,sysdate,SEQ_SURFDATA.nextval)");

  stmtins.bindin( 1, stsurfdata.obtid,5);
  stmtins.bindin( 2, stsurfdata.ddatetime,19);
  stmtins.bindin( 3,&stsurfdata.t);
  stmtins.bindin( 4,&stsurfdata.p);
  stmtins.bindin( 5,&stsurfdata.u);
  stmtins.bindin( 6,&stsurfdata.wd);
  stmtins.bindin( 7,&stsurfdata.wf);
  stmtins.bindin( 8,&stsurfdata.r);
  stmtins.bindin( 9,&stsurfdata.vis);

  while (true)
  {

    if (File.Fgets(strBuffer,300,true)==false) break;

//    logfile.Write("%s\n",strBuffer);
    
    CmdStr.SplitToCmd(strBuffer,",",true);
   
    if (CmdStr.CmdCount()!=9)//字段不对，这条数据丢弃
     {
       logfile.Write("%s\n",strBuffer); continue;
     }

    memset(&stsurfdata,0,sizeof(struct st_surfdata));
    
    CmdStr.GetValue(0,stsurfdata.obtid,5);      // 站点代码
    CmdStr.GetValue(1,stsurfdata.ddatetime,19); // 数据时间：格式yyyy-mm-dd hh:mi:ss。
    double dtmp=0;
    CmdStr.GetValue(2,&dtmp); stsurfdata.t=(int)(dtmp*10);  // 气温：单位，0.1摄氏度
    CmdStr.GetValue(3,&dtmp); stsurfdata.p=(int)(dtmp*10);  // 气压：0.1百帕
    CmdStr.GetValue(4,&stsurfdata.u);  // 相对湿度，0-100之间的值。
    CmdStr.GetValue(5,&stsurfdata.wd); // 风向，0-360之间的值。
    CmdStr.GetValue(6,&dtmp); stsurfdata.wf=(int)(dtmp*10);  // 风速：单位0.1m/s
    CmdStr.GetValue(7,&dtmp); stsurfdata.r=(int)(dtmp*10);   // 降雨量：0.1mm
    CmdStr.GetValue(8,&dtmp); stsurfdata.vis=(int)(dtmp*10); // 能见度：0.1米

    if(stmtsel.execute()!=0)
    {
         if((stmtsel.m_cda.rc>=3113)&&(stmtsel.m_cda.rc<=3115)) return false;
         logfile.Write("stmtsel.execute() failed.\n%s\n%s\n",stmtsel.m_sql,stmtsel.m_cda.message);continue;
    }
   
   // 从结果集中获取一条记录。
   // 如果执行的SQL语句是查询语句，调用execute方法后，会产生一个结果集（存放在数据库的缓冲区中）。
   // next方法从结果集中获取一条记录，把字段的值放入已绑定的输出变量中。
   // 返回值：0-成功，1403-结果集已无记录，其它-失败，失败的代码在m_cda.rc中，失败的描述在m_cda.message中。
   // 返回失败的原因主要有两个：1）与数据库的连接已断开；2）绑定输出变量的内存太小。
   // 每执行一次next方法，m_cda.rpc的值加1。
   // 程序员必须检查next方法的返回值。
    iccount=0;
   
    stmtsel.next();

    if(iccount>0) continue;

    // 执行SQL(插入)语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtins.execute() != 0) 
    {
       if (stmtins.m_cda.rc!=1)//1代表主键冲突，程序跳过重复数据，不会终止运行，只有非主键冲突的错误才会运行终止
       {
         if((stmtsel.m_cda.rc>=3113)&&(stmtsel.m_cda.rc<=3115)) return false;
         logfile.Write("%s\n",strBuffer);
         logfile.Write("stmtins.execute() failed.\n%s\n%s\n",stmtins.m_sql,stmtins.m_cda.message); 
       }
    }
  
  }

  // 提交事务
  conn.commit();

  // 关闭文件指针，并删除文件
  File.CloseAndRemove();

  return true;
}


