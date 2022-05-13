/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    vector<int> vec;
    void traversal(TreeNode* cur){
        if(cur==nullptr) return;
        traversal(cur->left);
        vec.push_back(cur->val);
        traversal(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX;
        traversal(root);
        for(int ii=1;ii<vec.size();ii++){
            if((vec[ii]-vec[ii-1])<res) res=vec[ii]-vec[ii-1];
            //res=min(res,vec[ii]-vec[ii-1]);
        }
        return res;
    }
};

class Solution {
public:
    TreeNode* pre=nullptr;
    void traversal(TreeNode* cur,int& res){
        if(cur==nullptr) return;
        traversal(cur->left,res);
        if(pre!=nullptr){
            res=min(res,cur->val-pre->val);
        }
        pre=cur;
        traversal(cur->right,res);
    }
    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX;
        traversal(root,res);
        return res;
    }
};
*/

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr) return 0;
        int res=INT_MAX;
        stack<TreeNode*>st;
        if(root) st.push(root);
        TreeNode* pre=nullptr;

        while(!st.empty()){
            TreeNode* node=st.top();
            if(node!=nullptr){
                st.pop();
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if(node->left) st.push(node->left);
            }else{
                st.pop();
                node=st.top();
                st.pop();
                if(pre!=nullptr){
                   res=min(res,node->val-pre->val);
                }
                pre=node;
            }
        }
        return res;
    }
};
// @lc code=end

