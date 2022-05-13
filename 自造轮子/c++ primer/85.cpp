/* ************************************************************************
> File Name:     85.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Fri 11 Jun 2021 09:11:42 AM CST
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
    string s1("hello world!");
    /*
    for(decltype(s1.size()) index=0;index<s1.size();index++){
          s1[index]='X';       
    }
    */
    /*
    for(auto &c:s1){
        c='X';
    }
    */
    for(char &c:s1){
        c='X';
    } 
    cout<<s1<<endl;
    return 0;
}
