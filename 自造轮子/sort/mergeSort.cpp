#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for(auto &num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

void mergeSortCore(vector<int>& nums,vector<int>& temp,int start,int end){
    if(start>=end) return;
    int mid=start+(end-start)/2;
    int begin1=start,end1=mid;
    int begin2=mid+1,end2=end;
    mergeSortCore(nums,temp,begin1,end1);
    mergeSortCore(nums,temp,begin2,end2);

    int index=start;
    while(begin1<=end1&&begin2<=end2){
        temp[index++]=nums[begin1]<nums[begin2]? nums[begin1++]:nums[begin2++];
    } 

    while(begin1<=end1){
        temp[index++]=nums[begin1++];
    }
    while(begin2<=end2){
        temp[index++]=nums[begin2++];
    }

    for(index=start;index<=end;index++){
        nums[index]=temp[index];
    }
}

void mergeSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;
    vector<int> temp(size,0);
    mergeSortCore(nums,temp,0,size-1);
}
int main(){
    vector<int> nums{2,4,5,1,3,58};
    mergeSort(nums);
    print(nums);
    return 0;
}