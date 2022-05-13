#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for(auto num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}


void heapify(vector<int>& nums,int n,int i){
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    int flag=0;
    if(c1<n&&nums[c1]>nums[max]){
        max=c1;
    }
    if(c2<n&&nums[c2]>nums[max]) {
        max=c2;
    }

    if(max!=i){
        swap(nums[max],nums[i]);
        heapify(nums,n,max);
    }
    
}


void heapify_build(vector<int>& nums){
    int size=nums.size();
    for(int ii=(size-1)/2;ii>=0;ii--){
        heapify(nums,size,ii);
    }
}

void heapSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;

    heapify_build(nums);

    for(int ii=0;ii<size;ii++){
        swap(nums[0],nums[size-1-ii]);
        heapify(nums,size-ii-1,0);
    }
}

int main(){
    vector<int> nums{2,1,23,43,21,34,56,45};
    heapSort(nums);
    print(nums);
    return 0;
}