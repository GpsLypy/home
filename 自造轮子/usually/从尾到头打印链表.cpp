#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    ListNode* pnext;
};

//用栈来实现
void PrintListReversing(ListNode* pHead){
    stack<ListNode*> st;
    if(pHead==nullptr) return;
    ListNode* pNode=pHead;
    while(pNode){
        st.push(pNode);
        pNode=pNode->pnext;
    }

    while(!st.empty()){
        pNode=st.top();
        cout<<pNode->val<<endl;
        st.pop();
    }
}

//用递归来实现
void PrintListReversing1(ListNode* pHead){
    if(pHead==nullptr) return;
    PrintListReversing(pHead->pnext);
    cout<<pHead->val<<endl;
}

int main(){
    ListNode* head=new ListNode();
    head->val=1;
    ListNode* node1=new ListNode();
    node1->val=2;
    head->pnext=node1;
    ListNode* node2=new ListNode();
    node2->val=3;
    head->pnext->pnext=node2;

    PrintListReversing1(head);
}