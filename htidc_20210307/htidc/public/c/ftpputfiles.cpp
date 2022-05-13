#include "_public.h"
#include "_ftp.h"

struct st_arg
{
  char host[51];         //Զ�̷�������IP�Ͷ˿�
  int  mode;             //����ģʽ��1-����ģʽ��2-����ģʽ��ȱʡ���ñ�ģʽ��
  char username[31];     //Զ�̷�����FTP���û���
  char password[31];     //Զ�̷�����FTP������
  char localpath[301];   //�����ļ���ŵ�Ŀ¼
  char remotepath[301];  //Զ�̷���������ļ���Ŀ¼
  char matchname[301];   //�������ļ�ƥ����ļ��������ô�дƥ��
  int  ptype;            //��ƥ����ļ����ᱻ���ͣ����ֶξ��������þ�ȷ����������*ƥ��ȫ�����ļ�
  char localpathbak[301];//�ļ����ͳɹ��󣬱����ļ��Ĵ���ʽ��1-ʲôҲ������2-ɾ����3-���ݣ����Ϊ3,��Ҫָ�����ݵ�Ŀ¼
  char okfilename[301];  //�ѷ��ͳɹ��ļ����嵥���˲���ֻ�е�ptype=1ʱ��Ч
  int  timetvl;          //����ʱ��������λ���룬�������10
} starg;

void EXIT(int sig);

Cftp ftp;//ftp��������
CLogFile logfile;//��־�ļ���������

vector<struct st_fileinfo> vlistfile,vlistfile1;
vector<struct st_fileinfo> vokfilename,vokfilename1;

// ��ʾ����İ���
void _help(char *argv[]);

// �������ҵ������������
bool _ftpputfiles();

// ��localpathĿ¼�µ��ļ����ص�vlistfile������
bool LoadListFile();

// ��okfilename�ļ����ݼ��ص�vokfilename������
bool LoadOKFileName();

// ��vlistfile�����е��ļ���vokfilename�������ļ��Աȣ��õ���������
// һ����vlistfile�д��ڣ����Ѿ����ͳɹ����ļ�vokfilename1
// ������vlistfile�д��ڣ����ļ�����Ҫ���·��͵��ļ�vlistfile1
bool CompVector();

// ��vokfilename1�����е�������д��okfilename�ļ��У�����֮ǰ�ľ�okfilename�ļ�
bool WriteToOKFileName();

// ���ptype==1���ѷ��ͳɹ����ļ���¼׷�ӵ�okfilename�ļ���
bool AppendToOKFileName(struct st_fileinfo *stfileinfo);

// ��xml����������starg�ṹ��
bool _xmltoarg(char *strxmlbuffer);

int main(int argc,char *argv[])
{
 if (argc!=3) { _help(argv); return -1; }
 // �ر�ȫ�����źź��������
 CloseIOAndSignal();
 
 // ��������˳����ź�
 signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

 if (logfile.Open(argv[1],"a+")==false)
  {
    printf("����־�ļ�ʧ�ܣ�%s����\n",argv[1]); return -1;
  }

 // ��xml����������starg�ṹ��
 if (_xmltoarg(argv[2])==false) return -1;
 
 while(true)
  { 
    //��¼FTP������
    if(ftp.login(starg.host,starg.username,starg.password,starg.mode)==false)
     { 
      logfile.Write("ftp.login(%s,%s,%s) failed.\n",starg.host,starg.username,starg.password); sleep(10); continue;
     }
    
    // logfile.Write("ftp.login ok.\n");

    _ftpputfiles();//��Զ����������ļ�

    ftp.logout();//����
   
    sleep(starg.timetvl);
 

  }

 return 0;

}

void EXIT(int sig)
{
  logfile.Write("�����˳���sig=%d\n\n",sig);

  exit(0);
}

