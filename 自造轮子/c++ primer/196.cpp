/* ************************************************************************
> File Name:     196.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Tue 13 Jul 2021 03:46:04 PM CST
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
#include <ctime>

using namespace std;

int myCompare(const int val,const int* p){
    return (val>*p)? val:*p;
}

int main(){
    srand((unsigned) time(NULL));
    int a[10];
    for(auto &c:a){
        c=rand()%10;
    }
    int val;
    cout<<"请输入一个数字："<<endl;
    cin>>val;
    cout<<"你输入的数字与数组的首元素较大的一个是:"<<myCompare(val,a)<<endl;
    cout<<"数组中的元素分别是："<<endl;
    for(auto ch:a){
        cout<<ch<<endl;
    }

    return 0;
}
