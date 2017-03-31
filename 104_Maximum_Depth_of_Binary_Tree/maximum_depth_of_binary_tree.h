/*
 Author:            cuckoo
 Date:              2017/03/31 21:19:55
 Update:            
 Problem:           Maximum Depth of Binary Tree  
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description

 */

#include <cstddef>      // for NULL
#include <algorithm>        // for max()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return maxDepth_1(root);
    }
    
    int dfs(TreeNode *root, int depth)
    {
        if(root == NULL) return depth;
        return std::max(dfs(root->left, depth + 1), dfs(root->right, depth + 1));
    }
    int maxDepth_1(TreeNode* root)
    {
        return dfs(root, 0);
    }
};
