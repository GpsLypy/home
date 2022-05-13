#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int res=0;
    vector<int> path;
    void backtracking(vector<int>& nums,int M,int sum,int startIndex){
        if(path.size()==2&&sum<=M){
            res++;
        }
        for(int ii=startIndex;ii<nums.size()&&sum+nums[ii]<=M;ii++){
            sum+=nums[ii];
            path.push_back(nums[ii]);
            backtracking(nums,M,sum,ii+1);
            sum-=nums[ii];
            path.pop_back();
        }
    }
};

int main(){
    vector<int> nums;
    int num;
    int count=2;
    int M;
    int i=0;
    
    while(1){
        cin>>num;
        nums.push_back(num);
        if(cin.get()=='\n') break;
    }
    cout<<nums.size();
    cout<<endl;
    cin>>M;
    cout<<"M="<<M<<endl;
    Solution s;
    s.backtracking(nums,M,0,0);
    cout<<s.res<<endl;
}