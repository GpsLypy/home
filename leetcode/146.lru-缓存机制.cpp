// @lc code=start
struct ListNode1{
    ListNode1(){}
    //注意！！
    ListNode1(int key,int val):key(key),val(val),pre(nullptr),next(nullptr){}
    int key,val;
    ListNode1* pre;
    ListNode1* next;
};

class LRUCache {
public:
    LRUCache(int _capacity){
        this->capacity=_capacity;
        head=new ListNode1(-1,-1);
        tail=new ListNode1(-1,-1);
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()){
            //获取val的值也是在使用，所以页面使用率也会变化
            ListNode1* node=map[key];
            removeNode(node);
            pushNode(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            ListNode1* node=map[key];
            removeNode(node);
            node->val=value;
            pushNode(node);
            return;
        }
        if(capacity==map.size()){
            ListNode1* node=head->next;
            removeNode(node);
            map.erase(node->key);
        }

        ListNode1* node=new ListNode1(key,value);
        pushNode(node);
        map[key]=node;
    }

    void removeNode(ListNode1* node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }

    void pushNode(ListNode1* node){
        //把活跃数据放在后面
        tail->pre->next=node;
        node->pre=tail->pre;
        node->next=tail;
        tail->pre=node;
    }
    ~LRUCache(){
        if(head){
            delete head;
            head=nullptr; 
        }
        if(tail){
            delete tail;
            tail=nullptr;
        }
        for(auto &a : map){
            if(a.second) {
               delete a.second;
               a.second=nullptr;
            }
        }
    }
private:
    int capacity;
    ListNode1* head,*tail;//表示首尾标记页面
    unordered_map<int,ListNode1*> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// 你必须定义一个 `main()` 函数入口。
#include <iostream>
using namespace std;

int main()
{
  cout << "Hello, World!" << endl;
  return 0;
}

//(a+b)*(c+d)   (ab+)(cd+)*
  TreeNode* root=new TreeNode('*');
  root->left=new TreeNode('+');
  root->left->left=new TreeNode('a');
  root->left->right=new TreeNode('b');

  root->right=new TreeNode('+');
  root->right->left=new TreeNode('c');
  root->right->right=new TreeNode('d');

  TreeNode* traversal(TreeNode* root){
  if(root==nullptr) return root;
  stack<TreeNode*> st;
  
  if(root) st.push(root);
  vector<string> res;
 
  while(!st.empty()){
    TreeNode* node=st.top();
    if(node){
      st.pop();
      st.push(node);
      st.push(nullptr);
      if(node->right) st.push(node->right);
      if(node->left)  st.push(node->left);
    }else{
      st.pop();
      node=st.top();
      st.pop();
      res.push_back(node->val);
    }
  }
  return root;
}