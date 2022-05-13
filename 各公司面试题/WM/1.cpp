#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 正方形广场边长是 2n+1
     * @return int整型
     */
    int count(int val) {
        // write code here
        const int N=val;
        int m=2*N+1;
        int n=2*N+1;
        vector<vector<int>> obs(m,vector<int>(n,0));
        vector<vector<int>> dp(m,vector<int>(n,0));
        int a=m/2-1;
        
        for(int ii=a;ii<a+3;ii++){
            for(int jj=a;jj<a+3;jj++){
                obs[ii][jj]=1;
            }
        }
        
        for(int ii=0;ii<n;ii++){
            dp[ii][0]=1;
        }
        
        for(int jj=0;jj<m;jj++){
            dp[0][jj]=1;
        }
        
        for(int ii=1;ii<m;ii++){
            for(int jj=1;jj<n;jj++){
                if(obs[ii][jj]==0) dp[ii][jj]=dp[ii-1][jj]+dp[ii][jj-1];
            }
        }
        
        for(auto a:obs){
            for(auto b:a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
        
        return dp[m-1][n-1];
    }
};

int main(){
    Solution s;
    int res=s.count(2);

    cout<<res<<endl;

}