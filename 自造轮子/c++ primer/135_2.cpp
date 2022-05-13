/* ************************************************************************
> File Name:     135_2.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Thu 24 Jun 2021 04:54:45 PM CST
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
   int  grade;
   cout<<"请输入分数："<<endl;
   while(cin>>grade){
       string finalgrade=(grade>90)?"high pass":(grade>=60&&grade<=75)? "low pass":(grade<60)? "fail":"pass";
       cout<<finalgrade<<endl;
   }
   return 0;
}
