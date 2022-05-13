#include <iostream>
#include <cstring>
using namespace std;
int main(){

    //测试sizeof
    char str[]="hello";
    cout<<sizeof(str)<<endl;//输出6，因为结尾有'\0'，所以会占用6个字节存储空间
    cout<<strlen(str)<<endl;//该字符串的长度为5


    //测试二维数组
    int a[3][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cout<<a[1][4]<<endl;//输出10

    //
    int i=0;
    int b[]={3,6,4,8,5,6};
    do{
        b[i]-=3;
    }while(b[i++]<4);


    for(i=0;i<6;i++){
        printf("%d",b[i]);
    }


    return 0;
}