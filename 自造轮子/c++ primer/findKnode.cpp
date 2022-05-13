#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(-1),next(nullptr){}
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode* ptr):val(_val),next(ptr){}
};

ListNode* findKnode(ListNode* node,int k){
    if(node==nullptr) return nullptr;
    ListNode* pre=node;
    int ii=0;
    while(pre->next!=nullptr&&(ii<k-1)){//
        pre=pre->next;
        ii++;
    }

    ListNode* second=node;
    while(pre->next!=nullptr){
        pre=pre->next;
        second=second->next;
    }

    return second;
}
int main(){
    ListNode* head=new ListNode(-11);
    head->next=new ListNode(9);
    head->next->next=new ListNode(11);
    ListNode* node=findKnode(head,10);
    cout<<node->val<<endl;
    return 0;
}