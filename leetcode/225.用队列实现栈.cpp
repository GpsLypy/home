/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack{
public:
    MyStack(){}
    void push(int val){
        que1.push(val);
    }
    int pop(){
        if(!que1.empty()){
            int size=que1.size();
            
            for(int ii=0;ii<size-1;ii++){
                int val=que1.front();
                que1.pop();
                que2.push(val);
            }
        }
        int val=que1.front();
        que1.pop();

        que1=que2;
        while(!que2.empty()){
            que2.pop();
        }
        
        return val;
    }

    int top(){
        return que1.back();
    }
    bool empty(){
        if(que1.empty()) return true;
        return false;
    }

private:
    queue<int> que1,que2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

