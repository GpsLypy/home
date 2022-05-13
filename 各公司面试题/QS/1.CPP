#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int climb(int n,int b,unordered_set<int>& c){
    if(n<2) return n;
    vector<int> dp(n+1);
    dp[1]=1;
    dp[2]=2;
    for(int ii=3;ii<=n;ii++)
    {
        int temp;
        if(c.find(ii)!=c.end()){
            temp=ii;
            c.erase(ii);
            continue;
        }
        else if(ii==temp+1) dp[ii]=dp[ii-2];
        else if(ii==temp+2) dp[ii]=dp[ii-1];
        
        dp[ii]=dp[ii-1]+dp[ii-2];
    }
    
    return dp[n];
}

int main(){
    int a,b;
    unordered_set<int> c;
    cin>>a>>b;
    for(int ii=0;ii<b;ii++){
        int val;
        cin>>val;
        c.insert(val);
    }
    if(a==b) cout<<0<<endl;
    int res=climb(a,b,c);
    cout<<res<<endl;
}
