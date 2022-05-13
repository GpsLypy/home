//
// 本程序演示采用CTcpServer类，实现socket通讯的服务端
// 

#include "_public.h"

#pragma pack(1)
struct datarec /* 长度=100 byte */ 
{ unsigned   char baoformat;         //  1 （瞬时报有）
  unsigned   char station;           //  2 （瞬时报有）
  unsigned   char stationname[6];    //  3 （瞬时报有）
  unsigned   int  rec_time;          //  4 （瞬时报有）
  unsigned   long rec_date;          //  5 （瞬时报有）
  unsigned   int  wd2dd;             //  6 （瞬时报有）
  unsigned   int  wd2df;             //  7（瞬时报有）
  unsigned   int  wd10dd;            //  8（瞬时报有）
  unsigned   int  wd10df;            //  9（瞬时报有）
  unsigned   int  wd10maxdd;         // 10 
  unsigned   int  wd10maxdf;         // 11
  unsigned   int  wd3smaxdd;         // 12
  unsigned   int  wd3smaxdf;         // 13 
  unsigned   char wd10maxtime;       // 14
  unsigned   char wd3smaxtime;       // 15
	             int  temp;      //         16（瞬时报有）
	             int  maxtemp;   //         17 
  	          int  mintemp;      //      18
  unsigned   char maxtemptime;       // 19
  unsigned   char mintemptime;       // 20  
  unsigned   int  hourrf;            // 21（瞬时报有）
  unsigned   int  dayrf;             // 22（瞬时报有）
	             char rh;        //         23 （瞬时报有）
	             char maxrh;     //         24
  unsigned   char maxrhtime;         // 25 
 	          char minrh;        //      26
  unsigned   char minrhtime;         // 27 
  unsigned   char rfmark1;           // 28
 	          int  dp;           //      29（瞬时报有）
          int  ps;                // 30 //  ㄋ彩北ㄓ校?	    	       int  maxps;   //           31
  	       int  minps;           //   32 
  unsigned   char maxpstime;         // 33
  unsigned   char minpstime;         // 34
  unsigned   char minrf[12];         // 35  
 	          int  Bps;          //      36
  unsigned   char Ys;                // 37（瞬时报有）
  unsigned   char w3a;               // 38（瞬时报有）
  unsigned   int  wd3daymax;         // 39
  unsigned   int  wf3daymax;         // 40
  unsigned   int  wd3daymaxtime;     // 41 
  unsigned   int  wd10daymax;        // 42 
  unsigned   int  wf10daymax;        // 43
  unsigned   int  wd10daymaxtime;    // 44 
 	          int  daymaxtemp;   //      45
  unsigned   int  daymaxtemptime;    // 46
             int  daymintemp;        // 47 
  unsigned   int  daymintemptime;    // 48
  unsigned   int  WpV;               //49（瞬时报有）
  unsigned   char Tempspace[2];      //50（瞬时报有）
}  Recv_Data;


int main(int argc,char *argv[])
{
  printf("sizeof=%d=\n",sizeof(Recv_Data));
 
  if (argc != 2)
  {
    printf("\n");
    printf("Using:./demo12 port\n\n");

    printf("Example:./demo12 5010\n\n");

    printf("本程序演示采用CTcpServer类，实现socket通讯的服务端。\n\n");

    return -1;
  }

  CTcpServer TcpServer;

  // 服务端初始化
  if (TcpServer.InitServer(atoi(argv[1])) == false)
  {
    printf("TcpServer.InitServer(%s) failed.\n",argv[1]); return -1;
  }

  // 等待客户端的连接
  if (TcpServer.Accept() == false)
  {
    printf("TcpServer.Accept() failed.\n"); return -1;
  }

  printf("client ip is %s\n",TcpServer.GetIP());
//鉴权
 // if(strcmp(TcpServer.GetIP(),"xxx")!=0);
  char strRecvBuffer[1024],strSendBuffer[1024];

  memset(strRecvBuffer,0,sizeof(strRecvBuffer));

  // 读取客户端的报文，等时间是10秒
  if (TcpServer.Read(strRecvBuffer,10)==false) 
 // if (TcpServer.Read(strRecvBuffer)==false) 
  {
    if (TcpServer.m_btimeout==true) printf("timeout\n");
    printf("TcpServer.Read() failed.\n"); return -1;
  }

  printf("recv ok:%s\n",strRecvBuffer);

  memset(strSendBuffer,0,sizeof(strSendBuffer));
  strcpy(strSendBuffer,"ok");

  // 向客户端返回响应内容
  if (TcpServer.Write(strSendBuffer)==false) 
  {
    printf("TcpServer.Write() failed.\n"); return -1;
  }

  printf("send ok:%s\n",strSendBuffer);

  return 0;
}


