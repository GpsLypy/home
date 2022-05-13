/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;

        int size=nums.size();
        int delimiter=size/2;//分割点
        int rootValue=nums[delimiter];//分割点数值

        TreeNode* root=new TreeNode(rootValue);
        if(size==1) return  root;
        
        vector<int> left(nums.begin(),nums.begin()+delimiter);
        vector<int> right(nums.begin()+delimiter+1,nums.end());
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);

        return root;
    }
};
// @lc code=end

