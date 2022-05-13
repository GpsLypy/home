/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* traversal(TreeNode* cur,int val){
        if(cur==nullptr) return nullptr;
        if(cur->val==val) return cur;

        if(cur->val>val){
            return traversal(cur->left,val);
        }

        if(cur->val<val){
            return traversal(cur->right,val);
        }
        return cur;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return traversal(root,val);
    }
};
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr||root->val==val) return root;

        while(root!=nullptr&&root->val!=val){
            if((root->val)>val) root=root->left;
            else if((root->val)<val) root=root->right;
        }
        
        return root;
    }
};
// @lc code=end

