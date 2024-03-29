/*
   freec++框架头文件，包括了公共的数据结构、函数和类。
   这是一个完全开源的框架，对使用者没有任何限制，可用于商业用途，但是，在使用者的项目中，必须标明源作者
   作者：码农有道   日期：20190601
*/
#ifndef _PUBLIC_H
#define _PUBLIC_H 1

#include "_cmpublic.h"

///////////////////////////////////// /////////////////////////////////////
// 以下是字符串操作相关的函数和类

// STRCPY、STRNCPY、STRCAT、STRNCAT、SNPRINTF函数弥补strcpy、strncpy、strcat、strncat、snprintf缺陷
// 以后可以用这四个函数取代strcpy、strncpy、strcat、strncat、snprintf
// 函数的第二个参数是第一个参数dest有效长度，即占用内存的字节数-1。
// 该系列函数解决三个问题：1）变量初始化；2）内存溢出；3）修复strncpy的缺陷。
char *STRCPY(char* dest,const size_t destlen,const char* src);
char *STRNCPY(char* dest,const size_t destlen,const char* src,size_t n);
char *STRCAT(char* dest,const size_t destlen,const char* src);
char *STRNCAT(char* dest,const size_t destlen,const char* src,size_t n);
int SNPRINTF(char *dest,const size_t destlen,size_t n,const char *fmt,...);
// 从一个字符串中提取数字、符号和小数点，并判断是否是一个合法的数
// 如果不合法，将返回空字符串
// bWithSign==true表示包括符号，bWithDOT==true表示包括圆点
void PickNumber(const char *strSrc,char *strDst,const bool bWithSign,const bool bWithDOT);

// 判断字符串中的负号和圆点是否合法
bool JudgeSignDOT(const char *strSrc,const char *strBZ);

// 删除字符串左边指定的字符
void DeleteLChar(char *in_string,const char in_char);

// 删除字符串右边指定的字符
void DeleteRChar(char *in_string,const char in_char);

// 删除字符串两边指定的字符
void DeleteLRChar(char *in_string,const char in_char);

// 把小写转换成大写，忽略不是字母的字符
void ToUpper(char *str);
void ToUpper(string &str);

// 把大写转换成小写，忽略不是字母的字符
void ToLower(char *str);
void ToLower(string &str);

// 字符串替换函数
// 把in_string中的in_str1替换为in_str2
// bLoop是否循环执行替换
// 注意
// 1、如果in_str2比in_str1要长，替换后in_string会变长，所以必须保证in_string有足够的长度， 否则内存会溢出
// 2、如果in_str2中包函了in_str1的内容，且bLoop为true，就会进入死循环，最终导致内存溢出
void UpdateStr(char *in_string,const char *in_str1,const char *in_str2,bool bLoop=true);

// 拆分字符串的类
// 字符串的格式为:内容1+分隔字符串+内容2+分隔字符串+内容3
// 如:num~!~name~!~address,分隔符为"~!~"
class CCmdStr
{
public:
  vector<string> m_vCmdStr;  // 存放拆分后的字段内容。

  CCmdStr();

  // 拆分字符串到容器中
  void SplitToCmd(const string in_string,const char *in_sep,const bool bdeletespace=true);

  int CmdCount();

  // 获取字段的值，取每个字段的值inum从0开始
  bool GetValue(const int inum,char   *in_return);
  bool GetValue(const int inum,char   *in_return,const int in_len);
  bool GetValue(const int inum,int    *in_return);
  bool GetValue(const int inum,long   *in_return);
  bool GetValue(const int inum,double *in_return);

  ~CCmdStr();
};
///////////////////////////////////// /////////////////////////////////////

///////////////////////////////////// /////////////////////////////////////
// 正则表达式

// 判断文件名是否匹配in_MatchStr指定的规则
// in_FileName文件名，如"_public.cpp"
// in_MatchStr规则表达式，如"*.txt,*.xml"，中间用逗号分隔
bool MatchFileName(const string in_FileName,const string in_MatchStr);
///////////////////////////////////// /////////////////////////////////////

///////////////////////////////////// /////////////////////////////////////
// 以下是XML格式字符串的相关操作函数和类

// 操作XMLBuffer的函数
// in_XMLBuffer，XML格式的字符串，如下：
// <filename>/tmp/readme.txt</filename><mtime>2018-01-01 12:20:35</mtime><size>10241</size>
// in_FieldName，字段的标签名
// out_Value，获取内容存放的变量的指针
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,bool   *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,int    *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,unsigned int *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,long   *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,unsigned long *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);
bool GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,char   *out_Value,const int in_StrLen=0);
///////////////////////////////////// /////////////////////////////////////

