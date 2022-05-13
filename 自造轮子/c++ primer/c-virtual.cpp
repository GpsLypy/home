//用C语言实现C++的继承


#include <iostream>
using namespace std;

struct A{
    virtual void fun(){
        cout<<"A::fun()"<<endl;
    }
    int a;
};

struct B:public A{
    virtual void fun(){
        cout<<"B::func()"<<endl;
    }
    int b;
};


//下面是用C语言模拟C++的继承和多态

typedef void (*FUN)();//定义一个函数指针来实现对成员函数的继承
struct _A{//父类
    FUN _fun;//由于C语言中结构体不能包含函数，故只能用函数指针在外面实现
    int a;
};

struct _B{//子类
    _A _a_;//在子类中定义一个基类的对象即可实现对父类的继承
    int _b;
};

void _fA(){
    printf("_A:_fun()\n");
}

void _fB(){
    printf("_B:_fun()\n");
}

void test(){
    //C++
    A a;
    B b;

    A* p1=&a;
    p1->fun();
    p1=&b;
    p1->fun();
    
    //C
    _A _a;
    _B _b;

    _a._fun=_fA;
    _b._a_._fun=_fB;

    _A* p2=& _a;
    p2->_fun();

    p2=(_A*)& _b;
    p2->_fun();
}
int main(){
    test();
    return 0;
}