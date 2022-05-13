class Solution {
public:
    unordered_map<char,string> digital={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string> res;
    string s;
    void backtracking(string digits,int index){
        if(digits.size()==index){
            res.push_back(s);
            return ;
        }

        char number=digits[index];
        string  S=digital[number];
        for(int ii=0;ii<S.size();ii++){
            s.push_back(S[ii]);
            backtracking(digits,index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        backtracking(digits,0);
        return res;
    }
};