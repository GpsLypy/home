#include <iostream>
#include <string>
using namespace std;

std::string GetString(){
    return "abc";
}

int main(){
    /*
    const char* p=GetString().c_str();
    std::cout<<p<<std::endl;//输出"abc";
    */
    //目前此机器采用小端存储 78 56 34 12 这种方式
    int a=0x12345678;
    char* p=(char*)&a;
    printf("0x%x\n",int(*p));//78
    printf("0x%x\n",int(*(p+1)));//56
    printf("0x%x\n",int(*(p+2)));//34
    printf("0x%x\n",int(*(p+3)));//12

    return 0;
}

