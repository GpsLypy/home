#include <iostream>
using namespace std;

class CString{
public:
    CString()=default;
    CString(const char* pstr):_str(pstr){}
    //void* operator new()=delete;//体面删除运算符操作

    ~CString(){}
private:
    string _str;
};

//带有默认构造函数的类成员对象，会自动生成默认构造函数
class A{
public:
    CString a;
    int b;
    ~A(){cout<<"A::~A()"<<endl;}
};

//带有默认构造函数的基类也会自动生成默认构造函数
class B:public CString{
public:
    int a;
    ~B(){}
};
int main(){
    A aaa;
    B bbb;
    A* pa=new A();
    cout<<aaa.b<<endl;
    cout<<bbb.a<<endl;
    auto a=new CString();
    cout<<"hello world"<<endl;
    return 0;
}