/* ************************************************************************
> File Name:     205.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Wed 14 Jul 2021 04:34:18 PM CST
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

int fact(int val){
    if(val>1){
        return fact(val--)*val;
    }
    return 1;
}

int main(){
    int res=fact(5);
    cout<<res<<endl;
}
