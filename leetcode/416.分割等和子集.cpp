/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;//一定要初始化
        for(int ii=0;ii<nums.size();ii++){
            sum+=nums[ii];
        }
        int size=sum/2;
        vector<int> dp(size+1,0);

        for(int ii=0;ii<nums.size();ii++){
            for(int jj=size;jj>=nums[ii];jj--){
                dp[jj]=max(dp[jj-nums[ii]]+nums[ii],dp[jj]);
            }
        }

        if(dp[size]==size&&(sum%2==0)) return true;
        else return false;

    }
};
// @lc code=end

