//计数排序->稳定
//时间复杂度：平均：n^2,最好n^2,最坏n^2 
//空间复杂度：O(1)

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for(auto a: nums){
        cout<<a<<" ";
    }
    cout<<endl;
}

void countSort(vector<int>& nums){
    if(nums.size()==0) return;
    for(auto a: nums) cout<<a<<" ";
    cout<<endl;
    //找出待排序数组中的最大最小值，方便下面开辟临时计数数组空间
    int max=nums[0],min=nums[0];
    for(int ii=1;ii<nums.size();ii++){
        if(nums[ii]>max) max=nums[ii];
        if(nums[ii]<min) min=nums[ii];
    }
    cout<<"max="<<max<<" "<<"min="<<min<<endl;
    vector<int> count((max-min+1),0);//数组大小为(max-min+1)
    for(int ii=0;ii<nums.size();ii++){
        count[nums[ii]-min]++;//统计每个元素出现的次数
    }

    //int index=0;
    /*
    for(int ii=0;ii<count.size();ii++){
        while( count[ii] != 0) {
            nums[index++]=ii+min;
            count[ii]--;
        }
    }
    */
    int index=nums.size()-1;
    for(int ii=count.size()-1;ii>=0;ii--){
        while( count[ii] != 0) {
            nums[index--]=ii+min;
            count[ii]--;
        }
    }
}

int main(){
     vector<int> nums{1,24,67,23,4,78,90,456,22,1,32,2,33,1,1,1,12,3,3,2,2,2,2,2,999};
     countSort(nums);
     print(nums);
     return 0;
}