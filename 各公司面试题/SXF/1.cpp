#include <iostream>
#include <vector>
using namespace std;

int uniquePath(vector<vector<int>>& res,int n,int m){
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int jj=0;jj<m&&res[0][jj]==0;jj++){
        dp[0][jj]=1;
    }

    for(int ii=0;ii<n&&res[ii][0]==0;ii++){
        dp[ii][0]=1;
    }

    for(int ii=1;ii<n;ii++){
        for(int jj=1;jj<m;jj++){
            if(res[ii][jj]==0){
                dp[ii][jj]=dp[ii-1][jj]+dp[ii][jj-1];
            }
        }
    }

    return dp[n-1][m-1];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> res;
    for(int ii=0;ii<n;ii++){
        vector<int> nums;
        for(int ii=0;ii<m;ii++){
            int val;
            cin>>val;
            nums.push_back(val);
        }
        res.push_back(nums);
    }

    int ress=uniquePath(res,n,m);

    cout<<ress<<endl;

}