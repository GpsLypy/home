//上海天气APP软件服务端主程序。(多线程 改动后）

#include "_freecplus.h"
#include "_ooci.h"

// 业务请求数据结构
struct st_biz
{
  int    bizid;                 // 业务代码
  char   userid[51];            // 设备ID
  int    device;                // 用户的设备类型，0-未知；1-IOS；2-Andriod，3-鸿蒙。
  int    usertype;              // 用户分类，0-未知；1-普通用户；2-气象志愿者；3-内部用户。
  double lon;                   //经度
  double lat;                   //纬度
  double height;                //海拔高度
  char   obtid[11];             //站点代码
  char   xmlbuffer[1001];       //?    
};

void *pth_main(void *arg);


// 把xml解析到结构体stbiz中
void xmltobiz(char *strxmlbuffer,struct st_biz *stbiz);

CLogFile  logfile;  
CTcpServer TcpServer;

vector<int>  vclientfd;
vector<long> vpthid;

// 程序退出时调用的函数
void EXIT(int sig);

// 关闭客户端的socket并从vclientfd容器中删除，
void RemoveClient(int clientfd);

//心跳业务
bool biz10000(int clientfd);

// 新用户登录业务
bool biz10001(int clientfd,connection *conn,struct st_biz *stbiz);

// 获取天气实况
bool biz10002(struct st_biz *stbiz,connection *conn,int clientfd);

// 插入用户请求日志表
bool InsertUSERLOG(connection *conn,struct st_biz *stbiz);

void pthmainexit(void *arg);

int main(int argc,char *argv[])
{
  if (argc != 3)
  {
    printf("\n");
    printf("Using:/htidc/shtqapp/bin/shtqappserver1 logfilename port\n");

    printf("Example:/htidc/shtqapp/bin/shtqappserver1 /log/shtqapp/shtqappserver1.log 5015\n\n");
    printf("本程序是上海天气APP软件的服务端(多线程)。\n");
    printf("logfilename 日志文件名。\n");
    printf("port 用于传输文件的TCP端口。\n");

    return -1;
  }

  // 关闭全部的信号和输入输出
  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程
  // 但请不要用 "kill -9 +进程号" 强行终止
  CloseIOAndSignal(); signal(SIGINT,EXIT);

  // 打开程序运行日志，这是一个多线程程序，日志可以自动切换
  if (logfile.Open(argv[1],"a+",true) == false)
  {
    printf("logfile.Open(%s) failed.\n",argv[1]); return -1;
  }

  logfile.Write("shtqappserver started(%s).\n",argv[2]);

 // CTcpServer TcpServer;

  if (TcpServer.InitServer(atoi(argv[2])) == false)
  {
    logfile.Write("TcpServer.InitServer(%s) failed.\n",argv[2]); exit(-1);
  }
 
  vclientfd.push_back(TcpServer.m_listenfd);

  while (true)
  {
    // 等待客户端的连接
    if (TcpServer.Accept() == false)
    {
      logfile.Write("TcpServer.Accept() failed.\n"); continue;
    }

    // 当有新的客户端连接上来时,创建一线程，与新连接上来的客户端通信
    pthread_t pthid;   
    if (pthread_create(&pthid,NULL,pth_main,(void*)(long)TcpServer.m_connfd)!=0)
    { 
      logfile.Write("创建线程失败，程序退出。n"); close(TcpServer.m_connfd); EXIT(-1);
    }

    logfile.Write("%s is connected.\n",TcpServer.GetIP());	
	
    vpthid.push_back(pthid);
    vclientfd.push_back(TcpServer.m_connfd);
  }

  return 0;
}

