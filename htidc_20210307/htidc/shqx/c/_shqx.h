#ifndef _SHQX_H
#define _SHQX_H

#include "_public.h"
#include "_ooci.h"

// ȫ������վ��������ݽṹ
struct st_stcode
{
  char provname[31];   // ʡ����
  char obtid[11];      // վ�����
  char obtname[31];   // ������
  double lat;          // γ��
  double lon;          // ����
  double height;       // ���θ߶�
};

// ȫ������վ����ӹ۲����ݽṹ
struct st_surfdata
{
  char obtid[11];      // վ�����
  char ddatetime[21];  // ����ʱ�䣺��ʽyyyy-mm-dd hh:mi:ss��
  int  t;              // ���£���λ��0.1���϶�
  int  p;              // ��ѹ��0.1����
  int  u;              // ���ʪ�ȣ�0-100֮���ֵ��
  int  wd;             // ����0-360֮���ֵ��
  int  wf;             // ���٣���λ0.1m/s
  int  r;              // ��������0.1mm
  int  vis;            // �ܼ��ȣ�0.1��
};

/*
����һ���࣬�����������۲����ݣ���������ַ�����׼��sql��䣬ִ��
*/
class CSURFDATA
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // ��¼�����ݡ�������������������Ч��¼����
 
  struct st_surfdata m_stsurfdata;//������Ŵ��ļ��л�ȡ�Ĺ۲���Ϣ

  CSURFDATA(connection *conn,CLogFile *logfile);//���캯��
 ~CSURFDATA();//��������

  void initdata();  // ���ݳ�ʼ��

  connection *m_conn; //����connection���͵�һ��ָ�룬��Ŷ����ַ
  CLogFile   *m_logfile;//����һ��CLogFile���͵�һ��ָ�룬��Ŷ����ַ

  int iccount;//�����������棬����ÿ��ʹ�õ�ʱ���ַ�����ı�
  sqlstatement stmtsel,stmtins,stmtupt; //ʵ����3������

  // ���ö��ŷָ��ļ�¼��ֵ�m_stsurfdata�ṹ�С�
  bool SplitBuffer(const char *strBuffer);

  // ��xml��ʽ�ļ�¼��ֵ�m_stsurfdata�ṹ�С�
  bool SplitBuffer1(const char *strBuffer);

  // ��m_stsurfdata�ṹ�е�ֵ���µ�T_SURFDATA���С�
  long InsertTable();
};

class CINIDATA
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // ��¼�����ݡ�������������������Ч��¼����

  struct st_stcode m_stcode;//������Ŵ��ļ��л�ȡ�Ĳ�����Ϣ

  CINIDATA(connection *conn,CLogFile *logfile);//���캯��
 ~CINIDATA();//��������

  void initdata();  // ���ݳ�ʼ��

  connection *m_conn; //����connection���͵�һ��ָ�룬��Ŷ����ַ
  CLogFile   *m_logfile;//����һ��CLogFile���͵�һ��ָ�룬��Ŷ����ַ

  int iccount;//�����������棬����ÿ��ʹ�õ�ʱ���ַ�����ı�
  sqlstatement stmtins; //ʵ����3������

  // ���ö��ŷָ��ļ�¼��ֵ�m_stcode�ṹ�С�
  bool SplitBuffer(const char *strBuffer);

 
  // ��m_stsurfdata�ṹ�е�ֵ���µ�T_OBYCODE���С�
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
  int totalcount,insertcount,updatecount,invalidcount;  // ��¼�����ݡ�������������������Ч��¼����
  struct st_signallog m_stsignallog;
  vector<struct st_signallog> vsignallog;   // �������һ���ļ���ȫ����¼

  CSIGNALLOG(connection *conn,CLogFile *logfile);
 ~CSIGNALLOG();


  void initdata();  // ���ݳ�ʼ��

  connection *m_conn;
  CLogFile   *m_logfile;

  int iccount;
  sqlstatement stmtsel,stmtins,stmtupt;

  // �Ѽ�¼��ֵ�vsignallog�����С�
  bool SplitBuffer(const char *strBuffer);

  // ��vsignallog�����е�ֵ���µ�T_SIGNALDATA���С�
  long InsertTable();
};

//̨����Ϣ���ݽṹ

struct st_tycode
{
 char sortflag[6]; //�����־
 char internum[5]; //���ʱ��, ��ݵ������λ��+��λ���ı��;
 char line[4];     //·�����ݼ�¼������;
 char cynum[5];    //�������
 char donum[5];    //���ڱ��
 int  endflag;     //�ȴ������ս��־:
 int  vtime;       //ÿ��·�����Сʱ��
 char tscname[20]; //�ȴ�������Ӣ������,
 char time[9];     //���ݼ��γɵ�����.ʱ��
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
����һ���࣬��������̨�����ݣ���������ַ�����׼��sql��䣬ִ��
*/

class CTYDATA
{
public:
  int sum,totalcount1,insertcount1,updatecount1,invalidcount1,totalcount2,insertcount2,updatecount2,invalidcount2;// ��¼�����ݡ�����������>��������Ч��¼����

  int m_set;
  struct st_tycode m_sttycode; //������Ŵ��ļ��л�ȡ��ͷ��¼��Ϣ
  struct st_typath m_sttypath; //������Ŵ��ļ��л�ȡ��·����Ϣ

