// 滑动窗口
// 每一时刻，窗口都表示一个无重复字符的子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.size();
        unordered_set<char> window;
        int ii=0;
        int res=0;
        for(int jj=0;jj<size;jj++){
            while(window.find(s[jj])!=window.end()){
                window.erase(s[ii]);
                ii++;
            }
            window.insert(s[jj]);
            res=max(res,jj-ii+1);
        }
        return res;
    }
};