void *pth_main(void *arg)
{
  // pthread_cleanup_push(pthmainexit,arg);// 设置线程清理函数(调用库函数）
   pthread_detach(pthread_self());  // 分离线程。在线程主函数中调用pthread_detach改变自己的状态，>避免僵尸线程
   //设置取消方式为立即取消。这是为了在收到信号主线程退出时，可以立即取消本子线程
  // pthread_setcanceltype(PTHREAD_CANCEL_DISABLE,NULL);
   int clientfd=(int)(long)arg;
   
   struct st_biz stbiz;
   connection conn;      //操作数据库的对象,注意定义在循环之外
   int ibuflen=0; 
   char strRecvBuffer[1024];
   
   while (true)
   {
    memset(strRecvBuffer,0,sizeof(strRecvBuffer));
    //memset(strSendBuffer,0,sizeof(strSendBuffer));//哪个函数内部使用，在内部初始化

    // 接收客户端的业务请求报文，如果返回false，认为是客户端退出或网络原因，不写错误日志
    if (TcpRead(clientfd,strRecvBuffer,&ibuflen,20)== false) ///
    {
      // logfile.Write("TcpRead() failed.\n"); 
      break;
    }

    logfile.Write("strRecvBuffer=%s\n",strRecvBuffer);  // xxxxxx

    // 把参数解析出来
    xmltobiz(strRecvBuffer,&stbiz);  /// 

    if (stbiz.bizid==10000)    // 心跳报文
    {
      if (biz10000(clientfd)==true) continue;
      else break;
    }

    CTimer Timer;

    if (conn.m_state==0)
    {
      // 连接数据库
      if (conn.connecttodb("shtqapp/pwdidc","Simplified Chinese_China.ZHS16GBK",true)!=0)
      {
        logfile.Write("conn.connettodb() failed.\n"); break;
      } 

      logfile.Write("conn=%lf\n",Timer.Elapsed());
    }
    // 新用户登录 
    if (stbiz.bizid==10001)    
    {
      if (biz10001(clientfd,&conn,&stbiz)==true) continue;
      else break;
    }

    // 获取天气实况
    if (stbiz.bizid==10002)    
    {
      if (biz10002(&stbiz,&conn,clientfd)==true) continue;
      else break;
    }

    // 体力活

    logfile.Write("非法报文%s\n",strRecvBuffer); break;
  }
 // pthread_cleanup_pop(1); 
  RemoveClient(clientfd);
  pthread_exit(0);

}

// 关闭客户端的socket并从vclientfd容器中删除，
void RemoveClient(int clientfd)
{
  for (int ii=0;ii<vclientfd.size();ii++)
  {
    if (vclientfd[ii]==clientfd) 
    { close(clientfd); vclientfd.erase(vclientfd.begin()+ii); return; }
  }
}


// 心跳业务
bool biz10000(int clientfd)
{
  char strSendBuffer[1024];
  memset(strSendBuffer,0,sizeof(strSendBuffer));
  strcpy(strSendBuffer,"ok");
  if (TcpWrite(clientfd,strSendBuffer) == false)
   {
    logfile.Write("2 TcpWrite() failed.\n"); return false;
   }
 
  return true;
}


// 新用户登录业务
bool biz10001(int clientfd,connection *conn,struct st_biz *stbiz)
{
  CTimer Timer;
  char strSendBuffer[1024];
  // 插入用户基本信息表T_USERINFO
  sqlstatement stmt(conn);

  stmt.prepare("insert into T_USERINFO(userid,downtime,usertype,device,keyid) values(:1,sysdate,:2,:3,SEQ_USERINFO.nextval)");
  stmt.bindin(1, stbiz->userid,50);
  stmt.bindin(2,&stbiz->device);
  stmt.bindin(3,&stbiz->usertype);
  if (stmt.execute() != 0)
  {
    if (stmt.m_cda.rc!=1)
    {
      logfile.Write("insert T_USERINFO failed.\n%s\n%s\n",stmt.m_cda.message,stmt.m_sql); return false;
    }
  }

  //logfile.Write("insert T_USERINFO =%lf\n",Timer.Elapsed());

  // 插入用户请求日志表
  if (InsertUSERLOG(conn,stbiz)==false) return false;

  //logfile.Write("insert T_USERLOG =%lf\n",Timer.Elapsed());

  char strobtid[6],strobtname[31],strlon[11],strlat[11];
  stmt.prepare("select obtid,obtname,lon,lat from T_OBTCODE where rsts=1 and rownum<=839");
  stmt.bindout(1,strobtid,5);
  stmt.bindout(2,strobtname,30);
  stmt.bindout(3,strlon,10);
  stmt.bindout(4,strlat,10);
  if (stmt.execute() != 0)
  {
    logfile.Write("select T_OBTCODE failed.\n%s\n%s\n",stmt.m_cda.message,stmt.m_sql); return false;
}

  while (true)
  {
    memset(strobtid,0,sizeof(strobtid)); 
    memset(strobtname,0,sizeof(strobtname));
    memset(strlon,0,sizeof(strlon)); 
    memset(strlat,0,sizeof(strlat));
    memset(strSendBuffer,0,sizeof(strSendBuffer));

    //如果执行的SQL语句是查询语句，调用execute方法后，会产生一个结果集（存放在数据库的缓冲区中）。
    // next方法从结果集中获取一条记录，把字段的值放入已绑定的输出变量中。
    if (stmt.next()!=0) break;

    sprintf(strSendBuffer,"<obtid>%s</obtid><obtname>%s</obtname><lon>%s</lon><lat>%s</lat><endl/>",strobtid,strobtname,strlon,strlat);

    if (TcpWrite(clientfd,strSendBuffer) == false)
    {
      logfile.Write("biz10001 TcpServer.Write() failed.\n"); return false;
    }
  }

  //logfile.Write("select =%lf\n",Timer.Elapsed());
  // 最后发送一个ok
  strcpy(strSendBuffer,"ok");
  if (TcpWrite(clientfd,strSendBuffer) == false)
  {
    logfile.Write("biz10001 TcpServer.Write() failed.\n"); return false;
  }

  return true;
}

