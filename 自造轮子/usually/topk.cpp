#include <bits/stdc++.h>
using namespace std;

class mycompare{
public:
    bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs){
        return lhs.second>rhs.second;//左大于右就是构建的小顶堆
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()<1) return{}; 
        unordered_map<int,int> map;
        //1、统计元素出现的频率
        for(int ii=0;ii<nums.size();ii++){
            map[nums[ii]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,mycompare> pri_que;
        //2、定义一个大小为 K 的小顶堆，对频率进行排序
        for(auto it=map.begin();it!=map.end();it++){
            pri_que.push(*it);
            if(pri_que.size()>k) pri_que.pop();
        }
        
        vector<int> res(k);
        for(int ii=k-1;ii>=0;ii--){
            int num=pri_que.top().first;//
            pri_que.pop();
            res[ii]=num;
        }

        return res;
    }
};

class cmp{
public:
    bool operator()(const int a,const int b){
        return a>b;
    }
};
class Solution2{
public:
    vector<int> topk(vector<int>& nums,int k){
        int size=nums.size();
        if(size<1) return {};

        priority_queue<int,vector<int>,cmp> pri_que;

        for(int ii=0;ii<size;ii++){
            pri_que.push(nums[ii]);
            if(pri_que.size()>k) pri_que.pop();
        }

        vector<int> res(k);
        for(int ii=k-1;ii>=0;ii--){
            int num=pri_que.top();
            res[ii]=num;
            pri_que.pop();
        }

        return res;
    }
};


int main(){
    vector<int> nums{1,1,1,2,2,3};
    Solution2 s;
    vector<int> res;
    res=s.topk(nums,2);
    for(auto a:res){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}