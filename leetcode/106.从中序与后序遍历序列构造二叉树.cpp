/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& inorder,int inbegin,int inend,vector<int>& postorder,int postbegin,int postend){
        if(postbegin>=postend) return nullptr;

        int rootValue=postorder[postend-1];
        TreeNode* root=new TreeNode(rootValue);
        if(postend-postbegin==1) return root;

        int delimiter;
        for(delimiter=inbegin;delimiter<inend;delimiter++){
            if(inorder[delimiter]==rootValue) break;
        }

        //vector<int> leftInorder(inbegin,inbegin+delimiter);
        //vector<int> rightInorder(inbegin+delimiter+1,inend);
        int leftInorderbegin=inbegin;
        int leftInorderend=delimiter;
        int rightInorderbegin=delimiter+1;
        int rightInorderend=inend;

        //postorder.resize(postend-1);
        //vector<int> leftPostorder(postbegin,postbegin+leftInorder.size());
        //vector<int> rightPostorder(postbegin+leftInorder.size(),postend);
        int leftPostorderbegin=postbegin;
        int leftPostorderend=postbegin+delimiter-inbegin;
        int rightPostorderbegin=postbegin+delimiter-inbegin;
        int rightPostorderend=postend-1;

        root->left=traversal(inorder,leftInorderbegin,leftInorderend,postorder,leftPostorderbegin,leftPostorderend);
        root->right=traversal(inorder,rightInorderbegin,rightInorderend,postorder,rightPostorderbegin,rightPostorderend);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return nullptr;
        return traversal(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};
// @lc code=end

