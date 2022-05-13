#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for(auto &num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

void heapify(vector<int>& nums,int n,int i){
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    if(c1<n && nums[c1]>nums[max]) max=c1;
    if(c2<n && nums[c2]>nums[max]) max=c2;

    if(max!=i){
        swap(nums[i],nums[max]);
        heapify(nums,n,max);
    } 
}


void heapify_build(vector<int>& nums,int n){
    if(n<1) return;
    for(int ii=(n-1)/2;ii>=0;ii--){
        heapify(nums,n,ii);
    }
}


void heapSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;
    heapify_build(nums,size);

    for(int ii=0;ii<size;ii++){
        swap(nums[0],nums[size-ii-1]);
        heapify(nums,size-ii-1,0);
    }
}

int main(){
    vector<int> nums{2,4,5,1,3,78};
    heapSort(nums);
    print(nums);
    return 0;
}