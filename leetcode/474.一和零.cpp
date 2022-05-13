/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int kk=0;kk<strs.size();kk++){
            int zeroNum=0;
            int oneNum=0;
            for(auto s1:strs[kk]){
                if(s1=='1') oneNum++;
                else zeroNum++;
            }
            for(int ii=m;ii>=zeroNum;ii--){
                for(int jj=n;jj>=oneNum;jj--){
                    dp[ii][jj]=max(dp[ii-zeroNum][jj-oneNum]+1,dp[ii][jj]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

