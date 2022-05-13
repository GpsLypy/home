#include <iostream>
using namespace std;

int main(){

    int a[5]={1,2,3,4,5};
    int* ptr=(int*)(&a+1);
    cout<<*(a+1)<<endl;
    cout<<*(ptr-1)<<endl;

    return 0;
}

/*
 *(a+1)其实很简单就是指a[1],输出为2.

 问题关键就在于第二个点，*(ptr-1)输出为多少？

 解释如下:
 &a+1不是首地址+1，系统会认为加了一个整个a数组，偏移了整个数组a的大小（也就是5个int的大小）。
 所以int*ptr=(int*)(&a+1);其实ptr实际是&(a[5]),也就是a+5.

 原因为何呢？

 &a是数组指针，其类型为int(*)[5];

 而指针加1要根据指针类型加上一定的值，不同类型的指针+1之后增加的大小不同，a是长度为5的int数组指针，
 所以要加5*sizeof(int)，所以ptr实际是a[5],但是ptr与（&a+1）类型是不一样的，
 这点非常重要，所以ptr-1只会减去sizeof(int*),a，&a的地址是一样的，但意思就不一样了，
 a是数组首地址，也就是a[0]的地址，
 &a是对象（数组）首地址，a+1是数组下一元素的地址，即a[1],&a+1是下一个对象的地址，即a[5]。
*/