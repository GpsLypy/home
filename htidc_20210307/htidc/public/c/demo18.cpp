//
// ��������ʾCftp�ͻ����࣬����ftpЭ��ӷ������ϻ�ȡ�ļ�
//

#include "_ftp.h"

int main(int argc,char *argv[])
{
  Cftp ftp;

  // ��¼Զ��FTP������
  if (ftp.login("49.232.185.49","li49","li498988598",FTPLIB_PASSIVE) == false)
  {
    printf("ftp.login() failed.\n"); return -1;
  }
/*
  ftp.chdir("/home/li49/qxidc/data/ftp/surfdata");
  ftp.nlist("/home/li49/qxidc/data/ftp/surfdata","/tmp/tmp.list");
  ftp.nlist("","/tmp/tmp.list1");
  ftp.nlist(".","/tmp/tmp.list2");
  ftp.nlist("*","/tmp/tmp.list3");

  return 0;
*/
  ftp.put("/home/li49/qxidc/data/ftp/surfdata/SURF_ZH_20190808043801_11644.txt","/tmp/SURF_ZH_20190808043801_11644.txt",true);

  // �ı䱾��Ŀ¼
  chdir("/tmp");

  // ����ftp���������ļ���ŵ�Ŀ¼
  if (ftp.chdir("/home/li49/qxidc/data/ftp/surfdata") == false)
  {
    printf("ftp.chdir() failed.\n"); return -1;
  }

  // ��ȡ�Է�Ŀ¼�ļ����б������"/tmp/ftp.list"�ļ���
  if (ftp.nlist("*.txt","/tmp/ftp.list")== false)
  {
    printf("ftp.nlist() failed.\n"); return -1;
  }

  CFile File;

  File.Open("/tmp/ftp.list","r");

  char strFileName[101];

  // ���ж�ȡ�ļ������ݣ������ļ�get������
  while (true)
  {
    // ��ftp.list�ļ��ж�ȡһ�����ݣ����ļ�����
    memset(strFileName,0,sizeof(strFileName));
    if (File.Fgets(strFileName,100) == false) break;
    strFileName[strlen(strFileName)-1]=0;//123? �򳤶�Ϊ4 �����һλΪ0
    printf("get %s ...",strFileName);

    // ��Զ��ȡ�ļ�
    if (ftp.get(strFileName,strFileName)==false)
    {
      printf("ftp.get(%s) failed.\n",strFileName); break;
    }
    
    printf("ok.\n");
    ftp.ftpdelete(strFileName);

  }

  File.Close();

  ftp.logout();

  return 0;
}


