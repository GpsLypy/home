#ifndef _SHQX_H
#define _SHQX_H

#include "_public.h"
#include "_ooci.h"

// 全国气象站点参数数据结构
struct st_stcode
{
  char provname[31];   // 省名称
  char obtid[11];      // 站点代码
  char obtname[31];   // 城市名
  double lat;          // 纬度
  double lon;          // 经度
  double height;       // 海拔高度
};

// 全国气象站点分钟观测数据结构
struct st_surfdata
{
  char obtid[11];      // 站点代码
  char ddatetime[21];  // 数据时间：格式yyyy-mm-dd hh:mi:ss。
  int  t;              // 气温：单位，0.1摄氏度
  int  p;              // 气压：0.1百帕
  int  u;              // 相对湿度，0-100之间的值。
  int  wd;             // 风向，0-360之间的值。
  int  wf;             // 风速：单位0.1m/s
  int  r;              // 降雨量：0.1mm
  int  vis;            // 能见度：0.1米
};

/*
定义一个类，用来处理地面观测数据，包括拆分字符串，准备sql语句，执行
*/
class CSURFDATA
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // 记录总数据、插入数、更新数、无效记录数。
 
  struct st_surfdata m_stsurfdata;//用来存放从文件中获取的观测信息

  CSURFDATA(connection *conn,CLogFile *logfile);//构造函数
 ~CSURFDATA();//析构函数

  void initdata();  // 数据初始化

  connection *m_conn; //定义connection类型的一个指针，存放对象地址
  CLogFile   *m_logfile;//定义一个CLogFile类型的一个指针，存放对象地址

  int iccount;//定义在类里面，避免每次使用的时候地址发生改变
  sqlstatement stmtsel,stmtins,stmtupt; //实例化3个对象

  // 把用逗号分隔的记录拆分到m_stsurfdata结构中。
  bool SplitBuffer(const char *strBuffer);

  // 把xml格式的记录拆分到m_stsurfdata结构中。
  bool SplitBuffer1(const char *strBuffer);

  // 把m_stsurfdata结构中的值更新到T_SURFDATA表中。
  long InsertTable();
};

class CINIDATA
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // 记录总数据、插入数、更新数、无效记录数。

  struct st_stcode m_stcode;//用来存放从文件中获取的参数信息

  CINIDATA(connection *conn,CLogFile *logfile);//构造函数
 ~CINIDATA();//析构函数

  void initdata();  // 数据初始化

  connection *m_conn; //定义connection类型的一个指针，存放对象地址
  CLogFile   *m_logfile;//定义一个CLogFile类型的一个指针，存放对象地址

  int iccount;//定义在类里面，避免每次使用的时候地址发生改变
  sqlstatement stmtins; //实例化3个对象

  // 把用逗号分隔的记录拆分到m_stcode结构中。
  bool SplitBuffer(const char *strBuffer);

 
  // 把m_stsurfdata结构中的值更新到T_OBYCODE表中。
  long InsertTable();
};


struct st_signallog
{
  char obtid[11];
  char ddatetime[20];
  char signalname[2];
  char signalcolor[2];
};

class CSIGNALLOG
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // 记录总数据、插入数、更新数、无效记录数。
  struct st_signallog m_stsignallog;
  vector<struct st_signallog> vsignallog;   // 容器存放一个文件的全部记录

  CSIGNALLOG(connection *conn,CLogFile *logfile);
 ~CSIGNALLOG();


  void initdata();  // 数据初始化

  connection *m_conn;
  CLogFile   *m_logfile;

  int iccount;
  sqlstatement stmtsel,stmtins,stmtupt;

  // 把记录拆分到vsignallog容器中。
  bool SplitBuffer(const char *strBuffer);

  // 把vsignallog容器中的值更新到T_SIGNALDATA表中。
  long InsertTable();
};

//台风信息数据结构

struct st_tycode
{
 char sortflag[6]; //分类标志
 char internum[5]; //国际编号, 年份的最后两位数+两位数的编号;
 char line[4];     //路径数据记录的行数;
 char cynum[5];    //气旋序号
 char donum[5];    //国内编号
 int  endflag;     //热带气旋终结标志:
 int  vtime;       //每行路径间隔小时数
 char tscname[20]; //热带气旋的英文名称,
 char time[9];     //数据集形成的日期.时间
};


struct st_typath
{
 char ttime[11];
 int  fflag;
 int  llat;
 int  llon;
 int  pressure;
 int  windspeed;
};


/*
定义一个类，用来处理台风数据，包括拆分字符串，准备sql语句，执行
*/

class CTYDATA
{
public:
  int sum,totalcount1,insertcount1,updatecount1,invalidcount1,totalcount2,insertcount2,updatecount2,invalidcount2;// 记录总数据、插入数、更>新数、无效记录数。

