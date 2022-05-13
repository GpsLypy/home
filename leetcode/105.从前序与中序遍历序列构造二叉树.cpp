/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& preorder,vector<int>& inorder){
        if(preorder.size()==0) return nullptr;

        int rootValue=preorder[0];
        TreeNode* root=new TreeNode(rootValue);
        if(preorder.size()==1) return root;

        int delimiter;
        for(delimiter=0;delimiter<inorder.size();delimiter++){
            if(inorder[delimiter]==rootValue) break;
        }

        vector<int> leftInorder(inorder.begin(),inorder.begin()+delimiter);
        vector<int> rightInorder(inorder.begin()+delimiter+1,inorder.end());


        vector<int> leftPreorder(preorder.begin()+1,preorder.begin()+leftInorder.size()+1);
        vector<int> rightPreorder(preorder.begin()+leftInorder.size()+1,preorder.end());

        root->left=traversal(leftPreorder,leftInorder);
        root->right=traversal(rightPreorder,rightInorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0) return nullptr;
        return traversal(preorder,inorder);
    }
};
*/


class Solution {
public:
    TreeNode* traversal(vector<int>& preorder,int pbegin,int pend,vector<int>& inorder,int inbegin,int inend){
        if(pbegin>=pend) return nullptr;

        int rootValue=preorder[pbegin];
        TreeNode* root=new TreeNode(rootValue);
        if(pend-pbegin==1) return root;

        int delimiter;
        for(delimiter=0;delimiter<inend;delimiter++){
            if(inorder[delimiter]==rootValue) break;
        }

        //vector<int> leftInorder(inorder.begin(),inorder.begin()+delimiter);
        //vector<int> rightInorder(inorder.begin()+delimiter+1,inorder.end());
        int Linbegin=inbegin;
        int Linend=delimiter;
        int Rinbegin=delimiter+1;
        int Rinend=inend;

        int Lpbegin=pbegin+1;
        int Lpend=pbegin+1+(delimiter-inbegin);
        int Rpbegin=pbegin+1+(delimiter-inbegin);
        int Rpend=pend;

        //vector<int> leftPreorder(preorder.begin()+1,preorder.begin()+leftInorder.size()+1);
        //vector<int> rightPreorder(preorder.begin()+leftInorder.size()+1,preorder.end());

        root->left=traversal(preorder,Lpbegin,Lpend,inorder,Linbegin,Linend);
        root->right=traversal(preorder,Rpbegin,Rpend,inorder,Rinbegin,Rinend);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0) return nullptr;
        return traversal(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};
// @lc code=end

