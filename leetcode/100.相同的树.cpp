/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==nullptr&&q==nullptr) return true;
       if(p==nullptr||q==nullptr) return false;
       queue<TreeNode*> que;
       que.push(p);
       que.push(q);

       while(!que.empty()){
           TreeNode* left=que.front(); que.pop();
           TreeNode* right=que.front();que.pop();

           if(!left&&!right) continue;
           if(!left||!right||left->val!=right->val) return false;

           que.push(left->left);
           que.push(right->left);
           que.push(left->right);
           que.push(right->right); 
       }
       return true;
    }
};
// @lc code=end

