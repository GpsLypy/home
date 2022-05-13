
// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool duplicate(int nums[],int len,int* duplication){
    if(nums==nullptr||len<=0) return false;
    
    for(int ii=0;ii<len;ii++){
        if(nums[ii]<0||nums[ii]>=len) return false; 
    }
    unordered_map<int,int> map;
    map.reserve(len);//重新指定容量
    for(int ii=0;ii<len;ii++){
        if(map.find(nums[ii])==map.end()){
            map.insert({nums[ii],1});//注意中括号
        }else{
            *duplication=nums[ii];
            return true;
        }
    }
    return false;
}

bool duplicate1(int nums[],int len,int* duplication){
    if(nums==nullptr||len<=0) return false;
    
    for(int ii=0;ii<len;ii++){
        if(nums[ii]<0||nums[ii]>=len) return false; 
    }
    vector<bool> vec(len,false);
    for(int ii=0;ii<len;ii++){
        if(vec[nums[ii]]==false){
            vec[nums[ii]]=true;//注意中括号
        }else{
            *duplication=nums[ii];
            return true;
        }
    }
    return false;
}
int  main()
{
   int res;
   int nums[]={2,2,2,3,2,3,6};
   duplicate1(nums,7,&res);
   cout<<res<<endl;
}
