/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
//言外之意是：只要剩余字符大于等于k，就反转前k个字符
class Solution {
public:
    string reverseStr(string s, int k) {
        int size=s.size();
        //每次找到2*k区间的起点
        for(int ii=0;ii<size;ii+=(2*k)){
           //此区间被是否有足够的元素
           //==的话意味着剩余元素小于2*K，等于k个，那么可以反转k个字符
           //<的话意味着剩余元素可能小于2*k，但大于k个，也可能大于2*k,但不论哪种情况，都可以反转前k个字符
           if(ii+k<=size){
               reverse(s.begin()+ii,s.begin()+ii+k);
               continue;
           }else reverse(s.begin()+ii,s.end());

        }
        return s;
    }
};
// @lc code=end

