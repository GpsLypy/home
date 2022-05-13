/* ************************************************************************
> File Name:     184.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Mon 12 Jul 2021 04:01:10 PM CST
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

int fact1(int val){
  int res=1;
  while(val>1){
      res*=val--;
  }
  return res;
}
int fact2(int val){
  int res=1;
  for(int ii=val;ii>1;--ii){
      res*=ii;
  }
  return res;
}

int main(){
    int res=fact2(5);
    cout<<"5!="<<res<<endl;
    return 0;
}
