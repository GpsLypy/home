#include <iostream>
#include <vector>
using namespace std;

/*
void print(vector<int>& nums){
    for(auto ch : nums){
        cout<<ch<<" ";
    }
    cout<<endl;
}

void quickSort(vector<int>& nums,int begin,int end){    
    if(begin>=end) return;/////
    int left=begin,right=end;
    int temp=nums[left];

    while(left<right){
        while(left<right&&nums[right]>=temp){
            right--;
        }
        if(left<right){
            nums[left++]=nums[right];
        }

        while(left<right&&nums[left]<temp){
            left++;
        }
        if(left<right){
            nums[right--]=nums[left];
        }
    }

    nums[left]=temp;
    quickSort(nums,begin,left-1);
    quickSort(nums,left+1,end);
}

int main(){
    vector<int> nums{23,1,1,23,43,45,64,2,34,11,34,22,214,45};
    quickSort(nums,0,nums.size()-1);
    print(nums);
    return 0;
}
*/


    void quickSort(vector<int>& nums,int start,int end){
        if(start>=end) return;//1++
        int left=start;
        int right=end;
        int temp=nums[left];
        while(left<right){
            while(left<right&&nums[right]>=temp){
                right--;
            }
            if(left<right) nums[left++]=nums[right];

            while(left<right&&nums[left]<=temp){
                left++;
            }
            if(left<right) nums[right--]=nums[left];
        }

        nums[left]=temp;
        quickSort(nums,start,left-1);
        quickSort(nums,left+1,end);
    }

    void print(vector<int>& nums){
        for(auto num: nums){
            cout<<num<<" ";
        }
        cout<<endl;
    }

int main(){
    vector<int> nums{1,3,54,6,67,7,5,3,22};
    quickSort(nums,0,nums.size()-1);
    print(nums);
    return 0;
}