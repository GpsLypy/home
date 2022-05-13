/* ************************************************************************
> File Name:     99.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Fri 18 Jun 2021 09:26:53 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> text;
    string s;
    while(getline(cin,s)){
        text.push_back(s);  
        break;
    }
    
    for(auto it=text.begin();it!=text.end()&&!it->empty();it++){
        for(auto it2=it->begin();it2!=it->end();it2++){
            *it2=toupper(*it2);
        }
        cout<<*it<<endl;
    }
    return 0;
}
