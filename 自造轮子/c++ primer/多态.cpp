#include <iostream>
using namespace std;

class Base{
public:
    virtual void fun(){
        cout<<"Base func()"<<endl;
    }
    void func2(){
        cout<<val<<endl;
    }
private:
    int val;
};

class Son1:public Base{
public:
    virtual void fun(){
        cout<<"Son1 func()"<<endl;
    }
};

class Son2:public Base{

};

int main(){
    Base* base=new Son1;
    base->fun();
    base->func2();
    base=new Son2;
    base->fun();
    delete base;
    base=nullptr;
    return 0;
}