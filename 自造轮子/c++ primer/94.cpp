/* ************************************************************************
> File Name:     94.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Fri 11 Jun 2021 10:55:27 AM CST
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
    vector<int> vec;

    int ii;
    char conster='y';
    while(cin>>ii){
        vec.push_back(ii);
        cout<<"是否继续（y/n?)"<<endl;
        cin>>conster;
        if(conster!='y'&&conster!='Y') break;
    }

//    for(decltype(vec.size()) index=0;index<vec.size()&&index+1<vec.size();index++){
      for(decltype(vec.size()) index=0;index<vec.size()-1;index+=2){

        cout<<vec[index]+vec[index+1]<<" ";
        if((index+2)%10==0) cout<<endl;
      }
        
      if(vec.size()%2!=0) cout<<vec[vec.size()-1]<<endl;
    return 0;
}
