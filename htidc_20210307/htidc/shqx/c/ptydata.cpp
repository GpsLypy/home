/*
 *  ���������ڴ���̨�����ݣ������浽���ݿ��T_tycode t_typath���С�
*/
#include "_public.h"
#include "_ooci.h"
#include "_shqx.h"

CLogFile logfile;

CDir Dir;

// ���������ļ�
bool _ptydata();

connection conn;

void EXIT(int sig);

int main(int argc,char *argv[])
{
  if (argc!=5)
  {
    printf("\n���������ڴ������Ԥ���źŷ�����־�������浽���ݿ��T_SIGNALLOG���С�\n");
    printf("/htidc/shqx/bin/psignallog �����ļ���ŵ�Ŀ¼ ��־�ļ��� ���ݿ����Ӳ��� ��������ʱ����\n");
    printf("���磺/htidc/shqx/bin/ptydata /data/shqx/sdata/TYDATA /log/shqx/ptydata.log shtqapp/pwdidc 10\n");
    return -1;
  }

  // �ر�ȫ�����źź��������
  CloseIOAndSignal();

  // ��������˳����ź�
  signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

  if (logfile.Open(argv[2],"a+")==false)
  {
    printf("����־�ļ�ʧ�ܣ�%s����\n",argv[2]); return -1;
  }

  logfile.Write("����������\n");

  while (true)
  {
    // logfile.Write("��ʼɨ��Ŀ¼��\n");

    // ɨ�������ļ���ŵ�Ŀ¼��ֻƥ��"WP20*.DTB"
    if (Dir.OpenDir(argv[1],"CH*.TXT",1000,true,true)==false)
    {
      logfile.Write("Dir.OpenDir(%s) failed.\n",argv[1]); sleep(atoi(argv[4])); continue;
    }

    // �������Ŀ¼�е������ļ�
    while (true)
    {
      if (Dir.ReadDir()==false) break;
  
      if (conn.m_state==0)
      {
        if (conn.connecttodb(argv[3],"Simplified Chinese_China.ZHS16GBK")!=0)
        {
          logfile.Write("connect database(%s) failed.\n%s\n",argv[3],conn.m_cda.message); break;
        }
        // logfile.Write("�������ݿ�ɹ���\n");
      }
  
      logfile.Write("��ʼ�����ļ�%s...\n",Dir.m_FileName);
  
      // ���������ļ�
      if (_ptydata()==false) 
      {
        logfile.WriteEx("ʧ�ܡ�\n"); break;
      }
    }

    // �Ͽ������ݿ������
    if (conn.m_state==1) conn.disconnect(); 

    sleep(atoi(argv[4]));
  }

  return 0;
}

void EXIT(int sig)
{
  logfile.Write("�����˳���sig=%d\n\n",sig);

  exit(0);
}
     

// ���������ļ�
bool _ptydata()
{
  // ���ļ�
  CFile File;

  if (File.Open(Dir.m_FullFileName,"r")==false)
  {
    logfile.Write("(File.Open(%s) failed.\n",Dir.m_FullFileName); return false;
  }

  CTYDATA TYDATA(&conn,&logfile);

  // ��ȡ�ļ��е�ÿһ�м�¼
  // д�����ݿ�ı���
  char strBuffer[301];

  while (true)
  {
    memset(strBuffer,0,sizeof(strBuffer));

    // ���ļ��л�ȡһ�м�¼
    if (File.Fgets(strBuffer,300,true)==false) break;

    UpdateStr(strBuffer,"  "," ",true);  // �������е������ո��滻��һ���ո�
    //logfile.Write("1->%s\n",strBuffer);
    
    // ���ö��ŷָ��ļ�¼��ֵ��ṹ����
    if (TYDATA.SplitBuffer1(strBuffer)==false) { logfile.Write("1->%s\n",strBuffer); continue; }

    //logfile.Write("m_set=%d\n",TYDATA.m_set);
    if(TYDATA.m_set==1)
    {
     // ��ͷ��¼��ֵ���µ�T_TYCODE���С�
     long rc=TYDATA.InsertTable1();
     
     // ֻҪ�������ݿ�session�Ĵ��󣬳���ͼ�����
     if ( (rc>=3113) && (rc<=3115) ) return false;

     if (rc != 0) { logfile.Write("%s\n",strBuffer); continue; }
   
    }
    
    if(TYDATA.m_set==2)
    {
      long rc=TYDATA.InsertTable2();

      // ֻҪ�������ݿ�session�Ĵ��󣬳���ͼ�����
      if ( (rc>=3113) && (rc<=3115) ) return false;

      if (rc != 0) { logfile.Write("2->%s\n",strBuffer); continue; }
  
     }
  }
  
  // �ύ����
  conn.commit();

  // �ر��ļ�ָ�룬��ɾ���ļ�
  File.CloseAndRemove();

  logfile.WriteEx("���ļ��м�¼����Ϊsum=%d\n",TYDATA.sum);

  logfile.WriteEx("���ļ���ͷ��¼����ɹ�(total1=%d,insert1=%d,update1=%d,invalid1=%d)��\n",TYDATA.totalcount1,TYDATA.insertcount1,TYDATA.updatecount1,TYDATA.invalidcount1);

  logfile.WriteEx("���ļ���ʵ��·������ɹ�(total2=%d,insert2=%d,update2=%d,invalid2=%d)��\n",TYDATA.totalcount2,TYDATA.insertcount2,TYDATA.updatecount2,TYDATA.invalidcount2);

  return true;
}