// �������ҵ������������
bool _ftpputfiles()
{
  // ����Զ�̷������ϵ�Ŀ¼�������ķ���ֵ,����Է�����Ȩ�ޣ����Դ����ɹ���û��Ȩ�ޣ��Է�Ӧ���ǽ������˵�
  ftp.mkdir(starg.remotepath);

  // ��localpathĿ¼�µ��ļ����ص�vlistfile������
  if (LoadListFile()==false) 
  {
    logfile.Write("LoadListFile() failed.\n"); return false;
  }

  if (starg.ptype==1)//���Ҫ�󱾵��ļ��Ĵ���ʽΪʲôҲ������Ҳ���ǡ������������䣬�������Ѿ����͹����ļ�
  {
    // ����okfilename�ļ��е����ݵ�����vokfilename��
    LoadOKFileName();

    // ��vlistfile�����е��ļ���vokfilename�������ļ��Աȣ��õ���������
    // һ����vlistfile�д��ڣ����Ѿ����ͳɹ����ļ�vokfilename1
    // ������vlistfile�д��ڣ����ļ�����Ҫ���·��͵��ļ�vlistfile1
    CompVector();

    // ��vokfilename1�����е�������д��okfilename�ļ��У�����֮ǰ�ľ�okfilename�ļ�
    WriteToOKFileName();
    
    // ��vlistfile1�����е����ݸ��Ƶ�vlistfile������
    vlistfile.clear(); vlistfile.swap(vlistfile1);
  }
 
    
  // �ѿͻ��˵����ļ����ѸĶ�������ļ����͸������
  for (int ii=0;ii<vlistfile.size();ii++)
  {
    char strremotefilename[301],strlocalfilename[301];
    SNPRINTF(strlocalfilename,301,300,"%s/%s",starg.localpath,vlistfile[ii].filename);
    SNPRINTF(strremotefilename,301,300,"%s/%s",starg.remotepath,vlistfile[ii].filename);

    logfile.Write("put %s ...",strlocalfilename);

    // �����ļ�
    if (ftp.put(strlocalfilename,strremotefilename,true)==false) 
    {
      logfile.WriteEx("failed.\n"); break;
    }

    logfile.WriteEx("ok.\n");
    
    // ɾ���ļ�
    if (starg.ptype==2) REMOVE(strlocalfilename);

    // ת�浽����Ŀ¼
    if (starg.ptype==3)
     {
       char strfilenamebak[301];//������ű���Ŀ¼�����ļ�
      
       memset(strfilenamebak,0,sizeof(strfilenamebak));
      
       sprintf(strfilenamebak,"%s/%s",starg.localpathbak,vlistfile[ii].filename);
      
       //�ѱ��ص��ļ����ݵ�����Ŀ¼������Ի����
       if (RENAME(strlocalfilename,strfilenamebak)==false)
        {
         logfile.Write("RENAME %s to %s failed.\n",strlocalfilename,strfilenamebak); return false;
        }
     }
  
    // ���ptype==1���ѷ��ͳɹ����ļ���¼׷�ӵ�okfilename�ļ���
    if (starg.ptype==1) AppendToOKFileName(&vlistfile[ii]);
  }
 
  return true;
}



// ��localpathĿ¼�µ��ļ����ص�vlistfile������
bool LoadListFile()
{
  vlistfile.clear();

  CDir Dir;

  // ��������Ŀ¼
  // ע�⣬���Ŀ¼�µ����ļ�������50000�����������ļ����ܽ�������
  if (Dir.OpenDir(starg.localpath,starg.matchname,50000,false,false)==false)
  {
    logfile.Write("Dir.OpenDir(%s) ʧ�ܡ�\n",starg.localpath); return false;
  }

  struct st_fileinfo stfileinfo;

  while (true)
  {
    memset(&stfileinfo,0,sizeof(struct st_fileinfo));

    if (Dir.ReadDir()==false) break;

    strcpy(stfileinfo.filename,Dir.m_FileName);  // �ļ�����������Ŀ¼��
    strcpy(stfileinfo.mtime,Dir.m_ModifyTime);
    stfileinfo.filesize=Dir.m_FileSize;

    vlistfile.push_back(stfileinfo);

    // logfile.Write("vlistfile filename=%s,mtime=%s\n",stfileinfo.filename,stfileinfo.mtime);
  }

  return true;
}



