/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    TreeNode* pre=nullptr;
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        bool left=isValidBST(root->left);
        if(pre!=nullptr&&pre->val>=root->val) return false;
        pre=root;
        bool right=isValidBST(root->right);
        return left&&right;
    }
};
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        stack<TreeNode*> st;
        if(root) st.push(root);
        vector<int> res;
        while(!st.empty()){
            TreeNode* node=st.top();
            if(node){
                st.pop();
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if(node->left) st.push(node->left);
                
            }else{
                st.pop();
                node=st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        int val=res[0];
        for(int ii=1;ii<res.size();ii++
        ){
            if(res[ii]>val) val=res[ii];
            else return false;
        }
        return true;
    }
};

// @lc code=end

