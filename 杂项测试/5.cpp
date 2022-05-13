#include <iostream>
using namespace std;
#include<stdio.h>

int test(){
    int a[2][4]={{3,6,9,12},{15,18,21,24}};
    cout<<*(*(a+1)+2)<<endl;//21
    return a[1][1]+*(a[1]+2)+*(*(a+1)+2);//18+21+21
}


int main()
{   
    /*测试一：
    //二维数组名a是数组第一行的指针，它指向的是一整行
    //*a才是a[0][0]的地址,是一个元素的地址
    int a[2][3]={1,2,3,4,5,6},(*p)[3];

    p=a;

    printf("%d %d %d\n",p,a,*a);//第一行的地址和第一个元素首地址肯定相同

    return 0;
    */

    //测试二：
    int a[2][3]={1,2,3,4,5,6},(*p)[3];

    p=a;

    printf("%d %d\n",(p+1),*(a+1));//p为第二行的地址，*(a+1)为第二行第一个元素的地址a[1][0]的地址
    printf("%d %d\n",*(*p+1),**(a+1));//a[0][1]的值2和a[1][0]的值4
    return 0;

    //结论：**a才表示a[0][0],*a表示a[0][0]的地址，a表示第一行的地址

    //测试三：
    int res=test();
    cout<<res<<endl;//60
    return 0;
}






