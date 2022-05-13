/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool compare(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr && subRoot==nullptr) return true;
        if(root==nullptr || subRoot==nullptr) return false;
        queue<TreeNode*> que;
        que.push(root);
        que.push(subRoot);

        while(!que.empty()){
            TreeNode* left=que.front(); que.pop();
            TreeNode* right=que.front(); que.pop();

            if(!left&&!right) continue;
            if(!left||!right||(left->val!=right->val)){
                return false;
            }

            que.push(left->left);
            que.push(right->left);
            que.push(left->right);
            que.push(right->right);
          
        }

        return true;
    }
    bool isSubtree(TreeNode*s,TreeNode*t){
        if(s==nullptr) return false;
        if(compare(s,t)) return true;
        return isSubtree(s->left,t)||isSubtree(s->right,t);
    }
};
// @lc code=end