// 获取天气实况
bool biz10002(struct st_biz *stbiz,connection *conn,int clientfd)
{
   return true;
}

// 插入用户请求日志表
bool InsertUSERLOG(connection *conn,struct st_biz *stbiz)//
{
  sqlstatement stmt(conn);
  stmt.prepare("insert into T_USERLOG(logid,userid,atime,bizid,obtid,lon,lat,height,xmlbuffer) values(SEQ_USERLOG.nextval,:1,sysdate,:2,:3,:4,:5,:6,:7)");
  stmt.bindin(1, stbiz->userid,50);
  stmt.bindin(2,&stbiz->bizid);
  stmt.bindin(3, stbiz->obtid,10);
  stmt.bindin(4,&stbiz->lon);
  stmt.bindin(5,&stbiz->lat);
  stmt.bindin(6,&stbiz->height);
  stmt.bindin(7, stbiz->xmlbuffer,10000);

  if (stmt.execute() != 0)
  {
    logfile.Write("insert T_USERLOG failed.\n%s\n%s\n",stmt.m_cda.message,stmt.m_sql); return false;

  }

  return true;
	
}

void pthmainexit(void *arg)
{
  logfile.Write("pthmainexit begin.\n");

  // 调用库函数close(int fd),关闭与客户端连接的socket(m_connfd)。
  close((int)(long)arg);

  // 从vpthid中删除本线程的id。
  for (int ii=0;ii<vpthid.size();ii++)
  {
    if (vpthid[ii]==pthread_self())//容器里的线程id等于本身线程id号
    {
      vpthid.erase(vpthid.begin()+ii);
    }
  }

  logfile.Write("pthmainexit end.\n");
}

void EXIT(int sig)
{
  if(sig>0)
  {
    signal(sig,SIG_IGN); signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);
    logfile.Write("catching the signal(%d).\n",sig);
  }
  
  // 关闭vclientfd容器中全部的socket
  for (int ii=0;ii<vclientfd.size();ii++)
  {
    close(vclientfd[ii]);
  }

  exit(0);
}

void xmltobiz(char *strxmlbuffer,struct st_biz *stbiz) //3种情况,多线程中，将结构体作为参数传递进来时，相当于复制了一个副本
{
  memset(stbiz,0,sizeof(struct st_biz));

  // 业务代码
  GetXMLBuffer(strxmlbuffer,"bizid",&stbiz->bizid);
  // logfile.Write("bizid=%d\n",stbiz->bizid);

  // 用户设备ID
  GetXMLBuffer(strxmlbuffer,"userid",stbiz->userid,50);
  // logfile.Write("userid=%s\n",stbiz->userid);
  
  GetXMLBuffer(strxmlbuffer,"usertype",&stbiz->usertype);
 

  GetXMLBuffer(strxmlbuffer,"obtid",stbiz->obtid,10);
  // logfile.Write("obtid=%s\n",stbiz->obtid);

  GetXMLBuffer(strxmlbuffer,"lat",&stbiz->lat);
  // logfile.Write("lat=%lf\n",stbiz->lat);

  GetXMLBuffer(strxmlbuffer,"lon",&stbiz->lon);
  // logfile.Write("lon=%lf\n",stbiz->lon);

  GetXMLBuffer(strxmlbuffer,"height",&stbiz->height);
  // logfile.Write("height=%lf\n",stbiz->height);

  strncpy(stbiz->xmlbuffer,strxmlbuffer,1000);

  return;
  
}



