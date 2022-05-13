/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
       vector<int> need(128,0);//用need数组记录我们所需要的元素
       for(char c : t){
           need[c]++;
       }
       int needcount=t.size();
       int ii=0,jj=0;//定义滑动窗口
       string res;
       int length=INT_MAX;
       for(jj=0;jj<s.size();jj++){
           char c=s[jj];
           if(need[c]>0){
               needcount--;
           }
           need[c]--;//-1/0
           if(needcount==0){
               while(ii<jj&&need[s[ii]]<0) {
                   need[s[ii++]]++;//
               }
               if(jj-ii+1<length&&ii<=jj){
                   length=jj-ii+1;
                   res=s.substr(ii,length);
               }
               need[s[ii++]]++;//
               needcount++;
           }
       }

       return (length==INT_MAX)? "":res;
    }
};
// @lc code=end

