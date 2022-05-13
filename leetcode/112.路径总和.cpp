/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool traversal(TreeNode* cur,int targetSum){
        //targetSum-=cur->val;
        if(!cur->left&&!cur->right){
            if(targetSum==0) return true;
            else return false;
        }

        if(cur->left) 
        {   
            targetSum-=cur->left->val;
            if(traversal(cur->left,targetSum)) return true;
            targetSum+=cur->left->val;
        }
        if(cur->right) {
            targetSum-=cur->right->val;
            if(traversal(cur->right,targetSum)) return true;
            targetSum+=cur->right->val;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        return traversal(root,targetSum-root->val);
    }
};
// @lc code=end

