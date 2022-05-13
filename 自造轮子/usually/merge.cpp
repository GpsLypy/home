#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       vector<int> temp(m+n);
       int index=0;

       int ii=0,jj=0;
       while(ii<m&&jj<n){
           if(nums1[ii]<=nums2[jj]){
                temp[index++]=nums1[ii++];
           }else if(nums2[jj]<nums1[ii]){
               temp[index++]=nums2[jj++];
           }
       }
       
       while(ii<m) temp[index++]=nums1[ii++];
       while(jj<n) temp[index++]=nums2[jj++];
       for(int ii=0;ii<m+n;ii++){
           nums1[ii]=temp[ii];
       }
    }
};

int main(){
    Solution s;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};

    s.merge(nums1,3,nums2,2);

}