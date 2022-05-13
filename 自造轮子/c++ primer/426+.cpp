/* ************************************************************************
> File Name:     426+.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Thu 10 Jun 2021 09:04:50 PM CST
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
#include <cstring>
using namespace std;

int main(){
    char c;
    char *r=new char[20];

    int l=0;
    while(cin.get(c)){
        cout<<"11"<<endl;
        if(isspace(c)) break;
        r[l++]=c;
        if(l==20){
            cout<<"达到数组容量上限"<<endl;
            break;
        }
    }
    r[l]=0;
    cout<<r<<endl;
    delete[] r;
    return 0;
}
