/*本程序是数据中心的公共功能模块，从数据库的表中导出数据生成xml文件，用于数据交换*/
#include "_public.h"
#include "_ooci.h"


// 主程序的参数,由于主程序的参数传进来的是xml格式，需要对其进行解析，所以定义一个结构体用来存放解析之后的参数
struct st_arg
{
  char connstr[101];//数据库的连接参数
  char charset[51]; //数据库的字符集
  char tname[51];   //待导出数据的表名
  char cols[1001];  //需要导出字段的列表
  char fieldname[1001]; //导出字段的别名列表
  char fieldlen[501];   //导出字段的长度列表
  int  exptype;         //导出数据的方式
  char andstr[501];     //导出数据的附加条件
  char bname[51];       //导出文件的命名的前部分
  char ename[51];       //导出文件的命名的后部分
  char taskname[51];    //导出任务的命名
  char exppath[301];    //导出文件存放的目录
  int  timetvl;         // 导出数据的时间间隔
} starg;

// 显示程序的帮助
void _help(char *argv[]);

// 把xml解析到参数starg结构中
bool _xmltoarg(char *strxmlbuffer);

// 拆分fieldname和fieldlen
void SplitFields();

vector<string> vfieldname; // 存放拆分fieldname内容的容器
vector<int>    vfieldlen;  // 存放拆分fieldlen内容的容器

int maxfieldlen;           // 存放fieldlen的最大值

void EXIT(int sig);//处理函数退出函数

CLogFile logfile;//日志文件操作类，实例化对象

connection conn;//oracle数据库连接池类

// 本程序的业务流程主函数
bool _exptables();

long maxkeyid;   // 已导出数据的最大的keyid
bool LoadMaxKeyid(); // 从系统参数T_SYSARG表中加载已导出数据的最大的keyid
bool UptMaxKeyid();  // 更新系统参数T_SYSARG表中已导出数据的最大的keyid

int main(int argc,char *argv[])
{
  if(argc!=3){_help(argv);return -1;}
  
  CloseIOAndSignal();//关闭全部的信号和输入输出 
  
  signal(SIGINT,EXIT);signal(SIGTERM,EXIT);//处理程序退出的信号

  if( (logfile.Open(argv[1],"a+"))==false ) {printf("打开日志文件失败(%s)\n",argv[1]);return -1;}

  if((_xmltoarg(argv[2]))==false) return -1; // 把xml格式字符串解析到参数starg结构中

  while(true)
  {
     // 连接数据库
     if (conn.connecttodb(starg.connstr,starg.charset) != 0)
     {
       logfile.Write("connect database %s failed.\n",starg.connstr); sleep(starg.timetvl); continue;
     }
   
     logfile.Write("准备导出表%s...\n",starg.tname);  
   
     if( (_exptables())==false ) logfile.Write("导出失败!\n");
  
     logfile.Write("导出成功!");
     
     conn.disconnect();//断开与数据库的连接
      
     sleep(starg.timetvl);//睡眠一段时间，等待表更新数据后，重新连接数据库导表

  }

  return 0;

}

void EXIT(int sig)
{
  logfile.Write("程序退出，sig=%d\n\n",sig);

  exit(0);
}

