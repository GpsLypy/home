#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for(auto &num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

void shellSortCore(vector<int>& nums,int gap,int ii){
    int inserted=nums[ii];
    int jj=0;
    for(jj=ii-gap;jj>=0&&inserted<nums[jj];jj-=gap){
        nums[jj+gap]=nums[jj];
    }
    nums[jj+gap]=inserted;
}

void shellSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;
    for(int ii=size/2;ii>=1;ii/=2){
        for(int jj=ii;jj<size;jj++){
            shellSortCore(nums,ii,jj);
        }
    }
}

int main(){
    vector<int> nums{2,4,5,1,3,78};
    shellSort(nums);
    print(nums);
    return 0;
}