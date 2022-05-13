#include <iostream>
#include <thread>//c++11新标准引入的
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mymutex;//互斥锁
condition_variable cv;//条件变量
int flag=0;

void printa(){
    unique_lock<mutex> lk(mymutex);
    int count=0;
    while(count<10){
        while(flag!=0) cv.wait(lk);//条件等待，不满足条件时线程被挂起，等待Notify唤醒
        cout<<"thread 1: A"<<endl;
        flag=1;
        cv.notify_all();
        count++;
    }
    cout<<"my thread  1 finished"<<endl;
}


void printb(){
    unique_lock<mutex> lk(mymutex);
    for(int ii=0;ii<10;ii++){
        while(flag!=1) cv.wait(lk);//条件等待，不满足条件时线程被挂起，等待Notify唤醒
        cout<<"thread 2: B"<<endl;
        flag=2;
        cv.notify_all();
    }
    cout<<"my thread  2 finished"<<endl;
}


void printc(){
    unique_lock<mutex> lk(mymutex);
    for(int ii=0;ii<10;ii++){
        while(flag!=2) cv.wait(lk);//条件等待，满足条件时线程被挂起，等待Notify唤醒
        cout<<"thread 3: C"<<endl;
        flag=0;
        cv.notify_all();
    }
    cout<<"my thread  3 finished"<<endl;
}

int main(){
    thread th1(printa);
    thread th2(printb);
    thread th3(printc);

    th1.join();
    th2.join();
    th3.join();
    return 0;
}
