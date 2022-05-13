/* ************************************************************************
> File Name:     169.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Fri 02 Jul 2021 10:55:12 PM CST
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
using namespace std;

int main(){
    string rsp;
    do{
        cout<<"please enter two values:";
        int val1=0,val2=0;
        cin>>val1>>val2;
        cout<<"the sum of"<<val1<<"and"<<val2<<"="<<val1+val2<<"\n\n"<<"more?";
        cin>>rsp;
    }while(cin);
    //while(!rsp.empty()&&rsp[0]!='n');
}
