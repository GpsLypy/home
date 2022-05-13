#include <iostream>
#include <vector>
using namespace std;

static int a=1;
void fun1(){
    a=2;
}
void fun2(){
    int a=3;
}

void fun3(){
    static int a=3;
}
int main(){
    cout<<a<<endl;//1
    fun1();
    cout<<a<<endl;//2
    fun2();
    cout<<a<<endl;//2
    fun3();
    cout<<a<<endl;//2
}