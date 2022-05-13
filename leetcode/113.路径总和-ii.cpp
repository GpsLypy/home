/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> path;
    void traversal(TreeNode* cur,int targetSum,vector<int>& path){
        if(!cur->left&&!cur->right){
            int count=0;
            for(auto a:path) count+=a;
            if(targetSum==count) {
                res.push_back(path);
                return ;
            }
            else return;
        }

        if(cur->left){
            path.push_back(cur->left->val);
            traversal(cur->left,targetSum,path);
            path.pop_back();
        }

        if(cur->right){
            path.push_back(cur->right->val);
            traversal(cur->right,targetSum,path);
            path.pop_back();
        }

        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return res;
        path.push_back(root->val);
        traversal(root,targetSum,path);
        return res;
    }
};
// @lc code=end

