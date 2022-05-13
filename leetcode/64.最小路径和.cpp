/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int ii=0;ii<grid.size();ii++){
            if(ii==0) dp[ii][0]=grid[ii][0];
            else if(ii>0) dp[ii][0]=dp[ii-1][0]+grid[ii][0];
        }
        for(int jj=1;jj<grid[0].size();jj++){
            dp[0][jj]=dp[0][jj-1]+grid[0][jj];
        }

        for(int ii=1;ii<grid.size();ii++){
            for(int jj=1;jj<grid[0].size();jj++){
                dp[ii][jj]=min(dp[ii-1][jj]+grid[ii][jj],dp[ii][jj-1]+grid[ii][jj]);
            }
        }
        //cout<<dp[grid.size()-1][grid[0].size()-1]<<endl;
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
// @lc code=end

