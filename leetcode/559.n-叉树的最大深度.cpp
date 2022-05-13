/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int traversal(Node* cur){
        if(cur==nullptr) return 0;
        int depth=0;
        for(auto a: cur->children){
            depth=max(depth,traversal(a));
        }
        return depth+1;
    }
    int maxDepth(Node* root) {
        int res=traversal(root);
        return res;
    }
};
// @lc code=end

