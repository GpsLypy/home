#include "_public.h"
#include "_ooci.h"
#include "cJSON.h" 
#include "_shqx.h"
CLogFile logfile;

CDir Dir;
connection conn;

// ���������ļ�
bool _pjsondata();

bool _Parse(char *s,struct st_json *stjson);
void EXIT(int sig);

int main(int argc,char *argv[])
{
  if (argc!=5)
  {
    printf("\n���������ڴ���ȫ��Ԥ����Ϣ�������浽���ݿ��T_SIGNALLOG���С�\n");
    printf("/htidc/shqx/bin/psignallog �����ļ���ŵ�Ŀ¼ ��־�ļ��� ���ݿ����Ӳ��� ��������ʱ����\n");
    printf("���磺/htidc/shqx/bin/pjsondata /data/shqx/sdata/JSONDATA /log/shqx/pjsondata.log shtqapp/pwdidc 10\n");
    return -1;
  }

  // �ر�ȫ�����źź��������
  CloseIOAndSignal();
  // ��������˳����ź�
  signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

  if (logfile.Open(argv[2],"a+")==false)
  {
    logfile.Write("����־�ļ�ʧ�ܣ�%s����\n",argv[2]); return -1;
  }

  logfile.Write("����������\n");
 

 
  while (true)
  {
     logfile.Write("��ʼɨ��Ŀ¼��\n");

    // ɨ�������ļ���ŵ�Ŀ¼��ֻƥ��"*.data1"
    if (Dir.OpenDir(argv[1],"*.json",1000,true,true)==false)
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
      if (_pjsondata()==false)
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
bool _pjsondata()
{
  // ���ļ�
  CFile File;

  if (File.Open(Dir.m_FullFileName,"r")==false)
  {
    logfile.Write("(File.Open(%s) failed.\n",Dir.m_FullFileName); return false;
  }

  CJSONDATA JSONDATA(&conn,&logfile);

  // ��ȡ�ļ��е�ÿһ�м�¼
  // д�����ݿ�ı���
  char strBuffer[1024];

  while (true)
   {
     memset(strBuffer,0,sizeof(strBuffer));

     // ���ļ��л�ȡһ�м�¼
     if (File.Fgets(strBuffer,1024,true)==false) break;

     logfile.Write("1->%s,%d\n",strBuffer,strlen(strBuffer));

     struct st_json stjson;
     char *s=strBuffer;
     //��¼��ֵ��ṹ����
     if(_Parse(s,&stjson)==false) {logfile.Write("Parse failed\n");continue;}   

     long rc=JSONDATA.InsertTable(&stjson);

     // ֻҪ�������ݿ�session�Ĵ��󣬳���ͼ�����
     if ( (rc>=3113) && (rc<=3115) ) return false;

     if (rc != 0) { logfile.Write("2->%s\n",strBuffer); continue; }

  }
  // �ύ����
  conn.commit();

  // �ر��ļ�ָ�룬��ɾ���ļ�
  //File.CloseAndRemove();
  
  return true;
}
 


bool _Parse(char *s,struct st_json *stjson)
{
  //struct st_json stjson;
  memset(stjson,0,sizeof(struct st_json));
  cJSON *root = cJSON_Parse(s);
  if(!root) { logfile.Write("get root faild !\n"); return false;}

  cJSON *js_w = cJSON_GetObjectItem(root, "w");
  if(!js_w){ logfile.Write("no w!\n"); return false; }

  int array_size = cJSON_GetArraySize(js_w);
  logfile.Write("array size is %d\n",array_size);
  if(array_size==0) return false;
  int i = 0;
  cJSON *item,*it,*js_w1,*js_w2,*js_w3,*js_w4,*js_w5,*js_w6,*js_w7,*js_w8,*js_w9,*js_w10,*js_w11;
  char *p  = NULL;

  for(i=0; i< array_size; i++) 
  {
    item = cJSON_GetArrayItem(js_w, i);
    if(!item)  return false;

    js_w1 = cJSON_GetObjectItem(item, "w1");
    //logfile.Write("w1 is %s\n",js_w1->valuestring);
    strcpy(stjson->w1,js_w1->valuestring);
    js_w2 = cJSON_GetObjectItem(item, "w2");
    //logfile.Write("w2 is %s\n",js_w2->valuestring);
    strcpy(stjson->w2,js_w2->valuestring);
    js_w3 = cJSON_GetObjectItem(item, "w3");
    //logfile.Write("w3 is %s\n",js_w3->valuestring);
    strcpy(stjson->w3,js_w3->valuestring);
    js_w4 = cJSON_GetObjectItem(item, "w4");
    //logfile.Write("w4 is %s\n",js_w4->valuestring);
    strcpy(stjson->w4,js_w4->valuestring);
    js_w5 = cJSON_GetObjectItem(item, "w5");
    //logfile.Write("w5 is %s\n",js_w5->valuestring);
    strcpy(stjson->w5,js_w5->valuestring);
    js_w6 = cJSON_GetObjectItem(item, "w6");
    //logfile.Write("w6 is %s\n",js_w6->valuestring);
    strcpy(stjson->w6,js_w6->valuestring);
    js_w7 = cJSON_GetObjectItem(item, "w7");
    //logfile.Write("w7 is %s\n",js_w7->valuestring);
    strcpy(stjson->w7,js_w7->valuestring);
    js_w8 = cJSON_GetObjectItem(item, "w8");
    //logfile.Write("w8 is %s\n",js_w8->valuestring);
    strcpy(stjson->w8,js_w8->valuestring);
    js_w9 = cJSON_GetObjectItem(item, "w9");
    //logfile.Write("w9 is %s\n",js_w9->valuestring);
    strcpy(stjson->w9,js_w9->valuestring);
    js_w10 = cJSON_GetObjectItem(item, "w10");
    //logfile.Write("w10 is %s\n",js_w10->valuestring);
    strcpy(stjson->w10,js_w10->valuestring);
    js_w11 = cJSON_GetObjectItem(item, "w11");
   // logfile.Write("w11 is %s\n",js_w11->valuestring);   
    strcpy(stjson->w11,js_w11->valuestring);
    //logfile.Write("w11 is %s\n",stjson->w11);
    if(root) cJSON_Delete(root);
   }
 return true;
}
