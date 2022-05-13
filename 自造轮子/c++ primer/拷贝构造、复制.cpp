#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout<<"我是构造函数"<<endl;
    }
    A(const A& a){
        cout<<"我是拷贝构造函数"<<endl;
    }
    A& operator= (const A& a){
        cout<<"我是赋值操作符"<<endl;
        return *this;
    }
    ~A(){};
};

int main(){
    A a1;
    A a2=a1;//拷贝构造
    A a3(a2);//和上面等价，也是拷贝构造
    a2=a1;//赋值操作符
    return 0;
}

