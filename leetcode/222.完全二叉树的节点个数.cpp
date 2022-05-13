/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        int leftHeight=0,rightHeight=0;

        while(left){
            leftHeight++;
            left=left->left;
        }
        while(right){
            rightHeight++;
            right=right->right;
        }

        if(leftHeight==rightHeight) return (2<<leftHeight)-1;
        else return countNodes(root->left)+countNodes(root->right)+1;
    }
};
// @lc code=end

