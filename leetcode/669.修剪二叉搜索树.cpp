/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==nullptr) return nullptr;//修剪的操作并不是在终止条件上进行的，所以遇到空节点返回就可以了
        if(root->val<low){
            TreeNode* right=trimBST(root->right,low,high);
            return right;
        }
        else if(root->val>high){
            TreeNode* left=trimBST(root->left,low,high);
            return left;
        }
        
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);

        return root;
    }
};
// @lc code=end

