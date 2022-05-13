#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string path;
    int res=0;
    void backtracking(string &s,int startIndex){
        if(path.size()>=2&&(path[path.size()-1]==path[path.size()-2])&&path[path.size()-1]=='('){
            path="";
            path+='(';
            return;
        }else if(path.size()>=2&&(path[path.size()-1]==path[path.size()-2])&&path[path.size()-1]==')'){
            path="";
            return;
        }
        else{
            int count=path.size();
            res=max(res,count);
        }
        for(int ii=startIndex;ii<s.size();ii++){
            if(path.size()==0){
                if(s[ii]=='('){
                    path+=s[ii];
                    backtracking(s,ii+1);
                    //path-=s[ii];
                }else continue;
            }
            path+=s[ii];
            backtracking(s,ii+1);
            //path-=s[ii];
        }

    }
    int longestValidParentheses(string s) {
        backtracking(s,0);
        return res;
    }
};

int main(){
    Solution s;
    string s1="(()";
    s.longestValidParentheses(s1);
    cout<<s.res<<endl;
}