// 显示程序的帮助
void _help(char *argv[])
{
  printf("\n");
  printf("Using:/htidc/public/bin/exptables logfilename xmlbuffer\n\n");

  printf("增量导出示例：\n");
  printf("/htidc/public/bin/exptables /log/shqx/exptables_surfdata_for_hb.log \"<connstr>shqx/pwdidc@snorcl11g_192.168.65.128</connstr><charset>Simplified Chinese_China.ZHS16GBK</charset><tname>T_SURFDATA</tname><cols>obtid,to_char(ddatetime,'yyyymmddhh24miss'),t,p,u,wd,wf,r,vis</cols><fieldname>obtid,ddatetime,t,p,u,wd,wf,r,vis</fieldname><fieldlen>5,14,8,8,8,8,8,8,8</fieldlen><exptype>1</exptype><andstr> and obtid in ('54406','54511')</andstr><bname>SURFDATA_</bname><ename>_for_hb</ename><taskname>SURFDATA_FOR_HB</taskname><exppath>/data/shqx/exp/tohb</exppath><timetvl>30</timetvl>\"\n\n");
  printf("全量导出示例：\n");
  printf("/htidc/public/bin/exptables /log/shqx/exptables_obtcode_for_hb.log \"<connstr>shqx/pwdidc@snorcl11g_192.168.65.128</connstr><charset>Simplified Chinese_China.ZHS16GBK</charset><tname>T_OBTCODE</tname><cols>obtid,obtname,provname,lat,lon,height</cols><fieldname>obtid,obtname,provname,lat,lon,height</fieldname><fieldlen>5,30,30,8,8,8</fieldlen><exptype>2</exptype><andstr> and rsts=1 and obtid in ('54406','54511')</andstr><bname>OBTCODE_</bname><ename>_for_hb</ename><exppath>/data/shqx/exp/tohb</exppath><timetvl>300</timetvl>\"\n\n");

  printf("本程序是数据中心的公共功能模块，从数据库的表中导出数据生成xml文件，用于数据交换。\n");
  printf("logfilename是本程序运行的日志文件。\n");
  printf("xmlbuffer为文件传输的参数，如下：\n");
  printf("数据库的连接参数 <connstr>shqx/pwdidc@snorcl11g_198</connstr>\n");
  printf("数据库的字符集 <charset>Simplified Chinese_China.ZHS16GBK</charset> 这个参数要与数据源数据库保持>一致，否则会出现中文乱码的情况。\n");
  printf("待导出数据的表名 <tname>T_SURFDATA</tname>\n");
  printf("需要导出字段的列表 <cols>obtid,to_char(ddatetime,'yyyymmddhh24miss'),t,p,u,wd,wf,r,vis</cols> 可以采用函数。\n");
  printf("导出字段的别名列表 <fieldname>obtid,ddatetime,t,p,u,wd,wf,r,vis</fieldname> 必须与cols一一对应。\n");
  printf("导出字段的长度列表 <fieldlen>5,14,8,8,8,8,8,8,8</fieldlen> 必须与cols一一对应。\n");
  printf("导出数据的方式 <exptype>1</exptype> 1-增量导出；2-全量导出，如果是增量导出，要求表一定要有keyid字段。\n");
  printf("导出数据的附加条件 <andstr> and obtid in ('59293','50745')</andstr> 注意，关键字and不能少。\n");
  printf("导出文件的命名的前部分 <bname>SURFDATA_</bname>\n");
  printf("导出文件的命名的后部分 <ename>_for_hb</ename>\n");
  printf("导出任务的命名 <taskname>SURFDATA_FOR_HB</taskname> 当exptype=1时该参数有效。\n");
  printf("导出文件存放的目录 <exppath>/data/shqx/exp/tohb</exppath>\n");
  printf("导出数据的时间间隔 <timetvl>30</timetvl> 单位：秒，建议大于10。\n");
  printf("以上参数，除了taskname和andstr，其它字段都不允许为空。\n\n\n");
}