///////////////////////////////////// /////////////////////////////////////
// 目录操作相关的类

// 文件信息的数据结构 
// 全路径文件名，大小，时间的结构体
struct st_fileinfo
{
  char filename[301];
  int  filesize;
  char mtime[21];
};

// 读取某目录下的全部的文件
class CDir
{
public:
  char m_DirName[301];         // 目录名
  char m_FileName[301];        // 文件名，不包括目录名
  char m_FullFileName[301];    // 文件全名，包括目录名
  int  m_FileSize;             // 文件的大小
  char m_ModifyTime[21];       // 文件最后一次被修改的时间
  char m_CreateTime[21];       // 文件生成的时间
  char m_AccessTime[21];       // 文件最后一次被访问的时间

  int m_uPOS;                 // 已读取m_vFileName容器的位置
  vector<string> m_vFileName;  //  存放OpenDir方法获取到的文件列表

  CDir();

  // 变量初始化
  void initdata();

  // 设置日期时间的格式，支持"yyyy-mm-dd hh24:mi:ss"和"yyyymmddhh24miss"两种格式，缺省是前者
  char m_DateFMT[21];
  void SetDateFMT(const char *in_DateFMT);

  // 打开目录，获取文件名信息，存放于m_vFileName容器中
  // in_DirName，待打开的目录名
  // in_MatchStr，待获取文件名的匹配规则
  // in_MaxCount，获取文件的最大数量
  // bAndChild，是否打开各级子目录
  // bSort，是否对结果集进行排序
  bool OpenDir(const char *in_DirName,const char *in_MatchStr,const unsigned int in_MaxCount=10000,const bool bAndChild=false,bool bSort=false);

  // 这是一个递归函数，用于OpenDir()的调用。
  bool _OpenDir(const char *in_DirName,const char *in_MatchStr,const unsigned int in_MaxCount,const bool bAndChild);

  // 逐个读取目录中的文件信息
  bool ReadDir();

  ~CDir();
};

// 用文件或目录的全路径中的目录创建目录，以及该目录下的各级子目录
// pathorfilename 目录名或文件名
// bisfilename true-pathorfilename是文件名，否则是目录名
bool MKDIR(const char *pathorfilename,bool bisfilename=true);
///////////////////////////////////// /////////////////////////////////////

///////////////////////////////////// /////////////////////////////////////
// 文件操作相关的函数和类

// 删除文件，如果删除失败，会尝试in_times次
bool REMOVE(const char *in_filename,const int in_times=3);

// 把in_srcfilename改名为in_dstfilename，如果改名失败，会尝试in_times次
bool RENAME(const char *in_srcfilename,const char *in_dstfilename,const int in_times=3);

// 把某一个文件复制到另一个文件
bool COPY(const char *srcfilename,const char *dstfilename);

// 调用fopen函数打开文件，如果文件名中包含的目录不存在，就创建目录
FILE *FOPEN(const char *filename,const char *mode);

// 获取文件的大小，返回字节数
int FileSize(const char *in_FullFileName);

// 获取文件的时间，即modtime
void FileMTime(const char *in_FullFileName,char *out_ModTime);

// 更改文件的修改时间属性，mtime指定了时间，格式不限，只要包括了yyyy,mm,dd,hh24,mi,ss即可。
int UTime(const char *filename,const char *mtime);

// 把字符串格式的时间转换为time_t
// 从文件文件中读取一行
// strEndStr是一行数据的结束标志，如果为空，则以换行符"\n"为结束标志。
// 本函数不会删除行的结束标志
bool FGETS(const FILE *fp,char *strBuffer,const int ReadSize,const char *strEndStr=0);

// 文件操作类声明
class CFile
{
private:
  FILE *m_fp;        // 文件指针
  bool  m_bEnBuffer; // 是否启用缓冲区，true-启用；false-不启用
  char  m_filename[301]; // 文件名
  char  m_filenametmp[301]; // 临时文件名

public:
  CFile();   // 类的构造函数
 ~CFile();   // 类的析构函数

  bool IsOpened();  // 判断文件是否已打开

  // 打开文件，参数与fopen相同，打开成功true，失败返回false          
  bool Open(const char *filename,const char *openmode,bool bEnBuffer=true);
  // 关闭文件指针，并删除文件
  bool CloseAndRemove();

