/* ************************************************************************
> File Name:     166.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 26 Jun 2021 06:55:18 PM CST
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
    string curstring,prestring="",maxCntstring;
    int curCnt=1,maxCnt=0;

    while(cin>>curstring){
        if(curstring==prestring){
            curCnt++;
            if(curCnt>maxCnt){
                maxCnt=curCnt;
                maxCntstring=curstring;
            }
         }
        else curCnt=1;

        prestring=curstring;
    }

    if(maxCnt>1)  
    cout<<"出现最多的字符串"<<maxCnt<<" :"<<maxCntstring<<endl;
    else cout<<"每个字符串只出现了一次"<<endl;
    return 0;
}
