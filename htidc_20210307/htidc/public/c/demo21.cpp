//此程序用于演示多进程下日志功能

#include "_public.h"

int main(int argc,char *argv[])
{

 CLogFile logfile;
 
 logfile.Open("/tmp/demo21.log","w",false,true);

 for(int ii=0;ii<10;ii++)
  {
    if(fork()>0) continue;
    
    for(int jj=0;jj<1000;jj++)
     {
      logfile.Write("pid=%10d,jj=%10d\n",getpid(),jj); 
     }
   
    exit(0);

  }
return 0;

}
