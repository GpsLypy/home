/* ************************************************************************
> File Name:     mutex.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sun 20 Jun 2021 02:49:04 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <thread>
#include <mutex>
using namespace std;

class A{
public:
    void insertMsg(){
        for(int ii=0;ii<100;ii++){
            cout<<"插入一条消息"<<ii<<endl;
          //  sleep(1);
            my_mutex1.lock();//语句1
            my_mutex2.lock();//语句2
            Msg.push_back(ii);
            my_mutex2.unlock();
            my_mutex1.unlock();
        }
    }

    void readMsg(){
        int MsgCom;
        for(int ii=0;ii<100;ii++){
            MsgCom=MsgLULProc(ii);
            if(MsgLULProc(MsgCom)){
                cout<<"消息已读取"<<MsgCom<<endl;
            }
            else{
                cout<<"消息为空"<<endl;
            }
        }
    }

    bool MsgLULProc(int &command){
        int curMsg;
        //sleep(1);
        my_mutex2.lock();//语句3
        my_mutex1.lock();//语句4
        if(!Msg.empty()){
            command=Msg.front();
            Msg.pop_front();

            my_mutex1.unlock();
            my_mutex2.unlock();
            return true;
        }
        my_mutex1.unlock();
        my_mutex2.unlock();
        return false;
    }
private:
    list<int>Msg;//消息变量
    mutex my_mutex1;//互斥量对象1
    mutex my_mutex2;//互斥量对象2
};

int main(){
    A a;
    //创建一个插入消息线程对象
    thread insertTd(&A::insertMsg,&a);//传引用保证是同一个对象
    //创建一个读消息线程
    thread readTd(&A::readMsg,&a);

    insertTd.join();
    readTd.join();
    return 0;
}
