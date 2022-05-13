/* ************************************************************************
> File Name:     199.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Tue 13 Jul 2021 04:40:52 PM CST
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

int icount(initializer_list<int>il){
    int Count=0;
    for(auto val:il){
        Count+=val;
    }
    return Count;

}
int main(){
    cout<<"1,3,9,100的和是："<<icount({1,3,9,100})<<endl;
    return 0;
}
