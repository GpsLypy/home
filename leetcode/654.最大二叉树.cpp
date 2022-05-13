/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* traversal(vector<int>& nums,int start,int end){
  
        if(start>=end) return nullptr;
        int maxnum=0;
        int delimiter=0;
        for(int ii=start;ii<end;ii++){//for循环不能用delimiter因为他会随时改变
            if(nums[ii]>maxnum){
                maxnum=nums[ii];
                delimiter=ii;
            }
        }

        TreeNode* node=new TreeNode(maxnum);
        if(end-start==1) return node;
       
        int leftStart=start;
        int leftEnd=delimiter;
        node->left=traversal(nums,leftStart,leftEnd);
        
        int rightStart=delimiter+1;
        int rightEnd=end;
        node->right=traversal(nums,rightStart,rightEnd);
    
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums,0,nums.size());
    }
};


// @lc code=end

