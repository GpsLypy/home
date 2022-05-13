/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* node){
        if(node==nullptr||node->next==nullptr) return node;
        ListNode* pre=nullptr;
        ListNode* cur=node;
        ListNode* temp;
        while(cur!=nullptr){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }

    ListNode* mergeList(ListNode* first,ListNode* second){
        if(first==nullptr) return second;
        if(second==nullptr) return first;

        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while(first!=nullptr&&second!=nullptr){
            cur->next=first;
            cur=cur->next;
            first=first->next;
            cur->next=second;
            cur=cur->next;
            second=second->next;


        }
        if(first==nullptr) cur->next=second;
        if(second==nullptr) cur->next=first;

        return dummy->next;
    }
    ListNode* reorderList(ListNode* head) {
        //终止条件
        if(head==nullptr||head->next==nullptr) return head;

        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverseList(slow->next);
        slow->next=nullptr;

        mergeList(head,second);
        return head;
    }
};
// @lc code=end

