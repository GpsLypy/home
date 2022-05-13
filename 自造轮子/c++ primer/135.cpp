/* ************************************************************************
> File Name:     135.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Thu 24 Jun 2021 04:43:11 PM CST
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
   vector<int> v1;
   const int sz=10;
   srand((unsigned) time(NULL));

   cout<<"数组的初始值是："<<endl;
   for(int ii=0;ii<sz;++ii){
       v1.push_back(rand()%100);
       cout<<v1[ii]<<" ";
   }

   cout<<endl;
   for(auto &val : v1){
       val=(val%2==1)? val*2:val;
   }

   cout<<"调整后的数值："<<endl;
   for(auto it=v1.cbegin();it!=v1.cend();++it){
    cout<<*it<<" ";
   }
   cout<<endl;
   return 0;
}
