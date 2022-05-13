#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <string>
#include <vector>
using namespace std;

mutex mymutex;
condition_variable cv;

int flag=0;
void printa(){
    string s1="ABCDEF";
    unique_lock<mutex> lk(mymutex);
    for(int ii=0;ii<s1.size();ii++){
        if(flag!=0) cv.wait(lk);
        cout<<s1[ii];
        flag=1;
        cv.notify_one();
    }
}


void printb(){
    vector<int> nums{1,2,3,4,5,6};
    unique_lock<mutex> lk(mymutex);
    for(int ii=0;ii<nums.size();ii++){
        if(flag!=1) cv.wait(lk);
        cout<<nums[ii];
        flag=0;
        cv.notify_one();
    }
    cout<<endl;
}


int main(){
    thread t1(printa);
    thread t2(printb);

    t1.join();
    t2.join();

    return 0;
}