  CTYDATA(connection *conn,CLogFile *logfile);//���캯��

  ~CTYDATA();//��������

  void initdata();  // ���ݳ�ʼ��
connection *m_conn; //����connection���͵�һ��ָ�룬��Ŷ����ַ
  CLogFile   *m_logfile;//����һ��CLogFile���͵�һ��ָ�룬��Ŷ����ַ

  int iccount1,iccount2;//�����������棬����ÿ��ʹ�õ�ʱ���ַ�����ı�

  sqlstatement stmtsel,stmtins,stmtupt,stmtsel2,stmtins2,stmtupt2; //ʵ����3������

  // ����" "�ָ��ļ�¼��ֵ�m_sttycode��m_sttypath�ṹ�С�
  bool SplitBuffer1(const char *strBuffer);

  // ��m_sttycode��m_sttypath�ṹ�е�ֵ���µ�T_SURFDATA���С�
  long InsertTable1();

  long InsertTable2();
};


struct st_json
{
  char w1[31]; //Ԥ��������λ��ʡ������
  char w2[31]; //Ԥ��������λ���м�����
  char w3[31]; //Ԥ��������λ���ؼ�����
  char w4[3]; //Ԥ������� 
  char w5[11]; //Ԥ��������� 
  char w6[3]; //Ԥ�������� 
  char w7[11]; //Ԥ���������� 
  char w8[21]; //Ԥ������ʱ��
  char w9[601]; //Ԥ���������� 
  char w10[51];//Ԥ����Ϣ ID 
  char w11[51];//��ԴURL
};

class CJSONDATA
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // ��¼�����ݡ�������������������Ч��¼����
  //struct st_signallog m_stsignallog;
  //vector<struct st_signallog> vsignallog;   // �������һ���ļ���ȫ����¼

  CJSONDATA(connection *conn,CLogFile *logfile);
 ~CJSONDATA();


  void initdata();  // ���ݳ�ʼ��

  connection *m_conn;
  CLogFile   *m_logfile;

  int iccount;
  sqlstatement stmtsel,stmtins,stmtupt;

  // �Ѽ�¼��ֵ�vsignallog�����С�
  //bool SplitBuffer(const char *strBuffer);

  // ��vsignallog�����е�ֵ���µ�T_SIGNALDATA���С�
  long InsertTable(struct st_json *stjson);
};


struct st_rffc 
{
   char encode[5];   //����ʡ�ı������
   char yygggg[10];  //���ղ�ͬ�Ĳ�Ʒʱ����ò�ͬ��ʱ��
   char commet[101]; //��Ʒ����
   char pcode[6];    //��Ʒ����
   char ctime[11];   //Ԥ���𱨵�������ʱ(����ʱ)
   char pvalue[3];   //Ԥ��ʱЧ
   char obtid[7];    //վ�����
   double t;         //�¶�
   double rh;        //���ʪ��
   double  wd;       //����
   double  wf;       //����
   double  p;        //��ѹ
   double  hourrf;   //������
   double  cloudh;   //������
   double  cloudl;   //������
   double  phenomena; //��������
   double  visibility;//�ܼ���
   double  maxt;      //�������
   double  mint;      //�������
   double  maxrh;     //������ʪ��
   double  minrh;     //��С���ʪ��
   double  hourrf24;  //24 Сʱ�ۼƽ�ˮ��
   double  hourrf12;  //12 Сʱ�ۼƽ�ˮ��
   double  cloudh12;  //12 Сʱ������
   double  cloudl12;  //2 Сʱ������
   double  phenomena12;//2 Сʱ������
   double  wd12;       //12 Сʱ����
   double  wf12;       //12 Сʱ����
};

/*
����һ���࣬��������ϸ��Ԥ�����ݣ���������ַ�����׼��sql��䣬ִ��
*/
class CRFFC
{
public:
  int totalcount,insertcount,updatecount,invalidcount;  // ��¼�����ݡ�������������������Ч��¼����

   char m_buffer1[101],m_buffer2[6],m_buffer3[11],m_buffer4[5],m_buffer5[10],m_buffer6[7],m_buffer7[3]; 
  struct st_rffc m_strffc;//������Ŵ��ļ��л�ȡ�Ĺ۲���Ϣ

  CRFFC(connection *conn,CLogFile *logfile);//���캯��
 ~CRFFC();//��������

  void initdata();  // ���ݳ�ʼ��

  connection *m_conn; //����connection���͵�һ��ָ�룬��Ŷ����ַ
  CLogFile   *m_logfile;//����һ��CLogFile���͵�һ��ָ�룬��Ŷ����ַ

  int iccount;//�����������棬����ÿ��ʹ�õ�ʱ���ַ�����ı�
  sqlstatement stmtsel,stmtins,stmtupt; //ʵ����3������

  // ���ö��ŷָ��ļ�¼��ֵ�m_stsurfdata�ṹ�С�
  bool SplitBuffer(const char *strBuffer);


  // ��m_stsurfdata�ṹ�е�ֵ���µ�T_RFFC���С�
  long InsertTable();
};



// �ѷǽṹ�������ļ�д��oracle���ݿ�ı���
int FileToTable(connection *in_conn,CLogFile *in_logfile,char *in_tname,char *in_filename,char *in_ddatetime);


#endif

