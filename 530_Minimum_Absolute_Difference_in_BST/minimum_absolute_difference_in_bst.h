/*
 Author:            cuckoo
 Date:              2017/04/26 20:44:29
 Update:            
 Problem:           Minimum Absolute Difference in BST
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description

 */

#include <cstddef>          // for NULL
#include <climits>          // for INT_MIN, INT_MAX

#include <algorithm>        // for min()

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        return getMinimumDifferenceFirst(root);
    }
    
    void inorder_traversal(TreeNode *root, int &last, int &minimum)
    {
        if(root == NULL) return;
        
        inorder_traversal(root->left, last, minimum);
        
        minimum = std::min(minimum, root->val - last);
        last = root->val;
        
        inorder_traversal(root->right, last, minimum);
    }
    
    int getMinimumDifferenceFirst(TreeNode* root)
    {
        
        if(root == NULL) return INT_MAX;
        
        // find the first element in bst to initialize variable last
        TreeNode *current = root;
        while(current->left)
            current = current->left;
        int first = current->val;
        
        
        int minimum = INT_MAX, last = first - INT_MAX;
        inorder_traversal(root, last, minimum);
        
        return minimum;
    }
};
