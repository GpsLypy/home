/* ************************************************************************
> File Name:     170.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 03 Jul 2021 11:14:25 AM CST
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
    string s1,s2;
    
    do{
        cout<<"请输入两个字符串："<<endl;
        cin>>s1>>s2;
        if(s1.size()<s2.size()) cout<<"长度较小的字符串是："<<s1<<endl;
        else if(s1.size()>s2.size()) cout<<"长度较小的字符串是："<<s2<<endl;
        else cout<<"两个字符串等长"<<endl;
    }while(cin);

    return 0;
}
