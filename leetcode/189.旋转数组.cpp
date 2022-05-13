/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start

//思路正确，但效率不高
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        if(size<1) return;
        while(k--){
            int val=nums[size-1];
            for(int ii=size-2;ii>=0;ii--){
                nums[ii+1]=nums[ii];
            }
            nums[0]=val;
        }

    }
};
*/
//对于右旋转
//1、反转整个字符串
//2、反转区间为前n的子串
//3、反转区间为n到末尾的子串
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
// @lc code=end

