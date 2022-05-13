/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:

      map<char,string> map{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };

    string path;
    vector<string> res;
    void dfs(const string& digits,int index){
        if(index==digits.size()){
            res.push_back(path);
            return;
        }

        string s=map[digits[index]];//横向遍历是abc 所以要去数字对应的字符集
        for(int ii=0;ii<s.size();ii++){
            path.push_back(s[ii]);
            dfs(digits,index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        dfs(digits,0);
        return res;
        
    }
};

// @lc code=end

