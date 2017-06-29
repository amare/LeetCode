/*
 Author:            cuckoo
 Date:              2017/06/28 22:33:04
 Update:            
 Problem:           Invert Binary Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/invert-binary-tree/#/description

 */

#include <cstddef>          // for NULL

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return invertTreeFirst(root);
    }
    
    TreeNode* invertTreeFirst(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
            
        TreeNode *temp = root->right;
        root->right = invertTreeFirst(root->left);
        root->left = invertTreeFirst(temp);
        
        return root;
    }
};
