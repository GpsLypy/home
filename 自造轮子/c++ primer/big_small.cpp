#include <iostream>
using namespace std;

union endian{
    int a;
    char ch;
};

int main(){
    {
        int a=0x123456;//十六进制表示的整数 二进制:0001 0010 0011 0100
        cout<<a<<endl;//4660
        char c=(char)(a);
        if(c==0x12){
            cout<<"big endian"<<endl;
        }else if(c==0x34){
            cout<<"little endian"<<endl;
        }
        cout<<c<<endl;
        
    }

    {
        endian value;
        value.a=0x1234;
        cout<<value.a<<endl;
        if(value.ch==0x12){
            cout<<"big endian"<<endl;
        }
        else if(value.ch==0x34){
            cout<<"little endian"<<endl;
        }
    }
    return 0;
}