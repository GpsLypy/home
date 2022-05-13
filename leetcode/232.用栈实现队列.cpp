/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                int val=st1.top();
                st1.pop();
                st2.push(val);
            }
        }
        int res=st2.top();
        st2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res=this->pop();
        st2.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(st1.empty()&&st2.empty()){
            return true;
        }
        return false;
    }

private:
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

