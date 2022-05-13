/* ************************************************************************
> File Name:     86.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Fri 11 Jun 2021 09:18:37 AM CST
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
    string s;
    cout<<"plese input a string"<<endl;

    getline(cin,s);
    //for(auto c:s)
    for(unsigned int ii=0;ii<s.size();ii++){
        if(!ispunct(s[ii])) cout<<s[ii];
    }
    cout<<endl;
    return 0;
}
