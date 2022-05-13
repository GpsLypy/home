#include <iostream>
#include <string.h>
using  namespace std;

class E{
public:
    virtual void func(int i=0){
        std::cout<<"E::func()\t"<<i<<"\n";
    }

    void func1(){
        cout<<"E::func1()\t"<<"\n";
    }
    int c=10;
};

class F:public E{
public:
    virtual void func(int i=1){
        std::cout<<"F::func()\t"<<i<<"\n";
    }
    void func1(){
        cout<<"F::func1()\t"<<"\n";
    }
};

class D:public E{
public:
    int func(){
        cout<<"D::："<<c<<endl;
    }
};

class W{
public:
    W(){
        cout<<"构造函数"<<endl;
        memset(this,0,sizeof(*this));
    }
    int func(){
        cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<endl;
    }
private:
    int a;
    char b;
    int c;
};

void test2(){
    F* pf=new F();
    E* pe=pf;
    pf->func();//1
    pe->func();//0 ！！！
    pe->func1();
    D* pd=new D();
    pd->func();
}
int main(){
    //test2();
    W object;
    object.func();
    return 0;
}


