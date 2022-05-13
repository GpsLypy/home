/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int maxLength=INT_MIN;
    int maxLeftVal=0;
    void traversal(TreeNode* cur,int leftlength){
        if(cur->left==nullptr&&cur->right==nullptr){
            if(leftlength>maxLength){ 
                maxLength=leftlength;
                maxLeftVal=cur->val;
            }
            return ;
        }

        if(cur->left){
            leftlength++;
            traversal(cur->left,leftlength);
            leftlength--;
        }
        if(cur->right){
            leftlength++;
            traversal(cur->right,leftlength);
            leftlength--;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
       traversal(root,1);
       return maxLeftVal;
    }
};
// @lc code=end

