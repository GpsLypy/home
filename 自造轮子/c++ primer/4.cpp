/* ************************************************************************
> File Name:     4.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sun 20 Jun 2021 09:46:31 AM CST
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

class Solution {
public:
    void merge(vector<int>&nums1,vector<int>&nums2,vector<int>&nums){
         if(nums1.size()==0){
             nums=nums2;
         }
        else if(nums2.size()==0){
            nums=nums1;
        }
        auto beg1=nums1.begin(),end1=nums1.end();
        auto beg2=nums2.begin(),end2=nums2.end();

/*
        if((*beg1)>(*(beg2+(end2-1)))){
            for(auto a:nums2) nums.push_back(a);
            for(auto b:nums1) nums.push_back(b);
        }
        if(*beg2>*(beg1+(end1-1)){
            for(auto a:nums1) nums.push_back(a);
            for(auto b:nums2) nums.push_back(b);
        }
*/
        while(beg1!=end1&&beg2!=end2){
            if(*beg1>=*beg2) {nums.push_back(*beg2);beg2++;}
            else {nums.push_back(*beg1);beg1++;}
        }

        if(beg1==end1) {
            while(beg2!=end2) {nums.push_back(*beg2);beg2++;}
        }
        else {
            while(beg1!=end1) {
                nums.push_back(*beg1);beg1++;
            }
        }

        return;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        merge(nums1,nums2,nums);
        cout<<nums.size()<<endl;
        for(auto a: nums){
            cout<<a<<" ";
        }
        cout<<endl;
        return nums.size()%2? nums[nums.size()/2]:(nums[nums.size()/2-1]+nums[nums.size()/2])/2.0;
    }
};


int main(){
        Solution s;
        vector<int>nums1{1,3};
        vector<int>nums2{};
        double res=s.findMedianSortedArrays(nums1,nums2);
        cout<<res<<endl;
        return 0;
}
