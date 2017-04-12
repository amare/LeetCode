/*
 Author:            cuckoo
 Date:              2017/04/12 20:03:43
 Update:            
 Problem:           Balanced Binary Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/balanced-binary-tree/#/description

 */

#include <cstddef>      // for NULL

#include <cmath>        // for abs()
#include <algorithm>    // for max()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isBalanced_2(root);
    }
    
    // O(n^2)
    int MaxDepthOfTree(TreeNode *root)
    {
        return root == NULL ? 0 : std::max(MaxDepthOfTree(root->left), MaxDepthOfTree(root->right)) + 1;
    }
    
    bool isBalanced_1(TreeNode* root)
    {
        if(root == NULL)
            return true;
        if(isBalanced_1(root->left) && isBalanced_1(root->right) && std::abs(MaxDepthOfTree(root->left) - MaxDepthOfTree(root->right)) <= 1)
            return true;
        
        return false;
    }
    
    // O(n)
    int DfsHeight(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        int left_subtree_height = DfsHeight(root->left);
        int right_subtree_height = DfsHeight(root->right);
        if(left_subtree_height == - 1 || right_subtree_height == - 1 || std::abs(left_subtree_height - right_subtree_height) > 1)
            return -1;
            
        return std::max(left_subtree_height, right_subtree_height) + 1;
    }
    bool isBalanced_2(TreeNode* root)
    {
        return DfsHeight(root) != -1;
    }
    
};
