/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void myswap(char &ii,char& jj){
        char temp=ii;
        ii=jj;
        jj=temp;
    }
    void reverseString(vector<char>& s) {
        //reverse(s.begin(),s.end());
        int ii=0,jj=s.size()-1;
        while(ii<jj){
            myswap(s[ii++],s[jj--]);
        }
    }
};
// @lc code=end

