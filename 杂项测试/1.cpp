#include <iostream>
using namespace std;

//问题一：为什么cout和printf输出结果不一样
int main(){
    double x,y;
    x=2;
    y=x+3/2;

    cout<<x<<endl;
    cout<<y<<endl;
    printf("%f\n",y);
}