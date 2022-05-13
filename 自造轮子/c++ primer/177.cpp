/* ************************************************************************
> File Name:     177.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 03 Jul 2021 02:26:04 PM CST
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
#include <stdexcept>
using namespace std;

int main(){
    cout<<"请依次输入被除数和除数："<<endl;
    int val1,val2;
    while(cin>>val1>>val2){
       try{
            if(val2==0){
                //1、cout<<"除数不能为0"<<endl;
                 //return -1;
                throw runtime_error("除数不能为0");
             }
            cout<<"两数相除的结果是："<<val1/val2<<endl; 
       }catch(runtime_error err){
            cout<<err.what()<<endl;
            cout<<"需要继续吗？(y or n)?";
            char ch;
            cin>>ch;
            if(ch!='y' && ch!='Y')  break;
       }
    }
    return 0;
}
