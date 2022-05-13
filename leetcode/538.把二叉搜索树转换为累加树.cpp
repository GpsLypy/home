/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
/*
class Solution {
public:
    int pre=0;
    void traversal(TreeNode* cur){
        if(cur==nullptr) return;
        //反中序遍历
        traversal(cur->right);
        cur->val+=pre;
        pre=cur->val;
        traversal(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
         traversal(root);
         return root;
    }
};
*/

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
         if(root==nullptr) return nullptr;
         stack<TreeNode*> st;
         if(root) st.push(root);
         int pre=0;
         while(!st.empty()){
             TreeNode* node=st.top();
             if(node!=nullptr){
                 st.pop();
                 if(node->left) st.push(node->left);
                 st.push(node);
                 st.push(nullptr);
                 if(node->right) st.push(node->right);
             }else{
                 st.pop();
                 node=st.top();
                 st.pop();
                 node->val+=pre;
                 pre=node->val;
             }
         }
         return root;
         
    }
};
// @lc code=end

