#include <iostream>
#include <vector>
using namespace std;

class Solution{
 public:
    int func(vector<int>& nums){
        vector<int> paper(nums.size(),1);
        for(int ii=1;ii<nums.size();ii++){
            if(nums[ii]>nums[ii-1]) paper[ii]=paper[ii-1]+1;
        }
         for(int ii=nums.size()-2;ii>=0;ii--){
            if(nums[ii]>nums[ii+1]) paper[ii]=max(paper[ii+1]+1,paper[ii]);
        }
        
        int res=0;
        for(auto a: paper){
            res+=a;
        }
        return res;
    }
};

int main(){
    vector<int> nums;
    int num;
    while(1){
        cin>>num;
        nums.push_back(num);
        if(cin.get()=='\n') break;
    }
    Solution s;
    cout<<s.func(nums);
}