/*
 Author:            cuckoo
 Date:              2017/06/24 11:01:04
 Update:            
 Problem:           Count Complete Tree Nodes
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/count-complete-tree-nodes/#/description

 */

#include <cstddef>      // for NULL
#include <cmath>        // for pow()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        return countNodesFirst(root);
    }
    
    // count the number of nodes in the last level
    int CountLastLevel(TreeNode *root, int left_subtree_level)
    {
        if(0 == left_subtree_level)
            return 1;
        
        // find the level of the right subtree of root
        int right_subtree_level = 0;
        if(root->right)
        {
            ++right_subtree_level;
            TreeNode *node = root->right;
            while(node->left)
            {
                ++right_subtree_level;
                node = node->left;
            }
        }
        
        return left_subtree_level != right_subtree_level
                                    ? CountLastLevel(root->left, left_subtree_level - 1)
                                    : std::pow(2, left_subtree_level - 1) + CountLastLevel(root->right, right_subtree_level - 1);
    }
    int countNodesFirst(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left_subtree_level = 0;
        TreeNode *node = root->left;
        while(node)
        {
            ++left_subtree_level;
            node = node->left;
        }
        
        // nodes of the last level plus all nodes of other level
        return std::pow(2, left_subtree_level) - 1 + CountLastLevel(root, left_subtree_level);
    }

    int countNodesSecond(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left_height = 0, right_height = 0;
        TreeNode *left_subtree = root, *right_subtree = root;
        while(left_subtree)
        {
            ++left_height;
            left_subtree = left_subtree->left;
        }
        while(right_subtree)
        {
            ++right_height;
            right_subtree = right_subtree->right;
        }
        
        return left_height == right_height
                    ? std::pow(2, left_height) - 1
                    : 1 + countNodesSecond(root->left) + countNodesSecond(root->right);
    }
};
