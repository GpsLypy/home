#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int>& nums,int M,int N){
    int left=M-1;
    int right=N-1;
    while(left<right){
        swap(nums[left],nums[right]);
        left++;
        right--;
    }
}

int main(){
    int L;
    cin>>L;
    int val;
    vector<int> nums;
    for(int ii=0;ii<L;ii++){
        cin>>val;
        nums.push_back(val);
    }
    int M,N;
    cin>>M>>N;
    reverse(nums,M,N);
    for(int ii=0;ii<nums.size();ii++){
        cout<<nums[ii]<<" ";
    }
    cout<<endl;
}