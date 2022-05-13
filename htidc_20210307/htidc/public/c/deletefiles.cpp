#include "_public.h"

void EXIT(int sig);

// ��ʾ����İ���
void _help(char *argv[]);

int main(int argc,char *argv[])
{
  if ( (argc != 3) && (argc != 4) ) { _help(argv); return -1; }

  // �ر�ȫ�����źź��������
  CloseIOAndSignal();

  // ��������˳����ź�
  signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

  char  strPathName[201];//����ⲿ�����·����
  double ddayout=0;//����ļ�������������λ���죬������С��
  memset(strPathName,0,sizeof(strPathName));

  strcpy(strPathName,argv[1]);
  ddayout=atof(argv[2]);//���ַ�����ʾ��ʱ��ת��Ϊ������

  char strTimeout[21];//���ָ��ʱ������ڵ�ǰ��ʱ�䣬��ɾ��1��ǰ�ļ�����ǰʱ��2020-12-29 18:00:00  ��ָ��ʱ��Ϊ2020-12-28 18:00:00

  LocalTime(strTimeout,"yyyy-mm-dd hh24:mi:ss",0-(int)(ddayout*24*60*60));//timetvlʱ���ƫ��������λ���룬0��ȱʡֵ����ʾ��ǰʱ�䣬30��ʾ��ǰʱ��30��֮���ʱ��
  
  char  strMatch[50];memset(strMatch,0,sizeof(strMatch));//�������ƥ�����
  if(argc==3) strcpy(strMatch,"*");
  else strcpy(strMatch,argv[3]);

  CDir Dir;

   // ��Ŀ¼����ȡ�ļ�������������Ŀ¼
  if(Dir.OpenDir(strPathName,strMatch,10000,true,false) ==false)
   {
    printf("Dir.OpenDir(%s) failed.\n",strPathName); return -1;
   }
  
  //��ȡĿ¼ʱ����õ��ļ���������Ϣ,�ر����ļ����һ�α��޸ĵ�ʱ��
 
  while(Dir.ReadDir()==true)//ѭ����ȡĿ¼�µ��ļ�
   {
     //��str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�����
     if(strcmp(Dir.m_ModifyTime,strTimeout)>0) continue;
     REMOVE(Dir.m_FullFileName);//ɾ���ļ�
     printf("delete %s ok.\n m_ModifyTime=%s,strTimeout=%s\n",Dir.m_FullFileName,Dir.m_ModifyTime,strTimeout);
 
   }
   
 return 0;

}

void EXIT(int sig)
{
  printf("�����˳���sig=%d\n\n",sig);

  exit(0);
}

// ��ʾ����İ���
void _help(char *argv[])
{
  printf("\n");
  printf("Using:/htidc/public/bin/deletefiles pathname dayout [matchstr]\n");
  printf("Sample:/htidc/public/bin/deletefiles /data/shqx/ftp/surfdata 0.001 \"*.TXT,*.CSV\"\n\n");

  printf("���������������ĵĹ�������ģ�飬����ɾ��ָ��Ŀ¼�µ���ʷ�ļ���\n");
  printf("pathname �������Ŀ¼�����������Ŀ¼�µĸ�����Ŀ¼��\n");
  printf("dayout   �ļ�������������λ���죬������С��,���籣�������ڵ��ļ���\n");
  printf("matchstr �������ļ�����ƥ���������һ����ѡ����������ƥ��������͵��ļ����м��ö��ŷָ��������˫���Ű���������\n\n");
}

