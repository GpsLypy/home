#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return string字符串
     */
    static bool cmp(string a,string b){
        string c=a+b;
        string d=b+a;   
        return c>d;
    }
    string largest(vector<int>& nums) {
        // write code here
        vector<string> temp;
        bool flag=false;
        
        for(int ii=0;ii<nums.size();ii++){
            temp.push_back(to_string(nums[ii]));
            if(nums[ii]!=0) flag=true;
        }
        /*
            // 使用 lambda 比较 elements.
            auto cmp = [](string left, string right) {
                return left + right > right + left;
            };
        */

        sort(temp.begin(),temp.end(),cmp);
        
        string res;
        cout<<"temp.size()="<<temp.size()<<endl;
        for(int ii=0;ii<temp.size();ii++){
            res+=temp[ii];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{0,0};
    string res=s.largest(nums);\
    cout<<res<<endl;
}





/*
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto i : nums) {
            str.push_back(to_string(i));
        }
        // 使用 lambda 比较 elements.
        auto cmp = [](string left, string right) {
            return left + right > right + left;
        };
        sort(str.begin(),str.end(), cmp);
        stringstream ss;
        for(auto c : str) {
            ss << c;
        }
        string ans = ss.str();
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};
*/