/* ************************************************************************
> File Name:     78.cpp
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Fri 04 Jun 2021 11:14:36 PM CST
> Description:   
 ************************************************************************/
#include<iostream>
using namespace std;

int main(){
    string word;
   /* while(cin>>word)
        cout<<word<<endl;
    return 0;
   */
    string line;
    while(getline(cin,line))
        cout<<line<<endl;
    return 0;

}
