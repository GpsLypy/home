/* ************************************************************************
> File Name:     100.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Fri 18 Jun 2021 09:45:54 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> vInt;
    srand((unsigned)time(NULL));//生成随机数种子
    for(int ii=0;ii<10;ii++){
      vInt.push_back(rand()%1000);
    }

    cout<<"原始数据"<<endl;
    for(auto it=vInt.cbegin();it!=vInt.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"翻倍后的数据"<<endl;

    for(auto it=vInt.begin();it!=vInt.end();it++){
        *it *=2;
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