  // 专为改名而创建文件，参数与fopen相同，打开成功true，失败返回false          
  // 函数将会创建filename后加.tmp的临时文件，调用CloseAndRename()后才把临时文件改名为正式文件
  bool OpenForRename(const char *filename,const char *openmode,bool bEnBuffer=true);
  // 关闭文件并改名
  bool CloseAndRename();

  // 调用fprintf向文件写入数据
  void Fprintf(const char *fmt, ... );

  // 调用fgets从文件中读取一行，bDelCRT=true删除换行符，false不删除，缺省为false
  bool Fgets(char *strBuffer,const int ReadSize,bool bDelCRT=false);

  // 从文件文件中读取一行
  // strEndStr是一行数据的结束标志，如果为空，则以换行符"\n"为结束标志。
  // 与Fgets不同，本函数不删除结束标志
  bool FFGETS(char *strBuffer,const int ReadSize,const char *strEndStr=0);

  // 调用fread从文件中读取数据
  size_t Fread(void *ptr,size_t size);

  // 调用fwrite向文件中写数据
  size_t Fwrite(const void *ptr,size_t size);

  // 关闭文件指针，如果存在临时文件，就删除它。
  void Close();
};
///////////////////////////////////// /////////////////////////////////////


/*
  取操作系统的时间
  out_stime是输出结果
  in_interval是偏移常量，单位是秒
  返回的格式由fmt决定，fmt目前的取值如下，如果需要，可以增加：
  yyyy-mm-dd hh:mi:ss，此格式是缺省格式
  yyyymmddhhmiss
  yyyy-mm-dd
  yyyymmdd
  hh:mi:ss
  hhmiss
  hh:mi
  hhmi
  hh
  mi
*/
void LocalTime(char *out_stime,const char *in_fmt=0,const int in_interval=0);

// 把字符串格式的时间转换为整数的时间
// stime为输入的时间，格式不限，但一定要包括yyyymmddhh24miss
time_t strtotime(const char *stime);

/*
  把一个字符串表格的时间加上一个偏移量，得到偏移后的时间
  in_stime是传入的时间，任意格式，但是一定要包括yyyymmddhh24miss，是否有分隔符没有关系。
  把yyyy-mm-dd hh24:mi:ss偏移in_interval秒
  传出的格式由fmt决定，fmt目前的取值如下，如果需要，可以增加：
  yyyy-mm-dd hh24:mi:ss（此格式是缺省格式）
  yyyymmddhh24miss
  yyyymmddhh24miss
  yyyy-mm-dd
  yyyymmdd
  hh24:mi:ss
  hh24miss
  hh24:mi
  hh24mi
  返回值：0-成功，-1-失败。
*/
int AddTime(const char *in_stime,char *out_stime,const int in_interval,const char *in_fmt=0);
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
// 以下是日志文件操作类

#define MAXLOGFSIZE 100    // 日志文件切换的大小，单位是M

// 日志文件操作类
class CLogFile
{
public:
  FILE   *m_tracefp;           // 日志文件指针
  char    m_filename[301];     // 日志文件全名
  char    m_openmode[11];      // 日志文件的打开方式
  bool    m_bBackup;           // 日志文件超出MAXLOGFSIZE，是否自动备份
  bool    m_bEnBuffer;         // 写入日志时，是否启用操作系统的缓冲机制

  CLogFile();

  // filename日志文件名
  // openmode打开文件的方式，操作日志文件的权限,同打开文件函数(fopen)使用方法一致，一般采用"a+"
  // bBackup，true-备份，false-不备份，在多进程的服务程序中，如果多个进行共用一个日志文件，bBackup必须为false
  // bEnBuffer:true-启用缓冲区，false-不启用缓冲区，如果启用缓冲区，那么写进日志文件中的内容不会立即写入文件
  // 注意，bEnBuffer参数的值如果设置为true，可能会导致日志文件内容不完整。
  bool Open(const char *in_filename,const char *in_openmode,bool bBackup=true,bool bEnBuffer=false);

  // 如果日志文件大于100M，就备份它
  // 备份后的文件会在源文件名后加上日期时间
  // 注意，在多进程程序中，日志文件不可切换，多线王中王程序中，日志文件可以切换。
  bool BackupLogFile();

  // 写日志文件,它是个可变参数的方法,同printf函数。
  // Write()方法会写入时间，WriteEx()方法不写时间。
  bool Write(const char *fmt,...);
  bool WriteEx(const char *fmt,...);

