/*
小美的子树调换
时间限制： 1000MS
内存限制： 65536KB
题目描述：
小美给出一颗二叉树，接下来会进行若干次对某些节点的左右子树互换操作。

你的任务是给出经过小美若干次调换后的树的中序遍历。

下图是一个调换的例子：

- 初始的二叉树状态，此时中序遍历为 4 2 5 1 6 3 7

- 小美调换了1号节点的左右子树，此时中序遍历为 6 3 7 1 4 2 5

输入描述
第一行是一行整数n, m, k，表示有n个节点，从1编号到n。小美会进行m次节点的调换。小美给出的二叉树的根节点是k。
接下来有 n 行，对于第 i 行，每行两个正整数，描述 i 号节点的左右儿子。其中对于没有儿子的情况用0来表示。
最后一行是m个空格隔开的正整数，每个正整数表示小美调换了这个正整数所标识的节点的左右子树。

输出描述
经过这m次调换后，二叉树的中序遍历。每两个节点序号之间以空格隔开。

样例输入
7 1 1
2 3
4 5
6 7
0 0
0 0
0 0
0 0
1
样例输出
6 3 7 1 4 2 5

提示
输入样例2
7 3 1
2 3
4 5
6 7
0 0
0 0
0 0
0 0
1 2 1
输出样例2
5 2 4 1 6 3 7

数据范围和说明
对于40%的数据有1 <= n <= 100, 1 <= m <= 100
对于100%的数据有 1<= n <= 1,000, 1 <= m <= 10,000
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


typedef struct node{
    struct node* left;
    struct node* right;
    int val;
    node():left(nullptr) , right(nullptr) ,val(0){}
    node(int v):left(nullptr) , right(nullptr) ,val(v){}
}Node;

vector<Node*> Tree;

void createTree(vector<pair<int,int>>& data , Node* root){
    Tree[root->val] = root;
    int l = data[root->val].first , r = data[root->val].second;
    if(l){
        root->left = new Node(l);
        createTree(data,root->left);
    }
    if(r){
        root->right = new Node(r);
        createTree(data,root->right);
    }
}

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    vector<pair<int,int>> data(N+1);
    Tree.resize(N+1);
    for(int i=1;i<=N;i++)
        cin>>data[i].first >> data[i].second;
    Node* root = new Node(K);
    createTree(data,root);

    while(M--){
        int t;
        cin>>t;
        Node* tmp = Tree[t]->left;
        Tree[t]->left = Tree[t]->right;
        Tree[t]->right = tmp; 
    }

    stack<Node*> s;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            root = root->left;
        }

        Node* tmp = s.top() ; s.pop();
        cout<<tmp->val << " ";
        root = tmp->right;
    }
    cout<<endl;
    return 0;
}