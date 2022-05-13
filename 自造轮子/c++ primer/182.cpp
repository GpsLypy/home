/* ************************************************************************
> File Name:     182.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sun 11 Jul 2021 07:27:01 PM CST
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

int fact(int val);
int main(){
   int res=fact(5);
   printf("%d\n",res);
   return 0;
}

int fact(int val){
    int ret=1;
    while(val>1){
        ret*=val--;
    }
    return ret;
}
