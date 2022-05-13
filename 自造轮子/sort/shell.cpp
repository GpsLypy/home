#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& nums){
    for(auto &num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}
/*
void shellSortCore(vector<int>& nums,int gap,int ii){
    int inserted=nums[ii];
    int jj;
    for(jj=ii-gap;jj>=0&&nums[jj]>inserted;jj-=gap){
        nums[jj+gap]=nums[jj];
    }
    nums[jj+gap]=inserted;
}
void shellSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;
    for(int gap=size/2;gap>=1;gap/=2){
        for(int ii=gap;ii<size;ii++){
            shellSortCore(nums,gap,ii);
        }
    }
}

*/

void shellSortCore(vector<int>&nums,int gap,int ii){
    int inserted=nums[ii];
    int jj;
    for(jj=ii-gap;jj>=0&&nums[jj]>inserted;jj-=gap){
        nums[jj+gap]=nums[jj];
    }
    nums[jj+gap]=inserted;
}

void shellSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;
    for(int gap=size/2;gap>=1;gap/=2){
        for(int ii=gap;ii<size;ii++){
            shellSortCore(nums,gap,ii);
        }
    }
}
int main(){
    vector<int> nums{2,4,5,1,3,78};
    shellSort(nums);
    print(nums);
    return 0;
}