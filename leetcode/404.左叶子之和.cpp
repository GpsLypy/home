/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if(root) st.push(root);
        int res=0;
        while(!st.empty()){
            TreeNode* node=st.top();
            if(node!=nullptr){
                st.pop();
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr);
            }else{
                st.pop();
                node=st.top();
                st.pop();
                int midvalue=0;
                if(node->left!=nullptr&&node->left->left==nullptr&&node->left->right==nullptr){
                    midvalue=node->left->val;
                    res+=midvalue;
                }
            }
        }
        return res;
    }
};
// @lc code=end

