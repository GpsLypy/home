/*
 * @lc app=leetcode.cn id=1593 lang=cpp
 *
 * [1593] 拆分字符串使唯一子字符串的数目最大
 */

// @lc code=start
class Solution {
public:
    int maxCount;
    unordered_set<string> set;
    void dfs(string s,int count,int index){
        if(index>=s.size()){
            maxCount=max(maxCount,count);
        }
        for(int ii=index;ii<s.size();ii++){
            string sub=s.substr(index,ii-index+1);
            if(set.find(sub)==set.end()){
                set.insert(sub);
                dfs(s,count+1,ii+1);
                set.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        maxCount=1;
        dfs(s,0,0);
        return maxCount;
    }
};
// @lc code=end

