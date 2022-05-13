#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
     void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        if(size<2) return;
        if(k>size) k=k%size;
        /*
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        */
        int ii=0,jj=size-1;
        while(ii<jj){
            swap(nums[ii++],nums[jj--]);
        }

        int iii=0,jjj=k-1;
        while(iii<jjj){
            swap(nums[iii++],nums[jjj--]);
        }
        int iiii=k,jjjj=size-1;
        while(iiii<jjjj){
            swap(nums[iiii++],nums[jjjj--]);
        }
     }
};

//每2*k个字符反转前k个字符
class Solution1 {
public:
    string reverseStr(string s, int k) {
        int size=s.size();
        //每次找到2*k区间的起点
        for(int ii=0;ii<size;ii+=(2*k)){
           //此区间被是否有足够的元素
           //==的话意味着剩余元素小于2*K，等于k个，那么可以反转k个字符
           //<的话意味着剩余元素可能小于2*k，但大于k个，也可能大于2*k,但不论哪种情况，都可以反转前k个字符
           //1、正好 2、余出一点点  3、余出好多
           //1、"ab"   2、"abc"    3、"abcde"
           if(ii+k<=size){
               reverse(s.begin()+ii,s.begin()+ii+k);
               continue;
           }else reverse(s.begin()+ii,s.end());

        }
        return s;
    }
};

int main(){
    vector<int> nums{1,2,3,4,5,6,7};
    Solution s;
    s.rotate(nums,3);
    for(auto a:nums){
        cout<<a<<" ";
    }
    cout<<endl;
}