/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
/*
class mycompare{
public:
    bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs){
        return lhs.second>rhs.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto num : nums){
            map[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,mycompare> pri_que;

        for(auto it=map.begin();it!=map.end();it++){
            pri_que.push(*it);
            if(pri_que.size()>k) pri_que.pop();
        }


        vector<int> res(k);
        for(int ii=k-1;ii>=0;ii--){
            int num=pri_que.top().first;
            pri_que.pop();
            res[ii]=num;
        }

        return res;
    }
};

*/

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


// @lc code=end

