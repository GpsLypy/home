/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */
// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        int size=num.size();
        if(size==k) return "0";
        queue<char> que;
        int need=size-k;//要求删掉k个元素，则最后需要保留size-k个元素
        //stack<string> st;
        string res;
        for(int ii=0;ii<size;ii++){
            char temp=num[ii];
            //还需要丢弃并且栈内还有元素供我们丢弃并且栈顶元素比当前遍历的元素大，那么就需要丢弃栈顶元素，使得整体变小
            while(k>0&&!que.empty()&&que.back()>temp){
                que.pop_back();
                k--;
            }
            que.push(temp);
        }
        
        while(!que.empty()){
            res+=que.front();
            que.pop();
        }
        
        //循环删除前导0 如"0","001"
        while(*res.begin()=='0'&&res.size()!=1){
            res.erase(res.begin());//顺序容器内部删除一个元素用erase,这个函数会返回下一个有效的迭代器
        }
        return res;
    }
};
// @lc code=end