  int m_set;
  struct st_tycode m_sttycode; //用来存放从文件中获取的头记录信息
  struct st_typath m_sttypath; //用来存放从文件中获取的路径信息

  CTYDATA(connection *conn,CLogFile *logfile);//构造函数

  ~CTYDATA();//析构函数

  void initdata();  // 数据初始化
connection *m_conn; //定义connection类型的一个指针，存放对象地址
  CLogFile   *m_logfile;//定义一个CLogFile类型的一个指针，存放对象地址

  int iccount1,iccount2;//定义在类里面，避免每次使用的时候地址发生改变

  sqlstatement stmtsel,stmtins,stmtupt,stmtsel2,stmtins2,stmtupt2; //实例化3个对象

  // 把用" "分隔的记录拆分到m_sttycode和m_sttypath结构中。
  bool SplitBuffer1(const char *strBuffer);

  // 把m_sttycode和m_sttypath结构中的值更新到T_SURFDATA表中。
  long InsertTable1();

  long InsertTable2();
};


struct st_json
{
  char w1[31]; //预警发布单位的省级名称
  char w2[31]; //预警发布单位的市级名称
  char w3[31]; //预警发布单位的县级名称
  char w4[3]; //预警类别编号 
  char w5[11]; //预警类别名称 
  char w6[3]; //预警级别编号 
  char w7[11]; //预警级别名称 
  char w8[21]; //预警发布时间
  char w9[601]; //预警发布内容 
  char w10[51];//预警信息 ID 
  char w11[51];//来源URL
};

class CJSONDATA
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // 记录总数据、插入数、更新数、无效记录数。
  //struct st_signallog m_stsignallog;
  //vector<struct st_signallog> vsignallog;   // 容器存放一个文件的全部记录

  CJSONDATA(connection *conn,CLogFile *logfile);
 ~CJSONDATA();


  void initdata();  // 数据初始化

  connection *m_conn;
  CLogFile   *m_logfile;

  int iccount;
  sqlstatement stmtsel,stmtins,stmtupt;

  // 把记录拆分到vsignallog容器中。
  //bool SplitBuffer(const char *strBuffer);

  // 把vsignallog容器中的值更新到T_SIGNALDATA表中。
  long InsertTable(struct st_json *stjson);
};


struct st_rffc 
{
   char encode[5];   //发报省的编码代号
   char yygggg[10];  //按照不同的产品时间采用不同的时间
   char commet[101]; //产品描述
   char pcode[6];    //产品代码
   char ctime[11];   //预报起报的年月日时(世界时)
   char pvalue[3];   //预报时效
   char obtid[7];    //站点代码
   double t;         //温度
   double rh;        //相对湿度
   double  wd;       //风向
   double  wf;       //风速
   double  p;        //气压
   double  hourrf;   //降雨量
   double  cloudh;   //总云量
   double  cloudl;   //低云量
   double  phenomena; //天气现象
   double  visibility;//能见度
   double  maxt;      //最高气温
   double  mint;      //最低气温
   double  maxrh;     //最大相对湿度
   double  minrh;     //最小相对湿度
   double  hourrf24;  //24 小时累计降水量
   double  hourrf12;  //12 小时累计降水量
   double  cloudh12;  //12 小时总云量
   double  cloudl12;  //2 小时低云量
   double  phenomena12;//2 小时低云量
   double  wd12;       //12 小时风向
   double  wf12;       //12 小时风速
};

/*
定义一个类，用来处理精细化预报数据，包括拆分字符串，准备sql语句，执行
*/
class CRFFC
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // 记录总数据、插入数、更新数、无效记录数。

   char m_buffer1[101],m_buffer2[6],m_buffer3[11],m_buffer4[5],m_buffer5[10],m_buffer6[7],m_buffer7[3]; 
  struct st_rffc m_strffc;//用来存放从文件中获取的观测信息

  CRFFC(connection *conn,CLogFile *logfile);//构造函数
 ~CRFFC();//析构函数

  void initdata();  // 数据初始化

  connection *m_conn; //定义connection类型的一个指针，存放对象地址
  CLogFile   *m_logfile;//定义一个CLogFile类型的一个指针，存放对象地址

  int iccount;//定义在类里面，避免每次使用的时候地址发生改变
  sqlstatement stmtsel,stmtins,stmtupt; //实例化3个对象

  // 把用逗号分隔的记录拆分到m_stsurfdata结构中。
  bool SplitBuffer(const char *strBuffer);


  // 把m_stsurfdata结构中的值更新到T_RFFC表中。
  long InsertTable();
};



// 把非结构化数据文件写入oracle数据库的表中
int FileToTable(connection *in_conn,CLogFile *in_logfile,char *in_tname,char *in_filename,char *in_ddatetime);


#endif

