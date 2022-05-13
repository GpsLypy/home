#include "_freecplus.h"


struct st_arg
{
  char ip[31];              // 服务器端的IP地址。
  int  port;                // 服务器端的端口。
  int  ptype;               // 文件发送成功后文件的处理方式：1-保留文件；2-移动到备份目录；3-删除文件。
  char clientpath[301];     // 本地文件存放的根目录。
  char clientpathbak[301];  // 文件成功发送后，本地文件备份的根目录，当ptype==2时有效。
  char srvpath[301];        // 服务端文件存放的根目录。
  char srvpathbak[301];     // 文件成功接收后，服务端文件备份的根目录，当ptype==2时有效。
  bool andchild;            // 是否发送clientpath目录下各级子目录的文件，true-是；false-否。
  char matchname[301];      // 待发送文件名的匹配方式，如"*.TXT,*.XML"，注意用大写。
  char okfilename[301];     // 已发送成功文件名清单。
  int  timetvl;             // 扫描本地目录文件的时间间隔，单位：秒。
  int  clienttype;          //多线程里把业务代码添加到结构体xxx
 } starg;

// 把xml解析到参数starg结构中xxx
bool _xmltoarg(char *strxmlbuffer,struct st_arg *starg);

CLogFile logfile;

//存放客户端已连接的socket的容器
vector<int> vclientfd;

// 存放线程id的容器。xxx
vector<long> vpthid;

//把客户端新的socket加入vclientfd
//void AddClient(int clientfd);

// 与客户端通信线程的主函数xxx
void *pth_main(void *arg);

//关闭客户端的socket并从vclientfd容器中删除xxx
void RemoveClient(int clientfd);

// 等待登录xxx
bool ClientLogin(int clientfd,struct st_arg *starg);

// 列出srvpath目录下文件的清单，返回给客户端。xxx
bool ListFile(int clientfd,struct st_arg *starg);

void pthmainexit(void *arg);

void EXIT(int sig);

// 接收文件主函数xxx
bool RecvFilesMain(int clientfd,struct st_arg *starg);

// 发送文件主函数xxx
bool SendFilesMain(int clientfd,struct st_arg *starg);

int main(int argc,char *argv[])
{
  if (argc != 3)
  {
    printf("\n");
    printf("Using:/htidc/public/bin/tcpfileserver logfilename port\n");

    printf("Example:/htidc/public/bin/tcpfileserver1 /tmp/tcpfileserver1.log 5006\n\n");
    printf("本程序是一个公共功能模块，采用TCP/IP传输文件的服务端。\n");
    printf("logfilename 日志文件名。\n");
	    printf("port 用于传输文件的TCP端口。\n");

    return -1;
  }

  // 关闭全部的信号和输入输出
  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程
  // 但请不要用 "kill -9 +进程号" 强行终止
  CloseIOAndSignal();signal(SIGINT,EXIT); signal(SIGTERM,EXIT);//xxx

  // 打开程序运行日志
  if (logfile.Open(argv[1],"a+",false) == false)
  {
    printf("logfile.Open(%s) failed.\n",argv[1]); return -1;
  }
   logfile.Write("fileserver started(%s).\n",argv[2]);
  
  //1、实例化一局部类对象
  CTcpServer TcpServer;

  if (TcpServer.InitServer(atoi(argv[2])) == false)
  {
    logfile.Write("TcpServer.InitServer(%s) failed.\n",argv[2]); exit(-1);
  }
   //2、保存服务端的listenfd到vclientfd
  vclientfd.push_back(TcpServer.m_listenfd);

  while (true)
  {
    // 等待客户端的连接
    if (TcpServer.Accept() == false)
    {
      logfile.Write("TcpServer.Accept() failed.\n"); continue;
    }

    //3、创建一线程，与新连接上来的客户端通信
    pthread_t pthid;
    if(pthread_create(&pthid,NULL,pth_main,(void*)(long)TcpServer.m_connfd)!=0){
	     logfile.Write("创建线程失败，程序退出\n");close(TcpServer.m_connfd);EXIT(-1);
	  }
	//4、写日志
	logfile.Write("%s is connection.\n",TcpServer.GetIP());
	//5、保存每个客户端的socket到vclientfd
    vclientfd.push_back(TcpServer.m_connfd);
	// 把线程id保存到vpthid容器中。
	vpthid.push_back(pthid);
  }

  return 0;
}

