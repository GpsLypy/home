//�Ϻ�����APP��������������(���߳� �Ķ���

#include "_freecplus.h"
#include "_ooci.h"

// ҵ���������ݽṹ
struct st_biz
{
  int    bizid;                 // ҵ�����
  char   userid[51];            // �豸ID
  int    device;                // �û����豸���ͣ�0-δ֪��1-IOS��2-Andriod��3-���ɡ�
  int    usertype;              // �û����࣬0-δ֪��1-��ͨ�û���2-����־Ը�ߣ�3-�ڲ��û���
  double lon;                   //����
  double lat;                   //γ��
  double height;                //���θ߶�
  char   obtid[11];             //վ�����
  char   xmlbuffer[1001];       //?    
};

void *pth_main(void *arg);


// ��xml�������ṹ��stbiz��
void xmltobiz(char *strxmlbuffer,struct st_biz *stbiz);

CLogFile  logfile;  
CTcpServer TcpServer;

vector<int>  vclientfd;
vector<long> vpthid;

// �����˳�ʱ���õĺ���
void EXIT(int sig);

// �رտͻ��˵�socket����vclientfd������ɾ����
void RemoveClient(int clientfd);

//����ҵ��
bool biz10000(int clientfd);

// ���û���¼ҵ��
bool biz10001(int clientfd,connection *conn,struct st_biz *stbiz);

// ��ȡ����ʵ��
bool biz10002(struct st_biz *stbiz,connection *conn,int clientfd);

// �����û�������־��
bool InsertUSERLOG(connection *conn,struct st_biz *stbiz);

void pthmainexit(void *arg);

int main(int argc,char *argv[])
{
  if (argc != 3)
  {
    printf("\n");
    printf("Using:/htidc/shtqapp/bin/shtqappserver1 logfilename port\n");

    printf("Example:/htidc/shtqapp/bin/shtqappserver1 /log/shtqapp/shtqappserver1.log 5015\n\n");
    printf("���������Ϻ�����APP����ķ����(���߳�)��\n");
    printf("logfilename ��־�ļ�����\n");
    printf("port ���ڴ����ļ���TCP�˿ڡ�\n");

    return -1;
  }

  // �ر�ȫ�����źź��������
  // �����ź�,��shell״̬�¿��� "kill + ���̺�" ������ֹЩ����
  // ���벻Ҫ�� "kill -9 +���̺�" ǿ����ֹ
  CloseIOAndSignal(); signal(SIGINT,EXIT);

  // �򿪳���������־������һ�����̳߳�����־�����Զ��л�
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
    // �ȴ��ͻ��˵�����
    if (TcpServer.Accept() == false)
    {
      logfile.Write("TcpServer.Accept() failed.\n"); continue;
    }

    // �����µĿͻ�����������ʱ,����һ�̣߳��������������Ŀͻ���ͨ��
    pthread_t pthid;   
    if (pthread_create(&pthid,NULL,pth_main,(void*)(long)TcpServer.m_connfd)!=0)
    { 
      logfile.Write("�����߳�ʧ�ܣ������˳���n"); close(TcpServer.m_connfd); EXIT(-1);
    }

    logfile.Write("%s is connected.\n",TcpServer.GetIP());	
	
    vpthid.push_back(pthid);
    vclientfd.push_back(TcpServer.m_connfd);
  }

  return 0;
}

