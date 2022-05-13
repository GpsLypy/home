#include <iostream>
using namespace std;

int main(){
    char a[]={'c','+','+'};//自动加结束符
    char b[]={'c','+','+','\0'};//手动加结束符
    char c[]="c++";
    char d[]="c++\0";


    cout<<"a.size()="<<sizeof(a)<<endl;//3
    cout<<"b.size()="<<sizeof(b)<<endl;//4
    cout<<"c.size()="<<sizeof(c)<<endl;//4
    cout<<"d.size()="<<sizeof(d)<<endl;//5


    //HTTP2支持分帧，将数据包分成多个帧发送

    /*
    C语言规定，数组名代表数组的首地址，也就是第0号元素的地址。所以a==&a[0]。

    但对数组名取地址时却要注意了，在理解“对数组名取地址”这一表达式的含义时一定要记住：
    数组名是“数组”这种变量的变量名。这样，&a就好理解了，它取的是“数组”这种变量的地址

    &a+1自然也就要跨过整个数组，所有元素长度总和，这么长的一个长度。例如:int a[10]，
    那么&a+1就要跨过10个int的长度 
    */

    int aa[]={1,2,3,4,5};
    cout<<sizeof(int)<<endl;//4

    cout<<aa<<endl;//数组名就是整个数组地址，也是数组中第一个元素地址即aa[0]的地址：0x7ffe7704d760
    cout<<*aa<<endl;//1

    cout<<aa+16<<endl;//a[4]的字节地址
    cout<<*(aa+4)<<endl;//访问a[4]的值

}