  // 关闭日志文件
  void Close();

  ~CLogFile();
};
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
// 以下是TCP/IP通讯的函数和类

#define TCPHEADLEN     4  // TCP报文头部的长度
#define TCPBUFLEN  10240  // TCP报文的最大长度，不能超过TCPHEADLEN能表达的长度。

// 用于TCP通讯的客户类
class CTcpClient
{
public:
  int  m_sockfd;        // socket id
  char m_ip[21];        // 服务端的IP
  int  m_port;          // 与服务端通讯的端口
  bool m_state;         // 连接状态
  bool m_btimeout;      // Read()方法是否超时，true-未超时，false-已超时
  int  m_buflen;        // 接收到的报文的包大小

  CTcpClient();

  // 向服务端发起连接
  bool ConnectToServer(const char *in_ip,const int in_port);                // 连接服务器

  // 没有超时机制的接收函数
  bool Read(char *strRecvBuffer);
  // 有超时机制的接收函数
  bool Read(char *strRecvBuffer,const int iTimeOut);

  // 向服务端发送字符串，长度为字符串的长度
  bool Write(char *strSendBuffer);

  // 向服务端发送流数据，需要指定长度
  bool Write(char *strSendBuffer,const int buflen);

  // 断开与服务端的连接
  void Close();

  ~CTcpClient();
};

// 用于TCP通讯的服务类
class CTcpServer
{
private:
  int m_socklen;                    // struct sockaddr_in的大小
  struct sockaddr_in m_clientaddr;  // 客户端的地址信息
  struct sockaddr_in m_servaddr;    // 服务端的地址信息
public:
  int  m_listenfd;                  // 服务端用于监听的socket
  int  m_connfd;                    // 客户端的socket
  bool m_btimeout;                  // Read()方法是否超时，true-未超时，false-已超时
  int  m_buflen;                    // 接收到的报文的包大小

  CTcpServer();
  bool InitServer(const unsigned int port); // 初始化TcpServer
  bool Accept();                            // 接受客户端的请求
  char *GetIP();                            // 获取客户端的ip地址


  // 没有超时机制的接收函数
  bool Read(char *strRecvBuffer);
  // 有超时机制的接收函数
  bool Read(char *strRecvBuffer,const int iTimeOut);

  // 向客户端发送字符串，长度为字符串的长度
  bool Write(char *strSendBuffer);

  // 向客户端发送流数据，需要指定长度
  bool Write(char *strSendBuffer,const int buflen);

  // 关闭监听的sock，用于多进程服务程序的子进程代码中
  void CloseListen();

  // 关闭客户端的sock，用于多进程服务程序的父进程代码中
  void CloseClient();

  ~CTcpServer();
};

// 读取socket的数据
// fd socket
// strRecvBuffer 读取结果存放的缓冲区
// buflen 读取到的报文的长度
// iTimeOut 读取超时的时间
bool TcpRead(const int fd,char *strRecvBuffer,int *buflen,const int iTimeOut=0);

// 把数据写入socket
// fd socket
// strSendBuffer 待写入数据存放的缓冲区
// buflen 待写入数据的长度，如果为0，就认为strSendBuffer是一个字符串。
// iTimeOut 写入超时的时间
bool TcpWrite(const int fd,const char *strSendBuffer,const int buflen=0,const int iTimeOut=0);

// 从socket中读取数据，专用于TcpRead函数
bool Readn(const int fd,char *vptr,const size_t n);

// 向socket中写入数据，专用于TcpWrite函数
bool Writen(const int fd,const char *vptr,const size_t n);

// 把文件通过sockfd发送给对端
bool SendFile(CLogFile *logfile,int sockfd,struct st_fileinfo *stfileinfo);

// 接收通过socdfd发送过来的文件
bool RecvFile(CLogFile *logfile,int sockfd,struct st_fileinfo *stfileinfo);
// 以上是TCP/IP通讯的函数和类
///////////////////////////////////// /////////////////////////////////////

///////////////////////////////////// /////////////////////////////////////
// 以下是精确到微秒的计时器
// 这是一个精确到微秒的计时器
class CTimer
{
public:
  struct timeval m_start,m_end;

  CTimer();

  // 开始计时
  void Start();

  // 计算已逝去的时间，单位：秒，小数点后面是微秒
  double Elapsed();
};
///////////////////////////////////// /////////////////////////////////////

// 关闭全部的信号和输入输出
void CloseIOAndSignal();


#endif