// 把xml解析到参数starg结构中***
bool _xmltoarg(char *strxmlbuffer)
{
  memset(&starg,0,sizeof(struct st_arg));
  /*
  xmlbuffer：待解析的xml格式字符串的内容。
  fieldname：字段的标签名。
  value：传入变量的地址，
  */
  GetXMLBuffer(strxmlbuffer,"connstr",starg.connstr);
  if (strlen(starg.connstr)==0) { logfile.Write("connstr is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"charset",starg.charset);
  if (strlen(starg.charset)==0) { logfile.Write("charset is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"tname",starg.tname);
  if (strlen(starg.tname)==0) { logfile.Write("tname is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"cols",starg.cols);
  if (strlen(starg.cols)==0) { logfile.Write("cols is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"fieldname",starg.fieldname);
  if (strlen(starg.fieldname)==0) { logfile.Write("fieldname is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"fieldlen",starg.fieldlen);
  if (strlen(starg.fieldlen)==0) { logfile.Write("fieldlen is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"exptype",&starg.exptype);
  if ( (starg.exptype!=1) && (starg.exptype!=2) ) { logfile.Write("exptype is not in (1,2).\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"andstr",starg.andstr);
  if (strlen(starg.andstr)==0) { logfile.Write("andstr is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"bname",starg.bname);
  if (strlen(starg.bname)==0) { logfile.Write("bname is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"ename",starg.ename);
  if (strlen(starg.ename)==0) { logfile.Write("ename is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"taskname",starg.taskname);
  if ( (starg.exptype==1) && (strlen(starg.taskname)==0) ) { logfile.Write("taskname is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"exppath",starg.exppath);
  if (strlen(starg.exppath)==0) { logfile.Write("exppath is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"timetvl",&starg.timetvl);
  if (starg.timetvl==0) { logfile.Write("timetvl is null.\n"); return false; }

  // 拆分fieldname和fieldlen,有嵌套需要拆分
  SplitFields();

  // 判断fieldname和fieldlen中元素的个数一定要相同
  if (vfieldname.size() != vfieldlen.size() ) { logfile.Write("fieldname和fieldlen的元素个数不同。.\n"); return false; }

  return true;
}

// 拆分fieldname和fieldlen到容器中***
void SplitFields()
{
  vfieldname.clear(); vfieldlen.clear(); maxfieldlen=0;
  
  CCmdStr CmdStr;//CCmdStr类用于拆分用分隔符分隔字段内容的字符串
  CmdStr.SplitToCmd(starg.fieldname,",");//把字符串拆分到m_vCmdStr容器中。
  vfieldname.swap(CmdStr.m_vCmdStr);//交换两个容器内所有元素

  int ifieldlen=0;
  CmdStr.SplitToCmd(starg.fieldlen,",");
  for (int ii=0;ii<CmdStr.CmdCount();ii++)//CmdCount()获取拆分后字段的个数，即m_vCmdStr容器的大小
  {  
    CmdStr.GetValue(ii,&ifieldlen);
    if (ifieldlen>maxfieldlen) maxfieldlen=ifieldlen;   // 得到fieldlen的最大值
    vfieldlen.push_back(ifieldlen);
  }
}


// 本程序的业务流程主函数
bool _exptables()
{
   // 从系统参数T_SYSARG表中加载已导出数据的最大的keyid
  if (LoadMaxKeyid()==false) { logfile.Write("LoadMaxKeyid() failed.\n"); return false; }

  //生成导出数据的SQL语句
  char strsql[4096];
  char fieldvalue[vfieldname.size()][maxfieldlen+1]; // 输出变量定义为一个二维数组
  memset(strsql,0,sizeof(strsql));
 
  if (starg.exptype==1)//增量导出
    sprintf(strsql,"select %s,keyid from %s where 1=1 and keyid>%ld %s order by keyid",starg.cols,starg.tname,maxkeyid,starg.andstr);
  else //全量导出
    sprintf(strsql,"select %s from %s where 1=1 %s",starg.cols,starg.tname,starg.andstr);

  sqlstatement stmt(&conn);
  stmt.prepare(strsql);

  for (int ii=0;ii<vfieldname.size();ii++)//待查询的字段有几个，就绑定几个输出变量，增量输出和全量输出公用部分
  {
    stmt.bindout(ii+1,fieldvalue[ii],vfieldlen[ii]);
  }
 
  // 如果是增量导出，还要绑定keyid字段
  if (starg.exptype==1) stmt.bindout(vfieldname.size()+1,&maxkeyid);
  
  // 执行导出数据的SQL，调用execute方法后，会产生一个结果集（存放在数据库的缓冲区中）。
  if (stmt.execute() != 0)
  {
    logfile.Write("select %s failed.\n%s\n%s\n",starg.tname,stmt.m_cda.message,stmt.m_sql); return false;
  } 
 
  CFile File;
  char strFileName[301],strLocalTime[21];
  int  iFileSeq=1;   // 待生成文件的序号

  while(true)
  {
    memset(fieldvalue,0,sizeof(fieldvalue));//初始化数组，准备接收数据
    if (stmt.next() !=0) break;//执行next()方法，获取缓冲区的第一条记录，存放在绑定的输出变量中
    
    if (File.IsOpened()==false)// 判断文件是否已打开
     {
       memset(strFileName,0,sizeof(strFileName));
       memset(strLocalTime,0,sizeof(strLocalTime));
       LocalTime(strLocalTime,"yyyymmddhh24miss");
      
       sprintf(strFileName,"%s/%s%s%s_%d.xml",starg.exppath,starg.bname,strLocalTime,starg.ename,iFileSeq++);
  
       if (File.OpenForRename(strFileName,"w")==false)//创建并打开一个临时文件，避免中间状态的文件被读取
        {
          logfile.Write("File.OpenForRename(%s) failed.\n",strFileName); return false;
        }
       File.Fprintf("<data>\n");//由于生成的是xml文件，所以加上固定标识符       
     }

    for (int ii=0;ii<vfieldname.size();ii++)
     {
       File.Fprintf("<%s>%s</%s>",vfieldname[ii].c_str(),fieldvalue[ii],vfieldname[ii].c_str());
     }
    File.Fprintf("<endl/>\n");

    // 1000条记录写入一个文件完成，每执行一次next方法，m_cda.rpc的值加1。说明文件被写入了一行
    if (stmt.m_cda.rpc%1000==0)
    {
      File.Fprintf("</data>\n");//写上文件结束表示符，文件即将关闭
      if (File.CloseAndRename()==false)
      {
        logfile.Write("File.CloseAndRename(%s) failed.\n",strFileName); return false;
      }

      // 更新系统参数T_SYSARG表中已导出数据的最大的keyid
      if (UptMaxKeyid()==false) { logfile.Write("UptMaxKeyid() failed.\n"); return false; }

      logfile.Write("create file %s ok.\n",strFileName);
    } 
  }

  // 不够1000条的写入一个文件
  if (File.IsOpened()==true)
  {
    File.Fprintf("</data>\n");
    if (File.CloseAndRename()==false)
    {
      logfile.Write("File.CloseAndRename(%s) failed.\n",strFileName); return false;
    }

    // 更新系统参数T_SYSARG表中已导出数据的最大的keyid
    if (UptMaxKeyid()==false) { logfile.Write("UptMaxKeyid() failed.\n"); return false; }

    logfile.Write("create file %s ok.\n",strFileName);
  }

  if (stmt.m_cda.rpc>0) logfile.Write("本次导出了%d条记录。\n",stmt.m_cda.rpc);

  return true;


}

// 从系统参数T_SYSARG表中加载已导出数据的最大的keyid,用于增量输出控制。
bool LoadMaxKeyid()
{
 if (starg.exptype!=1) return true;//全量输出，返回true
 
 sqlstatement stmt(&conn);//创建操作SQL语句的对象，传递的参数传给了带参数的构造函数，完成了绑定数据库连接池的功能
 
 stmt.prepare("select argvalue from T_SYSARG where argcode=:1");
 stmt.bindin(1,starg.taskname,50);
 stmt.bindout(1,&maxkeyid);
 if(stmt.execute()!=0)
  {
   logfile.Write("select T_SYSARG failed.\n%s\n%s\n",stmt.m_cda.message,stmt.m_sql); return false;
  }

  //如果记录不存在说明还未进行过数据的导入，就插入一条新记录,
  //如果执行的SQL语句是查询语句，调用execute方法后，会产生一个结果集（存放在数据库的缓冲区中）。
  // next方法从结果集中获取一条记录，把字段的值放入已绑定的输出变量中。
 if(stmt.next()!=0)
  {
    stmt.prepare("insert into T_SYSARG(argcode,argname,argvalue) values(:1,:2,0)");
    stmt.bindin(1,starg.taskname,50);
    stmt.bindin(2,starg.taskname,50);
    stmt.execute();
    conn.commit();
  }

 logfile.Write("maxkeyid=%d\n",maxkeyid);
 
 return true;
}


// 更新系统参数T_SYSARG表中已导出数据的最大的keyid
bool UptMaxKeyid()
{
  if (starg.exptype!=1) return true;

  sqlstatement stmt(&conn);
  stmt.prepare("update T_SYSARG set argvalue=:1 where argcode=:2");//将符合条件的代码指定的value值修改为1
  stmt.bindin(1,&maxkeyid);
  stmt.bindin(2,starg.taskname,50); 
  if (stmt.execute() != 0)
  {
    logfile.Write("select T_SYSARG failed.\n%s\n%s\n",stmt.m_cda.message,stmt.m_sql); return false;
  }

  conn.commit();

  return true;
}
















