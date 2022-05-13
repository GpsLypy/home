/* ************************************************************************
> File Name:     164.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 26 Jun 2021 04:11:00 PM CST
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

/*
int main(){
    unsigned int vowelCnt=0;
    char ch;
    cout<<"请输入一段文本："<<endl;
    while(cin>>ch){
        if(ch=='a') ++vowelCnt;
        if(ch=='e') ++vowelCnt;
        if(ch=='i') ++vowelCnt;
        if(ch=='o') ++vowelCnt;
        if(ch=='u') ++vowelCnt;
    }

    cout<<"输入的文本中共有："<<vowelCnt<<"个元音字母"<<endl;
    return 0;
}
*/

/*
int main(){
    unsigned int aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0;
    char ch;
    cout<<"请输入一段文本"<<endl;
    while(cin>>ch){
       switch(ch){
           case 'a':
           case 'A':
               ++aCnt;
               break;
           case 'e':
           case 'E':
               ++eCnt;
               break;
           case 'i':
           case 'I':
               ++iCnt;
               break;
           case 'o':
           case 'O':
               ++oCnt;
               break;
           case 'u':
           case 'U':
               ++uCnt;
               break;
       }
    }

    cout<<aCnt<<endl;
}
*/

/*
int main(){
    unsigned int aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0;
    unsigned int spaceCnt=0,tabCnt,newlineCnt=0;
    unsigned int ffCnt=0,flCnt=0,fiCnt=0;
    char ch;
    char prech='\0';
    cout<<"请输入一段文本"<<endl;
    while(cin.get(ch)){ //>>会忽略掉特殊符号
       switch(ch){
           case 'a':
           case 'A':
               ++aCnt;
               break;
           case 'e':
           case 'E':
               ++eCnt;
               break;
           case 'i':
           case 'I':
               ++iCnt;
               break;
           case 'o':
           case 'O':
               ++oCnt;
               break;
           case 'u':
           case 'U':
               ++uCnt;
               break;
           case ' ':
               ++spaceCnt;
               break;
           case '\t':
               ++tabCnt;
               break;
           case '\n':
               ++newlineCnt;
               break;
       }
    }

    cout<<aCnt<<endl;
    cout<<newlineCnt<<endl;
}
*/

int main(){
    unsigned int ffCnt=0,flCnt=0,fiCnt=0;
    char ch;
    char prech='\0';//预检验
    cout<<"请输入一段文本"<<endl;
    while(cin>>ch){ //>>会忽略掉特殊符号
       bool b1=true;
       if(prech=='f'){
           switch(ch){
           case 'f':
               ++ffCnt;
               b1=false;
               break;
           case 'l':
               ++flCnt;
               b1=false;
               break;
           case 'i':
               ++fiCnt;
               b1=false;
               break;
           }
       }
       if(!b1) prech='\0';
       else prech=ch;
    }

    cout<<ffCnt<<endl;
    cout<<fiCnt<<endl;
}

