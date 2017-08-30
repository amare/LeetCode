/*
 Author:            cuckoo
 Date:              2017/07/21 18:16:51
 Update:            
 Problem:           Binary Tree Maximum Path Sum
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/binary-tree-maximum-path-sum/#/description

 */

#include <cstddef>          // for NULL

#include <algorithm>            // for std::max()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        return MaxPathSumFirst(root);
    }
    
    int MaxPathSumFirst(TreeNode *root)
    {
        int result = -0x7FFFFFFF;
        MaxPathSumFirstAux(root, result);
        
        return result;
    }
    
    // the maximum path from starting root node to any node in the tree along the parent-child connections
    int MaxPathSumFirstAux(TreeNode *root, int &result)
    {
        if(root == NULL)
            return 0;
        
        int max_left = MaxPathSumFirstAux(root->left, result);
        int max_right = MaxPathSumFirstAux(root->right, result);
        
        // key parts : embedding the max-value-find in the recursion process
        // @var sum: the maximum path including current root node, left subtree and right subtree
        int sum = root->val;
        sum += max_left > 0 ? max_left : 0;
        sum += max_right > 0 ? max_right : 0;
        result = std::max(result, sum);
            
        return root->val + std::max(0, std::max(max_left, max_right));
    }
};
