/* ************************************************************************
> File Name:     81.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Mon 07 Jun 2021 12:06:09 PM CST
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
    string s1,s2;
    //cout<<"请输入两个字符串："<<endl;
    char cont='y';
    cout<<"请输入第一个字符串："<<endl;
    while(cin>>s1){
        if(s2.size()==0){
            s2+=s1;
        }
        else s2+=" "+s1;
        cout<<"是否继续(y or n)?"<<endl;
        cin>>cont;
        if(cont=='y'||cont=='Y') cout<<"请输入下一个字符串："<<endl;
        else{
            cout<<s2<<endl;
            break;
        }
    }
    /*
    cin>>s1>>s2;
    auto len1=s1.size();
    auto len2=s2.size();
    if(len1==len2) cout<<s1<<"和"<<s2<<"长度都是"<<len1<<endl;
    else if(len1>len2) cout<<s1<<"比"<<s2<<"长度多"<<len1-len2<<endl;
    else cout<<s1<<"比"<<s2<<"长度少"<<len2-len1<<endl;
   */

    /*
    if(s1>s2) cout<<s1<<">"<<s2<<endl;
    else if(s1==s2)  cout<<s2<<"="<<s1<<endl;
    else if(s1<s2) cout<<s1<<"<"<<s2<<endl;
    */
    return 0;
}
