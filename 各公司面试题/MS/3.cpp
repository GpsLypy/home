#include <iostream>
using namespace std;


void swap(int* p1,int* p2){
    int *p;//这里没有指定指针的指向，可能会造成非法访问内存
    *p=*p1;
    *p1=*p2;
    *p2=*p1;
}

int main(){
    /*
    int m=10;
    int n=20;
    swap(&m,&n);
    printf("%d\n",m);
    */
    
    //int aa=0x4080;
    //char cc=0x40a0;
    //栈向着内存地址减小的方向增长
    int a[10],*pa;
    char c[10],*pc;
    pa=a;
    pc=c;
    printf("0x%x 0x%x\n",a,c);
    printf("0x%x 0x%x\n",++pa,++pc);

    char ch;
    ch=0x123;
    cout<<abs(ch)<<endl;
    return 0;
}