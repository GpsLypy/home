/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
//若题目没有说明是二叉搜索树，则按以下方法写
/*
class Solution {
public:
    void traversal(TreeNode* cur,unordered_map<int,int>& map){
        if(cur==nullptr) return;
        map[cur->val]++;
        traversal(cur->left,map);
        traversal(cur->right,map);
    }

    static bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
        return p1.second>p2.second;
    }
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        unordered_map<int,int> map;
        traversal(root,map);
        vector<pair<int,int>> vec(map.begin(),map.end());

        sort(vec.begin(),vec.end(),cmp);
        res.push_back(vec[0].first);

        for(int ii=1;ii<vec.size();ii++){
            if(vec[ii].second>=vec[0].second) res.push_back(vec[ii].first);
        }

        return res;
        
    }
};
*/
class Solution {
public:
    int maxcount=0;
    int count=0;
    vector<int> res;
    TreeNode* pre=nullptr;
    void traversal(TreeNode* cur){
        if(cur==nullptr) return;

        traversal(cur->left);

        if(pre==nullptr){
            count=1;
        }else if(cur->val==pre->val) count++;
        else {
            count=1;    
        }
        pre=cur;
        if(count==maxcount) res.push_back(pre->val);
        if(count>maxcount){
            maxcount=count;
            res.clear();
            res.push_back(pre->val);
        }

        traversal(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr) return {};
        traversal(root);
        return res;
    }
};

// @lc code=end

