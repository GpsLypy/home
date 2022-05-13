/* ************************************************************************
> File Name:     192.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Tue 13 Jul 2021 02:36:39 PM CST
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

bool HasUpper(const string& s){
    for(auto ch : s){
        if(isupper(ch)) return true;
    }
     return false;
}

void changeToLower(string &s){
    for(auto &ch : s){
        ch=tolower(ch);
    }
}
int main(){
    cout<<"请输入一个字符串："<<endl;
    string str;
    cin>>str;
    if(HasUpper(str)){
        changeToLower(str);
        cout<<"转换后的字符串是："<<str<<endl;
    }else cout<<"该字符串不含大写字母，无需转换"<<endl;

    return 0;
}
