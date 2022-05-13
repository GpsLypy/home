#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
//产生指定范围内的随机整数的方法：模数+加法的方法
//产生[m,n]范围内的随机数num，可用int num = rand() % (n-m+1)+m;
#define D(x) 2*x+3
int main(){
    int i,n,max,min;
    srand((unsigned) time(NULL));
    
    printf("请输入你想要产生的随机数个数:\n");
    scanf("%d",&n);

    printf("请输入你想要产生随机数的上界：\n");
    scanf("%d",&max);

    printf("请输入你想要产生随机数的下届：\n");
    scanf("%d",&min);

    for(i=1;i<=n;i++){
        printf("随机数=%d\n",rand()%(max-min+1)+min);
    }

    printf("float 存储最大字节数：%lu\n",sizeof(float));//4
    printf("float最小值：%E\n",FLT_MIN);//1.175494E-38
    printf("float最大值：%E\n",FLT_MAX);//3.402823E+38
    printf("精度值：%d\n",FLT_DIG);//6

    int ii=1,j=2;
    printf("%d\n",D(ii+j));//7
    return 0;
}