#include <iostream>
#include <stdexcept>
using namespace std;

istream& f(istream& in){
    int v;
    while(in>>v,!in.eof()){
        if(in.bad()) throw runtime_error("IO 流错误");//反生系统级错误
        if(in.fail()){//发生可恢复错误
            cerr<<"数据错误，请重试："<<endl;
            in.clear();//清除所有错误标志位，恢复cin，使其恢复有效状态
            in.ignore(100,'\n');
            continue;
        }
        cout<<v<<endl;
    }
    in.clear();
    return in;
}

static int res=0;

int* func(){
    static int count=100;
    cout<<count<<endl;
    return &count;
}

int a=66;
int main(){
    cout<<"请输入一些整数，按Ctrl+Z结束"<<endl;
    //f(cin);
    cout<<res<<endl;
    int *temp=func();
    cout<<*temp<<endl;
    const int& b=a;
    cout<<b<<endl;
    a=1000;
    //b=2000;
    cout<<b<<endl;
    cout<<a<<endl;

    const int b1=a;
    //b1=200;
    cout<<b1<<endl;

    int* p=nullptr;
    cout<<p<<endl;
    cout<<*p<<endl;
    return 0;
}