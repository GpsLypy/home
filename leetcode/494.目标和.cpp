/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto a: nums) sum+=a;
        if(target>sum) return 0;
        if((target+sum)%2) return 0;
        int x=(target+sum)/2;
        
        vector<int> dp(x+1,0);
        dp[0]=1;
        for(int ii=0;ii<nums.size();ii++){
            for(int jj=x;jj>=nums[ii];jj--){
                dp[jj]+=dp[jj-nums[ii]];
            }
        }

        return dp[x];
    }
};
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto num : nums) sum+=num;
        if(target>sum) return 0;
        if(abs(target)>sum) return 0;
        if((target+sum)%2) return 0;
        int bagsize=(target+sum)/2;   //推导出来的

        vector<int> dp(bagsize+1,0);
        dp[0]=1;
        for(int ii=0;ii<nums.size();ii++){  //防止每个背包只有一个物品
            for(int jj=bagsize;jj>=nums[ii];jj--){//防止物品被重复放入
                dp[jj]+=dp[jj-nums[ii]];
            }
        }
        return dp[bagsize];
    }
};
// @lc code=end

