#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int value;
    Node* next;
};


void revert(Node*& list){
    if(list==nullptr) return;
    Node* pre=nullptr;
    Node* temp;
    while(list){
        temp=list->next;
        list->next=pre;
        pre=list;
        list=temp;
    }
    
    list=pre;
}

int main(){
    /*
    int val=0;
    Node* head=new Node();
    Node* pre=head;
    while(1){
        cin>>val;
        if(cin.get()=='#') break;
        head->next=new Node();
        head->next->value=val;
        head=head->next;
    }
    
    Node* s=pre->next;
    revert(s);
    while(s) {
        cout<<s->value<<" ";
        s=s->next;
    }
    */
    vector<int> nums;
    int val;
    int index=0;
    while(1){
        cin>>val;
        nums[index++]=val;
        if(cin.get()=='#') break;
        //nums.push_back(val);
        
    }
    for(int ii=index-1;ii>=0;ii--){
        cout<<nums[ii]<<" ";
    }
    cout<<'#';
    cout<<endl;
}