// ��okfilename�ļ����ݼ��ص�vokfilename������
bool LoadOKFileName()
{
  vokfilename.clear();

  CFile File;

  // ע�⣺��������ǵ�һ�η��ͣ�okfilename�ǲ����ڵģ������Ǵ�������Ҳ����true��
  if (File.Open(starg.okfilename,"r") == false) return true;

  struct st_fileinfo stfileinfo;

  char strbuffer[301];

  while (true)
  {
    memset(&stfileinfo,0,sizeof(struct st_fileinfo));

    if (File.Fgets(strbuffer,300,true)==false) break;

    GetXMLBuffer(strbuffer,"filename",stfileinfo.filename,300);
    GetXMLBuffer(strbuffer,"mtime",stfileinfo.mtime,20);

    vokfilename.push_back(stfileinfo);

    // logfile.Write("vokfilename filename=%s,mtime=%s\n",stfileinfo.filename,stfileinfo.mtime);
  }

  return true;
}


// ��vlistfile�����е��ļ���vokfilename�������ļ��Աȣ��õ���������
// һ����vlistfile�д��ڣ����Ѿ����ͳɹ����ļ�vokfilename1
// ������vlistfile�д��ڣ����ļ�����Ҫ���·��͵��ļ�vlistfile1
bool CompVector()
{
  vokfilename1.clear();  vlistfile1.clear();

  for (int ii=0;ii<vlistfile.size();ii++)
  {
    int jj=0;
    for (jj=0;jj<vokfilename.size();jj++)
    {
      if ( (strcmp(vlistfile[ii].filename,vokfilename[jj].filename)==0) &&
           (strcmp(vlistfile[ii].mtime,vokfilename[jj].mtime)==0) )
      {
        vokfilename1.push_back(vlistfile[ii]); break;
      }
    }

    if (jj==vokfilename.size())
    {
      vlistfile1.push_back(vlistfile[ii]);
    }
  }
}

// ��vokfilename1�����е�������д��okfilename�ļ��У�����֮ǰ�ľ�okfilename�ļ�
bool WriteToOKFileName()
{
  CFile File;

  // ע�⣬���ļ���Ҫ���û������
  if (File.Open(starg.okfilename,"w",false) == false)
  {
    logfile.Write("File.Open(%s) failed.\n",starg.okfilename); return false;
  }

  for (int ii=0;ii<vokfilename1.size();ii++)
  {
    File.Fprintf("<filename>%s</filename><mtime>%s</mtime>\n",vokfilename1[ii].filename,vokfilename1[ii].mtime);
  }

  return true;
}


// ���ptype==1���ѷ��ͳɹ����ļ���¼׷�ӵ�okfilename�ļ���
bool AppendToOKFileName(struct st_fileinfo *stfileinfo)
{
  CFile File;

  // ע�⣬���ļ���Ҫ���û������
  if (File.Open(starg.okfilename,"a",false) == false)
  {
    logfile.Write("File.Open(%s) failed.\n",starg.okfilename); return false;
  }

  File.Fprintf("<filename>%s</filename><mtime>%s</mtime>\n",stfileinfo->filename,stfileinfo->mtime);

  return true;
}



