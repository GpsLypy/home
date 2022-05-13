/* ************************************************************************
> File Name:     101.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 19 Jun 2021 10:18:20 PM CST
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
    cout<<"请输入一组数据"<<endl;
    int val;
    while(cin>>val)
        v1.push_back(val);

    if(v1.cbegin()==v1.cend()){
        cout<<"没有任何元素"<<endl;
        return -1;
    }

    cout<<"相邻两项元素的和依次是："<<endl;
    for(auto it=v1.cbegin();it!=v1.cend()-1;it++){
        cout<<(*it+*(++it))<<" ";
        if((it-v1.cbegin()+1)%10==0) cout<<endl;
    }

    if(v1.size()%2!=0) 
        cout<<*(v1.cend()-1);
    return 0;
}
