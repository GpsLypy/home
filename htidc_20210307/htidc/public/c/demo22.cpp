#include "_public.h"


CLogFile logfile;

void *pthmain(void *arg)
{
 for(int jj=0;jj<1000;jj++)
  {
   logfile.Write("pid=%10d jj=%10d\n",getpid(),jj);
  }

 pthread_exit(0);

}
int main(int argc,char *argv[])
{
  logfile.Open("/tmp/demo22.log","w",false,false);
  
  for(int ii=0;ii<20;ii++)
   {
    pthread_t pth;
    pthread_create(&pth,NULL,pthmain,NULL);  
   }

sleep(60);
return 0;
}

