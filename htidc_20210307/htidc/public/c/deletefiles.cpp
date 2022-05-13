#include "_public.h"

void EXIT(int sig);

// 显示程序的帮助
void _help(char *argv[]);

int main(int argc,char *argv[])
{
  if ( (argc != 3) && (argc != 4) ) { _help(argv); return -1; }

  // 关闭全部的信号和输入输出
  CloseIOAndSignal();

  // 处理程序退出的信号
  signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

  char  strPathName[201];//存放外部输入的路径名
  double ddayout=0;//存放文件保留天数，单位是天，可以用小数
  memset(strPathName,0,sizeof(strPathName));

  strcpy(strPathName,argv[1]);
  ddayout=atof(argv[2]);//把字符串表示的时间转换为浮点数

  char strTimeout[21];//存放指定时间相对于当前的时间，如删除1天前文件，当前时间2020-12-29 18:00:00  则指定时间为2020-12-28 18:00:00

  LocalTime(strTimeout,"yyyy-mm-dd hh24:mi:ss",0-(int)(ddayout*24*60*60));//timetvl时间的偏移量，单位：秒，0是缺省值，表示当前时间，30表示当前时间30秒之后的时间
  
  char  strMatch[50];memset(strMatch,0,sizeof(strMatch));//用来存放匹配规则
  if(argc==3) strcpy(strMatch,"*");
  else strcpy(strMatch,argv[3]);

  CDir Dir;

   // 打开目录，读取文件，包括它的子目录
  if(Dir.OpenDir(strPathName,strMatch,10000,true,false) ==false)
   {
    printf("Dir.OpenDir(%s) failed.\n",strPathName); return -1;
   }
  
  //读取目录时，会得到文件的所有信息,特别是文件最后一次被修改的时间
 
  while(Dir.ReadDir()==true)//循环读取目录下的文件
   {
     //若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数
     if(strcmp(Dir.m_ModifyTime,strTimeout)>0) continue;
     REMOVE(Dir.m_FullFileName);//删除文件
     printf("delete %s ok.\n m_ModifyTime=%s,strTimeout=%s\n",Dir.m_FullFileName,Dir.m_ModifyTime,strTimeout);
 
   }
   
 return 0;

}

void EXIT(int sig)
{
  printf("程序退出，sig=%d\n\n",sig);

  exit(0);
}

// 显示程序的帮助
void _help(char *argv[])
{
  printf("\n");
  printf("Using:/htidc/public/bin/deletefiles pathname dayout [matchstr]\n");
  printf("Sample:/htidc/public/bin/deletefiles /data/shqx/ftp/surfdata 0.001 \"*.TXT,*.CSV\"\n\n");

  printf("本程序是数据中心的公共功能模块，用于删除指定目录下的历史文件。\n");
  printf("pathname 待清理的目录名，包括这个目录下的各级子目录。\n");
  printf("dayout   文件保留天数，单位是天，可以用小数,比如保留七天内的文件。\n");
  printf("matchstr 待清理文件名的匹配规则，这是一个可选参数，可以匹配多种类型的文件，中间用逗号分隔，最好用双引号包含起来。\n\n");
}

