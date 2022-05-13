#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

/*
class Solution {
public:
    void lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int ii=1;ii<size;ii++){
            if(nums[ii]>res[res.size()-1]){
                res.push_back(nums[ii]);
            }else{
                res.pop_back();
                res.push_back(nums[ii]);
            }
        }
        for(auto num: res){
            cout<<num<<" ";
        }
        cout<<endl;
    }
};
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        ListNode* node1=l1;
        ListNode* node2=l2;
        while(node1){
            st1.push(node1->val);
            node1=node1->next;
        }
        while(node2){
            st2.push(node2->val);
            node2=node2->next;
        }

        string s1;
        while(!st1.empty()){
            s1+=to_string(st1.top());
            //cout<<st1.top()<<endl;
            st1.pop();
        }
        
        string s2;
        while(!st2.empty()){
            s1+=to_string(st2.top());
            //cout<<st1.top()<<endl;
            st2.pop();
        }

        int number1,number2;
        size_t t1,t2;
        number1=stoi(s1);
        number2=stoi(s2);
        //int sum=number1+number2;
        cout<<number1<<endl;
    }
};
int main(){
    Solution s;
    ListNode* head1=new ListNode(5);
    head1->next=new ListNode(6);
    head1->next->next=new ListNode(4);

    ListNode* head2=new ListNode(7);
    head2->next=new ListNode(0);
    head2->next->next=new ListNode(8);
    s.addTwoNumbers(head1,head2);
    vector<int> nums{0,1,0,3,2,3};
    return 0;
}