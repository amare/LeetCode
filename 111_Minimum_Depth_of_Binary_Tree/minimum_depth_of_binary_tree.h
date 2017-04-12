/*
 Author:            cuckoo
 Date:              2017/04/12 21:10:10
 Update:            
 Problem:           Minimum Depth of Binary Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/minimum-depth-of-binary-tree/#/description

 */

#include <cstddef>      // for NULL

#include <algorithm>        // for min()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        return minDepth_2(root);
    }
    
    
    int minDepth_1Aux(TreeNode* root)
    {
        if(root->left && root->right)
            return std::min(minDepth_1(root->left), minDepth_1(root->right)) + 1;
        if(root->left != NULL)
            return minDepth_1(root->left) + 1;
        if(root->right != NULL)
            return minDepth_1(root->right) + 1;
        
        return 1;   // root->left == NULL && root->right == NULL
    }
    
    int minDepth_1(TreeNode* root)
    {
        return root == NULL ? 0 : minDepth_1Aux(root);
    }
    
    
    int minDepth_2(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left_subtree_depth = minDepth_2(root->left);
        int right_subtree_depth = minDepth_2(root->right);
        
        return (left_subtree_depth == 0 || right_subtree_depth == 0)
                ? left_subtree_depth + right_subtree_depth + 1
                : std::min(left_subtree_depth, right_subtree_depth) + 1;
    }
    
};
