#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for(auto &num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

void bubbleSort(vector<int>& nums,int size){
    if(size<2) return;
    int flag=0;
    for(int ii=0;ii<size-1;ii++){
        for(int jj=0;jj<size-ii-1;jj++){
            if(nums[jj]>nums[jj+1]){
                swap(nums[jj],nums[jj+1]);
                flag=1;
            }
        }
        if(!flag) break;
    }
}

void bucketSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;
    vector<int> bucketsize(5);
    vector<vector<int>> buckets(5,vector<int>(5,0));

    for(int ii=0;ii<size;ii++){
        buckets[nums[ii]/10][bucketsize[nums[ii]/10]++]=nums[ii];
    }

    for(int ii=0;ii<5;ii++){
        bubbleSort(buckets[ii],bucketsize[ii]);
    }

    int index=0;
    for(int ii=0;ii<5;ii++){
        for(int jj=0;jj<bucketsize[ii];jj++){
            nums[index++]=buckets[ii][jj];
        }
    }
}

int main(){
    vector<int> nums{2,4,5,1,3,28};
    bucketSort(nums);
    print(nums);
    return 0;
}