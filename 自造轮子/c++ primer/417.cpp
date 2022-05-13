/* ************************************************************************
> File Name:     417.cpp
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Thu 03 Jun 2021 10:37:34 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
#include <memory>
#include<stdio.h>
#include <unistd.h>  
using namespace std;

struct destination {};
struct connection{};

connection connect(destination *pd){
    cout<<"打开连接"<<endl;
    return connection();
}

void disconnection(connection c){
    cout<<"关闭连接"<<endl;
}

void f(destination &d){
    cout<<"直接管理connection"<<endl;
    connection c = connect(&d);
    cout<<endl;
}

void end_connection(connection *p){
    disconnection(*p);
}

void f1(destination &d){
    cout<<"shared_ptr"<<endl;
    connection c=connect(&d);
  //  shared_ptr<connection> p(&c,end_connection);
    shared_ptr<connection> p(&c,[](connection* p){
            disconnection(*p);
            });
    cout<<endl;
}

int main(){
    destination d;
    f(d);
    f1(d);
    sleep(200);
    return 0;
}
