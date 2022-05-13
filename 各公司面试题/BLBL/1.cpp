#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <sstream>
using namespace std;

struct Node {
  int val;
  Node* next;
};

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
Node* reverse(Node* node){
    if(node==nullptr||node->next==nullptr) return node;
    Node* pre=nullptr;
    Node* cur=node;
    while(cur!=nullptr){
        Node* temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    return pre;
}

Node* mergeNode(Node* head,Node* second){
    if(head==nullptr) return second;
    if(second==nullptr) return head;
    Node* pre=new Node();
    Node* HEAD=pre;
    while(head&&second){
        pre->next=head;
        head=head->next;
        pre=pre->next;

        pre->next=second;
        second=second->next;
        pre=pre->next;
    }

    if(head==nullptr) pre->next=second;
    if(second==nullptr) pre->next=head;

    return HEAD->next;
}


void reverseLinkedList(Node* head) {
	if(head==nullptr||head->next==nullptr) return;
    Node* slow=head,*fast=head->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* second=reverse(slow->next);
    slow->next=nullptr;
    mergeNode(head,second);
    return;

}
/******************************结束写代码******************************/


int main() {
    int x;
    char ch;
    string s;
    vector<int> a;
    getline(cin,s);
    istringstream is(s);
    while(is>>x){
        a.push_back(x);
        is>>ch;
    }
   	Node* head=new Node();
    Node* cur=head;
    for(auto num:a){
       // cout<<num<<endl;
        cur->next=new Node();
        cur->next->val=num;
        cur=cur->next;
    }
	reverseLinkedList(head->next);
    vector<int> res;
    Node* node=head->next;
    while(node){
        if(node->next){
        cout<<node->val<<",";
        }
       else cout<<node->val<<endl;
        node=node->next;
    }
    return 0;

}