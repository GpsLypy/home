/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int jj=0;jj<nums.size();jj++){
            if(map.find(target-nums[jj])!=map.end()){
                return {jj,map[target-nums[jj]]};
            }else{
                map.insert(pair<int,int>(nums[jj],jj));
            }
        }
        return {};
    }
};
// @lc code=end