void *pth_main(void *arg)
{
  // pthread_cleanup_push(pthmainexit,arg);// �����߳�������(���ÿ⺯����
   pthread_detach(pthread_self());  // �����̡߳����߳��������е���pthread_detach�ı��Լ���״̬��>���⽩ʬ�߳�
   //����ȡ����ʽΪ����ȡ��������Ϊ�����յ��ź����߳��˳�ʱ����������ȡ�������߳�
  // pthread_setcanceltype(PTHREAD_CANCEL_DISABLE,NULL);
   int clientfd=(int)(long)arg;
   
   struct st_biz stbiz;
   connection conn;      //�������ݿ�Ķ���,ע�ⶨ����ѭ��֮��
   int ibuflen=0; 
   char strRecvBuffer[1024];
   
   while (true)
   {
    memset(strRecvBuffer,0,sizeof(strRecvBuffer));
    //memset(strSendBuffer,0,sizeof(strSendBuffer));//�ĸ������ڲ�ʹ�ã����ڲ���ʼ��

    // ���տͻ��˵�ҵ�������ģ��������false����Ϊ�ǿͻ����˳�������ԭ�򣬲�д������־
    if (TcpRead(clientfd,strRecvBuffer,&ibuflen,20)== false) ///
    {
      // logfile.Write("TcpRead() failed.\n"); 
      break;
    }

    logfile.Write("strRecvBuffer=%s\n",strRecvBuffer);  // xxxxxx

    // �Ѳ�����������
    xmltobiz(strRecvBuffer,&stbiz);  /// 

    if (stbiz.bizid==10000)    // ��������
    {
      if (biz10000(clientfd)==true) continue;
      else break;
    }

    CTimer Timer;

    if (conn.m_state==0)
    {
      // �������ݿ�
      if (conn.connecttodb("shtqapp/pwdidc","Simplified Chinese_China.ZHS16GBK",true)!=0)
      {
        logfile.Write("conn.connettodb() failed.\n"); break;
      } 

      logfile.Write("conn=%lf\n",Timer.Elapsed());
    }
    // ���û���¼ 
    if (stbiz.bizid==10001)    
    {
      if (biz10001(clientfd,&conn,&stbiz)==true) continue;
      else break;
    }

    // ��ȡ����ʵ��
    if (stbiz.bizid==10002)    
    {
      if (biz10002(&stbiz,&conn,clientfd)==true) continue;
      else break;
    }

    // ������

    logfile.Write("�Ƿ�����%s\n",strRecvBuffer); break;
  }
 // pthread_cleanup_pop(1); 
  RemoveClient(clientfd);
  pthread_exit(0);

}

// �رտͻ��˵�socket����vclientfd������ɾ����
void RemoveClient(int clientfd)
{
  for (int ii=0;ii<vclientfd.size();ii++)
  {
    if (vclientfd[ii]==clientfd) 
    { close(clientfd); vclientfd.erase(vclientfd.begin()+ii); return; }
  }
}


// ����ҵ��
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


// ���û���¼ҵ��
bool biz10001(int clientfd,connection *conn,struct st_biz *stbiz)
{
  CTimer Timer;
  char strSendBuffer[1024];
  // �����û�������Ϣ��T_USERINFO
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

  // �����û�������־��
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

    //���ִ�е�SQL����ǲ�ѯ��䣬����execute�����󣬻����һ�����������������ݿ�Ļ������У���
    // next�����ӽ�����л�ȡһ����¼�����ֶε�ֵ�����Ѱ󶨵���������С�
    if (stmt.next()!=0) break;

    sprintf(strSendBuffer,"<obtid>%s</obtid><obtname>%s</obtname><lon>%s</lon><lat>%s</lat><endl/>",strobtid,strobtname,strlon,strlat);

    if (TcpWrite(clientfd,strSendBuffer) == false)
    {
      logfile.Write("biz10001 TcpServer.Write() failed.\n"); return false;
    }
  }

  //logfile.Write("select =%lf\n",Timer.Elapsed());
  // �����һ��ok
  strcpy(strSendBuffer,"ok");
  if (TcpWrite(clientfd,strSendBuffer) == false)
  {
    logfile.Write("biz10001 TcpServer.Write() failed.\n"); return false;
  }

  return true;
}

// ��ȡ����ʵ��
bool biz10002(struct st_biz *stbiz,connection *conn,int clientfd)
{
   return true;
}

// �����û�������־��
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

  // ���ÿ⺯��close(int fd),�ر���ͻ������ӵ�socket(m_connfd)��
  close((int)(long)arg);

  // ��vpthid��ɾ�����̵߳�id��
  for (int ii=0;ii<vpthid.size();ii++)
  {
    if (vpthid[ii]==pthread_self())//��������߳�id���ڱ����߳�id��
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
  
  // �ر�vclientfd������ȫ����socket
  for (int ii=0;ii<vclientfd.size();ii++)
  {
    close(vclientfd[ii]);
  }

  exit(0);
}

void xmltobiz(char *strxmlbuffer,struct st_biz *stbiz) //3�����,���߳��У����ṹ����Ϊ�������ݽ���ʱ���൱�ڸ�����һ������
{
  memset(stbiz,0,sizeof(struct st_biz));

  // ҵ�����
  GetXMLBuffer(strxmlbuffer,"bizid",&stbiz->bizid);
  // logfile.Write("bizid=%d\n",stbiz->bizid);

  // �û��豸ID
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



