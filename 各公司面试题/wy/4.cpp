#include <bits/stdc++.h>
using namespace std;


int func(int a,int b);
int func(int n);


int func(int c,int d){
  cout<<"111"<<endl;
}

int func(int n){
  if(n<2) return n;
  return func(n-1)+func(n-2);
}


typedef struct mystruct{
  std::map<int,int> m;
  int b;
}Tmy;



int main(){
  
  enum color{blue,white,red,black};
  enum color cc=red;
  cout<<"cc="<<cc;//值为2

  char ccc; ccc=97;//ok
  char str[7]={'s','t','r','i','n','g'};//ok
  char pc[]={'a','b','c','d','\0'};//ok
    
  // char str[10];
  //str="string";//no

  //char *pctr="abcd"; //deprecated conversion from string constant to ‘char*:语法上可以，但不建议这样转换
  //cout<<*pctr<<endl;

  //char pcc[4]="abcd";//too long
  //char ppcc[]='abcd';//初始化器无法确定“ppcc”的大小
   
   
  //int a=1,b=2,c=3,d=4;
  //int res=a<b?a:c<d?c:d;
  //cout<<res<<endl;//值为1

  cout<<func(7)<<endl;

  FILE* fp;
  int i,a[6]={1,2,3,4,5,6};
  fp=fopen("d2.dat","w+");
  for(i=0;i<6;i++){
    fprintf(fp,"%d\n",a[i]);
  }

  rewind(fp);
  for(i=0;i<6;i++){
    fscanf(fp,"%d",&a[5-i]);
  }

  fclose(fp);

  for(i=0;i<6;i++){//654321
    printf("%d",a[i]);
  }

  struct test{
    int size;
    char jd[0];
  };

  test t;
  cout<<sizeof(t)<<endl;//4


  //Tmy s;
  //s.b=0;//ok

  //Tmy s={0};//!wrong

  Tmy s;
  memset(&s,0,sizeof(s));//ok
  //memset(s,0,sizeof(s));//no


  static int hot=200;
  int &rad=hot;
  hot=hot+100;
  cout<<rad<<endl;//300
  return 0;


}
