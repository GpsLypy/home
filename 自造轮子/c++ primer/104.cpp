/* ************************************************************************
> File Name:     104.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Mon 21 Jun 2021 05:42:52 PM CST
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
    const int sz=10;
    int nums[sz];
    int nums2[sz];
    for(int ii=0;ii<sz;ii++){
        nums[ii]=ii;
    }
    //!nums2=nums;
    for(int jj=0;jj<sz;jj++){
        nums2[jj]=nums[jj];
    }
    for(auto res : nums2)
        cout<<res<<" ";
    cout<<endl;
    return 0;
}
*/
int main(){
    const int sz=10;
    vector<int> v1(sz);
    vector<int> v2(sz);
    for(int ii=0;ii<sz;ii++){
       v1[ii]=ii;
    }
    //!nums2=nums;
    for(int jj=0;jj<sz;jj++){
        v2[jj]=v1[jj];
    }
    for(auto res : v2)
        cout<<res<<" ";
    cout<<endl;
    return 0;
}
