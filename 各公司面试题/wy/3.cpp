#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        //for循环的终止条件，一旦遇到obstacleGrid[i][0] == 1的情况就停止dp[ii][0]的赋值1的操作，dp[0][jj]同理
        for(int jj=1;jj<n&&obstacleGrid[0][jj]!=2;jj++){
            if(obstacleGrid[0][jj]==0) dp[0][jj]=dp[0][jj-1]+2;
            else if(obstacleGrid[0][jj]==1) dp[0][jj]=dp[0][jj-1]+1;
        }
       
        for(int ii=1;ii<m&&obstacleGrid[ii][0]!=2;ii++){
            if(obstacleGrid[ii][0]==0) dp[ii][0]=dp[ii-1][0]+2;
           else if(obstacleGrid[ii][0]==1) dp[ii][0]=dp[ii-1][0]+1;
        }

        for(int ii=1;ii<m;ii++){
            for(int jj=1;jj<n;jj++){
                if(obstacleGrid[ii][jj]!=2&&obstacleGrid[ii-1][jj]!=2&&obstacleGrid[ii][jj-1]!=2){
                    if(obstacleGrid[ii][jj]==0) dp[ii][jj]=min(dp[ii-1][jj],dp[ii][jj-1])+2;
                    else if(obstacleGrid[ii][jj]==1) dp[ii][jj]=min(dp[ii-1][jj],dp[ii][jj-1])+1;
                }
                else if(obstacleGrid[ii][jj]!=2){
                    if(obstacleGrid[ii-1][jj]==2&&obstacleGrid[ii][jj-1]==2) obstacleGrid[ii][jj]=2;
                    else if(obstacleGrid[ii-1][jj]==2&&obstacleGrid[ii][jj]==0) dp[ii][jj]=dp[ii][jj-1]+2;
                    else if(obstacleGrid[ii-1][jj]==2&&obstacleGrid[ii][jj]==1) dp[ii][jj]=dp[ii][jj-1]+1;
                    else if(obstacleGrid[ii][jj-1]==2&&obstacleGrid[ii][jj]==1) dp[ii][jj]=dp[ii-1][jj]+1;
                    else if(obstacleGrid[ii][jj-1]==2&&obstacleGrid[ii][jj]==0) dp[ii][jj]=dp[ii-1][jj]+2;
                }
            }
        }

        for(auto &a:dp){
            for(auto &b: a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
       return (dp[m-1][n-1]==0)? -1:dp[m-1][n-1];
    }
};


int main(){
    vector<vector<int>> nums{
        //{1,1,1,1,0},{0,1,0,1,0},{1,1,2,1,1},{0,2,0,0,1}
        {2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{0,2,0,0,1}
    };
    cout<<nums[3][1]<<endl;
    Solution s;
    int res=s.uniquePathsWithObstacles(nums);
    cout<<res<<endl;
}