void EXIT(int sig)
{
  if(sig>0) {signal(sig,SIG_IGN);signal(SIGINT,SIG_IGN);signal(SIGTERM,SIG_IGN);}
  logfile.Write("tcpfileserver1 exit,sig=%d...\n",sig);
  
  //关闭vclientfd容器中全部socket
  for(int ii=0;ii<vclientfd.size();ii++)
  {
	close(vclientfd[ii]);
  }
  exit(0);
}

// 与客户端通信线程的主函数
void *pth_main(void *arg)
{
  pthread_cleanup_push(pthmainexit,arg);// 设置线程清理函数(调用库函数）
  pthread_detach(pthread_self());  // 分离线程。在线程主函数中调用pthread_detach改变自己的状态，>避免僵尸线程
    //设置取消方式为立即取消。这是为了在收到信号主线程退出时，可以立即取消本子线程
  pthread_setcanceltype(PTHREAD_CANCEL_DISABLE,NULL);

  //int clientfd=(int)(long)arg;//
  int clientfd=(long)arg;
    //6、声明一结构体变量starg
  struct st_arg starg;
  memset(&starg,0,sizeof(struct st_arg));
  
  //789函数中要把clientfd,&starg作为参数传进去，这就是多线程和多进程程序的差别
    //7、等待客户端的登录     
  if (ClientLogin(clientfd,&starg) == false) {RemoveClient(clientfd);pthread_exit(0);}

    //8、接收文件主函数
  if (starg.clienttype==1)
  {
   if(RecvFilesMain(clientfd,&starg)==false) {RemoveClient(clientfd);pthread_exit(0);}
  }
    //9、发送文件主函数
  if (starg.clienttype==2) 
  {
   if(SendFilesMain(clientfd,&starg)==false) {RemoveClient(clientfd);pthread_exit(0);}
  }
  RemoveClient(clientfd); 
  pthread_cleanup_pop(1);
  pthread_exit(0);

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



//关闭客户端的socket并从vclientfd容器中删除
void RemoveClient(int clientfd)
{
  //先在容器中找到这个fd，然后关闭它并在容器中删除记录
  for(int ii=0;ii<vclientfd.size();ii++)
   {
    if(vclientfd[ii]==clientfd) {close(clientfd);vclientfd.erase(vclientfd.begin()+ii);return;}	 
   }
}

// 等待登录,在多线程程序中，不能用TcpServer类里面的read和write函数
bool ClientLogin(int clientfd,struct st_arg *starg)
{
  int ibuflen=0;
  char username[10],password[10];
  char strRecvBuffer[1024]; // 接收报文的缓冲区
  char strSendBuffer[1024]; // 发送报文的缓冲

  memset(username,0,sizeof(username));
  memset(password,0,sizeof(password));
  memset(strRecvBuffer,0,sizeof(strRecvBuffer));
  memset(strSendBuffer,0,sizeof(strSendBuffer));

  if (TcpRead(clientfd,strRecvBuffer,&ibuflen,20) == false)
  {
    logfile.Write("1 TcpServer.Read() failed.\n"); return false;
  }
   logfile.Write("1 strRecvBuffer=%s\n",strRecvBuffer);  // xxxxxx

   GetXMLBuffer(strRecvBuffer,"clienttype",&starg->clienttype);//因为传进来的是结构体指针，访问结构体内的成员时，用->
   GetXMLBuffer(strRecvBuffer,"username",username);
   GetXMLBuffer(strRecvBuffer,"password",password);

   if ( ( (starg->clienttype==1) || (starg->clienttype==2) )&&((strcmp(username,"li")==0)&&(strcmp(password,"1234")==0)) )
  //if ( (starg->clienttype==1) || (starg->clienttype==2) )
    strcpy(strSendBuffer,"ok");
  else
    strcpy(strSendBuffer,"failed");

   logfile.Write("1 strSendBuffer=%s\n",strSendBuffer);  // xxxxxx
   
   if (TcpWrite(clientfd,strSendBuffer) == false)
  {
    logfile.Write("1 TcpServer.Write() failed.\n"); return false;
  }

  logfile.Write("login %s(clienttype=%d)\n",strSendBuffer,starg->clienttype);

  if (strcmp(strSendBuffer,"failed") == 0) return false;

  // 把参数解析出来
  _xmltoarg(strRecvBuffer,starg);//

  return true;
}
// 接收文件主函数
bool RecvFilesMain(int clientfd,struct st_arg *starg)
{
  int ibuflen=0;
  char strRecvBuffer[1024]; // 接收报文的缓冲区
  char strSendBuffer[1024]; // 发送报文的缓冲
  while (true)
  {
    memset(strRecvBuffer,0,sizeof(strRecvBuffer));
    memset(strSendBuffer,0,sizeof(strSendBuffer));

    if (TcpRead(clientfd,strRecvBuffer,&ibuflen,80) == false)
    {
      logfile.Write("2 TcpServer.Read() failed.\n");return false;
    }
     logfile.Write("2 strRecvBuffer=%s\n",strRecvBuffer);  // xxxxxx
	   // 处理心跳报文
    if (strstr(strRecvBuffer,"activetest")!=0)
    {
      strcpy(strSendBuffer,"ok");
       logfile.Write("2 strSendBuffer=%s\n",strSendBuffer);  // xxxxxx
      if (TcpWrite(clientfd,strSendBuffer) == false)
      {
        logfile.Write("2 TcpServer.Write() failed.\n");
      }

      continue;
    }

    struct st_fileinfo stfileinfo;
    memset(&stfileinfo,0,sizeof(struct st_fileinfo));

    // 获取待接收的文件的时间和大小
    GetXMLBuffer(strRecvBuffer,"filename",stfileinfo.filename);
	 GetXMLBuffer(strRecvBuffer,"filesize",&stfileinfo.filesize);
    GetXMLBuffer(strRecvBuffer,"mtime",stfileinfo.mtime);

    // 把文件名中的clientpath替换成srvpath，要小心第三个参数
    UpdateStr(stfileinfo.filename,starg->clientpath,starg->srvpath,false);

    // 接收文件的内容
    if(RecvFile(clientfd,&stfileinfo,&logfile)==false)
    {
      logfile.Write("RecvFile() failed.\n");
    }

    logfile.Write("recv %s ok.\n",stfileinfo.filename);
  }
  return true;
}
  // 发送文件主函数
bool SendFilesMain(int clientfd,struct st_arg *starg)
{
  int ibuflen=0;
  char strRecvBuffer[1024]; // 接收报文的缓冲区
  char strSendBuffer[1024]; // 发送报文的缓冲

  while (true)
  {
    memset(strRecvBuffer,0,sizeof(strRecvBuffer));
    if (TcpRead(clientfd,strRecvBuffer,&ibuflen,80) == false)
     {
      logfile.Write("3 TcpServer.Read() failed.\n");
     }
    // logfile.Write("3 strRecvBuffer=%s\n",strRecvBuffer);  // xxxxxx

    // 处理心跳报文
    if (strstr(strRecvBuffer,"activetest")!=0)
     {
	  memset(strSendBuffer,0,sizeof(strSendBuffer));
      strcpy(strSendBuffer,"ok");
      // logfile.Write("3 strSendBuffer=%s\n",strSendBuffer);  // xxxxxx
      if (TcpWrite(clientfd,strSendBuffer) == false)
       {
        logfile.Write("3 TcpServer.Write() failed.\n");
       }

      continue;
     }

    // 处理获取文件列表报文
    if (strcmp(strRecvBuffer,"<list>")==0)
    {
       if (ListFile(clientfd,starg)==false)
      {
        logfile.Write("ListFile() failed.\n");
		 }

      continue;
    }

    // 取文件报文
    if (strncmp(strRecvBuffer,"<filename>",10)==0)
    {
      // 获取待接收的文件的时间和大小
      struct st_fileinfo stfileinfo;
      memset(&stfileinfo,0,sizeof(struct st_fileinfo));
      GetXMLBuffer(strRecvBuffer,"filename",stfileinfo.filename);
      GetXMLBuffer(strRecvBuffer,"filesize",&stfileinfo.filesize);
      GetXMLBuffer(strRecvBuffer,"mtime",stfileinfo.mtime);

      // 把文件发送给客户端
      //if (SendFile(&logfile,TcpServer.m_connfd,&stfileinfo)==false) ChldEXIT(-1);
      if (SendFile(clientfd,&stfileinfo,&logfile)==false) return false;
	  logfile.Write("put %s ...ok.\n",stfileinfo.filename);

      // 删除服务端的文件
      if (starg->ptype==2) REMOVE(stfileinfo.filename);

      // 备份服务端的文件
      if (starg->ptype==3)
      {
        char strfilenamebak[301];
        memset(strfilenamebak,0,sizeof(strfilenamebak));
        strcpy(strfilenamebak,stfileinfo.filename);
        UpdateStr(strfilenamebak,starg->srvpath,starg->srvpathbak,false);  // 要`小心第三个参数
        if (RENAME(stfileinfo.filename,strfilenamebak)==false)
        {
          logfile.Write("RENAME %s to %s failed.\n",stfileinfo.filename,strfilenamebak);
        }
      }
    }
  }
  return true;
}

// 把xml解析到参数starg结构中
bool _xmltoarg(char *strxmlbuffer,struct st_arg *starg)
{
  //memset(starg,0,sizeof(struct st_arg));
  GetXMLBuffer(strxmlbuffer,"ip",starg->ip);
  GetXMLBuffer(strxmlbuffer,"port",&starg->port);
  GetXMLBuffer(strxmlbuffer,"ptype",&starg->ptype);
  GetXMLBuffer(strxmlbuffer,"clientpath",starg->clientpath);
  GetXMLBuffer(strxmlbuffer,"clientpathbak",starg->clientpathbak);
  GetXMLBuffer(strxmlbuffer,"srvpath",starg->srvpath);
  GetXMLBuffer(strxmlbuffer,"srvpathbak",starg->srvpathbak);
  GetXMLBuffer(strxmlbuffer,"andchild",&starg->andchild);
  GetXMLBuffer(strxmlbuffer,"matchname",starg->matchname);
  GetXMLBuffer(strxmlbuffer,"okfilename",starg->okfilename);
  GetXMLBuffer(strxmlbuffer,"timetvl",&starg->timetvl);

  return true;
}

// 列出srvpath目录下文件的清单，返回给客户端。
bool ListFile(int clientfd,struct st_arg *starg)
{
  CDir Dir;
  int  ibuflen=0;
  char strRecvBuffer[1024]; // 接收报文的缓冲区
  char strSendBuffer[1024]; // 发送报文的缓冲
   // 注意，如果目录下的总文件数超过50000，增量发送文件功能将有问题
  if (Dir.OpenDir(starg->srvpath,starg->matchname,50000,starg->andchild,false)==false)
  {
    logfile.Write("Dir.OpenDir(%s) 失败。\n",starg->srvpath); return false;
  }

  // 先把文件总数返回给客户端
  memset(strSendBuffer,0,sizeof(strSendBuffer));
  sprintf(strSendBuffer,"<totalfile>%d</totalfile>",Dir.m_vFileName.size());
  // logfile.Write("4 strSendBuffer=%s\n",strSendBuffer);  // xxxxxx
   if (TcpWrite(clientfd,strSendBuffer) == false)
  {
    logfile.Write("4 TcpServer.Write() failed.\n"); return false;
  }
  
   // 把文件信息一条条的返回给客户端
  while (true)
  {
    if (Dir.ReadDir()==false) break;

    memset(strSendBuffer,0,sizeof(strSendBuffer));
    sprintf(strSendBuffer,"<filename>%s</filename><mtime>%s</mtime><filesize>%d</filesize>",Dir.m_FullFileName,Dir.m_ModifyTime,Dir.m_FileSize);
    // logfile.Write("5 strSendBuffer=%s\n",strSendBuffer);  // xxxxxx
     if (TcpWrite(clientfd,strSendBuffer) == false)
    {
      logfile.Write("5 TcpServer.Write() failed.\n"); return false;
    }
  }

  return true;
}

 
