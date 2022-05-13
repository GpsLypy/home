#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zeronum=0,onenum=0;
    for(int ii=0;ii<s.size();ii++){
        if(s[ii]==0) zeronum++;
        else onenum++;
    }
    int N;
    if(onenum>zeronum) N=onenum+1;
    else N=zeronum+1;
    vector<int> dp(n+1,0);
    dp[1]=1;
    for(int ii=2;ii<N;ii++){
        //if(s[ii]!=s[ii-1]){
        //   dp[ii]=1;
        //}else{
            dp[ii]=max(dp[ii-1]+1,dp[ii]);
        //}
    }
    int res=0;
    for(int ii=1;ii<n+1;ii++){
        res+=dp[ii];
    }
    cout<<res<<endl;
    return 0;
}