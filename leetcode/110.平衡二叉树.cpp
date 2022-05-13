/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getDepth(TreeNode* cur){
        if(cur==nullptr) return 0;
        int leftDepth=getDepth(cur->left);
        if(leftDepth==-1) return -1;
        int rightDepth=getDepth(cur->right);
        if(rightDepth==-1) return -1;

        return abs(leftDepth-rightDepth)>1? -1:1+max(leftDepth,rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        if(getDepth(root)!=-1) return true;
        else return false;
    }
};
// @lc code=end

