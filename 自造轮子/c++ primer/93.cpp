/* ************************************************************************
> File Name:     93.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 19 Jun 2021 11:14:34 PM CST
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
vector<unsigned> scores(11,0);
unsigned grade;

auto beg=scores.begin();
while(cin>>grade){
    if(grade<=100){
        ++*(beg+(grade/10)); 
    }
}

for(beg=scores.begin();beg!=scores.end();beg++){
    cout<<*beg<<" ";
}
cout<<endl;
return 0;
}