// ��ʾ����İ���
void _help(char *argv[])
{
  printf("\n");
  printf("Using:/htidc/public/bin/ftpputfiles logfilename xmlbuffer\n\n");

  printf("Sample:/htidc/public/bin/ftpputfiles /log/shqx/ftpputfiles_surfdata.log \"<host>49.232.185.49:21</host><port>21</port><mode>1</mode><username>li49</username><password>li498988598</password><localpath>/data/shqx/ftp/surfdata</localpath><remotepath>/home/li49/data</remotepath><matchname>SURF_*.TXT,*.DAT</matchname><ptype>1</ptype><localpathbak></localpathbak><okfilename>/data/shqx/ftplist/ftpputfiles_surfdata.xml</okfilename><timetvl>30</timetvl>\"\n\n\n");

  printf("���������������ĵĹ�������ģ�飬���ڰѱ���Ŀ¼�е��ļ����͵�Զ�̵�FTP��������\n");
  printf("logfilename�Ǳ��������е���־�ļ���\n");
  printf("xmlbufferΪ�ļ�����Ĳ��������£�\n");
  printf("<host>118.89.50.198:21</host> Զ�̷�������IP�Ͷ˿ڡ�\n");
  printf("<mode>1</mode> ����ģʽ��1-����ģʽ��2-����ģʽ��ȱʡ���ñ�ģʽ��\n");
  printf("<username>wucz</username> Զ�̷�����FTP���û�����\n");
  printf("<password>test1234TEST</password> Զ�̷�����FTP�����롣\n");
  printf("<localpath>/tmp/ftpput</localpath> �����ļ���ŵ�Ŀ¼��\n");
  printf("<remotepath>/tmp/gzrad</remotepath> Զ�̷���������ļ���Ŀ¼��\n");
  printf("<matchname>*.GIF</matchname> �������ļ�ƥ����ļ��������ô�дƥ�䣬"\
         "��ƥ����ļ����ᱻ���ͣ����ֶξ��������þ�ȷ����������*ƥ��ȫ�����ļ���\n");
  printf("<ptype>1</ptype> �ļ����ͳɹ��󣬱����ļ��Ĵ���ʽ��1-ʲôҲ������2-ɾ����3-���ݣ����Ϊ3����Ҫָ�����ݵ�Ŀ¼��\n");
  printf("<localpathbak>/tmp/gzradbak</localpathbak> �ļ����ͳɹ��󣬱����ļ��ı���Ŀ¼���˲���ֻ�е�ptype=3ʱ����Ч��\n");
  printf("<okfilename>/data/shqx/ftplist/ftpputfiles_surfdata.xml</okfilename> �ѷ��ͳɹ��ļ����嵥���˲���ֻ�е�ptype=1ʱ��Ч��\n");
  printf("<timetvl>30</timetvl> ����ʱ��������λ���룬�������10��\n\n");
}

// ��xml����������starg�ṹ��
bool _xmltoarg(char *strxmlbuffer)
{
  memset(&starg,0,sizeof(struct st_arg));

  GetXMLBuffer(strxmlbuffer,"host",starg.host);
  if (strlen(starg.host)==0) { logfile.Write("host is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"mode",&starg.mode);
  if ( (starg.mode!=1) && (starg.mode!=2) ) starg.mode=1;

  GetXMLBuffer(strxmlbuffer,"username",starg.username);
  if (strlen(starg.username)==0) { logfile.Write("username is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"password",starg.password);
  if (strlen(starg.password)==0) { logfile.Write("password is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"localpath",starg.localpath);
  if (strlen(starg.localpath)==0) { logfile.Write("localpath is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"remotepath",starg.remotepath);
  if (strlen(starg.remotepath)==0) { logfile.Write("remotepath is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"matchname",starg.matchname);
  if (strlen(starg.matchname)==0) { logfile.Write("matchname is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"ptype",&starg.ptype);
  if ( (starg.ptype!=1) && (starg.ptype!=2) && (starg.ptype!=3) ){ logfile.Write("ptype is error.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"localpathbak",starg.localpathbak);
  if ((starg.ptype==3) && (strlen(starg.localpathbak)==0)) { logfile.Write("localpathbak is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"okfilename",starg.okfilename);
  if ((starg.ptype==1) && (strlen(starg.okfilename)==0)) { logfile.Write("okfilename is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"timetvl",&starg.timetvl);
  if (starg.timetvl==0) { logfile.Write("timetvl is null.\n"); return false; }

  return true;
}






