/* ************************************************************************
> File Name:     426.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Thu 10 Jun 2021 08:31:58 PM CST
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
    const char* c1="hello ";
    const char* c2="world";

    char *pc=new char[strlen(c1)+strlen(c2)+1];
    strcpy(pc,c1);
    strcat(pc,c2);

    cout<<pc<<endl;

    string s1="hello ";
    string s2="world";

    strcpy(pc,(s1+s2).c_str());//获取连接结果的内存地址
    cout<<pc<<endl;

    delete [] pc;
   
    return 0;
ls}