/*
 Author:            cuckoo
 Date:              2017/05/05 20:20:01
 Update:            
 Problem:           Flatten Binary Tree to Linked List
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/flatten-binary-tree-to-linked-list/#/description

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
    void flatten(TreeNode* root) {
        return flattenSecond(root);
    }
    
    /*
        @param - root: current root node
        @return the last node after flatten
    */
    TreeNode * flattenFirstAux(TreeNode *root)
    {
        if(root->left == NULL && root->right == NULL)
            return root;
            
        if(root->left == NULL && root->right != NULL)
            return flattenFirstAux(root->right);
        
        // root->left != NULL
        if(root->right != NULL)
        {
            // reserve the right child node
            TreeNode *right_subtree_root = root->right;
            
            root->right = root->left;
            root->left = NULL;
            TreeNode *left_subtree_tail = flattenFirstAux(root->right);
            
            left_subtree_tail->right = right_subtree_root;
            left_subtree_tail->left = NULL;
            
            return flattenFirstAux(right_subtree_root);
        }
        else
        {
            root->right = root->left;
            root->left = NULL;
            return flattenFirstAux(root->right);
        }
            
    }
    void flattenFirst(TreeNode* root)
    {
        if(root == NULL)
            return;
            
        flattenFirstAux(root);
    }

    void flattenSecond(TreeNode* root)
    {
        TreeNode *current = root;
        while(current != NULL)
        {
            if(current->left != NULL)
            {
                 // Find current node's pre-node that links to current node's right subtree
                TreeNode *previous = current->left;
                while(previous->right != NULL)
                {
                    previous = previous->right;
                }
                previous->right = current->right;
                
                // Use current node's left subtree to replace its right subtree
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};
