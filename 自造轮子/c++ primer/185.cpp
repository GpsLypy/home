/* ************************************************************************
> File Name:     185.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Mon 12 Jul 2021 04:13:19 PM CST
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
#include <cmath>
using namespace std;

double myABS(double val){
    if(val<0) return -val;
    else return val;
}


int main(){
    double num;
    
    while(cin>>num){
        cout<<num<<"的绝对值是："<<myABS(num)<<endl;
        cout<<num<<"的绝对值是："<<abs(num)<<endl;
    }
    return 0;
}
