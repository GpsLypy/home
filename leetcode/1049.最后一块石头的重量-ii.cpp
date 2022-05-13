/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int ii=0;ii<stones.size();ii++){
            sum+=stones[ii];
        }
        int size=sum/2;
        vector<int> dp(size+1,0);
        for(int ii=0;ii<stones.size();ii++){
            for (int jj = size; jj >= stones[ii]; jj--){
                dp[jj]=max(dp[jj],dp[jj-stones[ii]]+stones[ii]);
            }
        }

        int leve=sum-dp[size];
        return leve-dp[size];
    }
};
// @lc code=end

