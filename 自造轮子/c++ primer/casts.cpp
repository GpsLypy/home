#include <bits/stdc++.h>
using namespace std;

class Base{
public:
    Base():b(1){}
    virtual void fun(){};
    int b;
};

class Son:public Base{
public:
    Son():d(2){}
    int d;
};

int main(){
    int n=97;
    int* p=&n;
    /*测试reinterpret_cast->用于类型之间的强制转换,意图执行低级转型*/
    char* c=reinterpret_cast<char*>(p);
    char* c2=(char*)(p);
    cout<<"reinterpret_cast输出: "<<*c<<endl;
    cout<<"c2输出: "<<*c2<<endl;

    /*测试const_cast->一般用于修改底层指针，去除对象的常量属性*/
    const int* p2=&n;
    int* p3=const_cast<int*>(p2);
    *p3=100;
    cout<<"const_cast: "<<*p3<<endl;


    Base* b1=new Son;
    Base* b2=new Base;
    /*测试static_cast->一般用于基类和派生类之间指针或引用的转换*/
    Son* s1=static_cast<Son*>(b1);//同类型转换
    Son* s2=static_cast<Son*>(b2);//static_cast下行转换是不安全的
    cout<<"static_cast输出："<<endl;
    cout<<s1->d<<endl;//2
    cout<<s2->d<<endl;//下行转换，原先父对象没有d成员，输出垃圾值0


    /*测试dynamic_cast*/
    Son* s3=dynamic_cast<Son*>(b1);//同类型之间的转换
    Son* s4=dynamic_cast<Son*>(b2);//安全向下转型
    cout<<"dynamic_cast输出："<<endl;
    cout<<s3->d<<endl;//2
    if(s4==nullptr){
        cout<<"s4指针为nullptr"<<endl;
    }else cout<<s4->d<<endl;
    
    return 0;
}