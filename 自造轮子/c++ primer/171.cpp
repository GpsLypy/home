/* ************************************************************************
> File Name:     171.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 03 Jul 2021 12:00:39 PM CST
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
    string s1,s2="";
    bool b1=true;
    while(cin>>s1&&!s1.empty()){
       if(!isupper(s1[0])) continue;
       if(s1==s2) {
            b1=false;
            cout<<"连续出现的单词是："<<s1<<endl;
            break;
       }
       else s2=s1;
    }
    if(b1)  cout<<"没有任何单词是连续出现的！"<<endl;
    return 0;
}
