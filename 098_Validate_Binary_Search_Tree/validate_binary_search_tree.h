/*
 Author:            cuckoo
 Date:              2017/03/31 11:09:19
 Update:            
 Problem:           Validate Binary Search Tree
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/validate-binary-search-tree/#/description

 */

#include <cstddef>      // for NULL

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST_3(root);
    }
    // make sure that the most-right-child of a left-subtree has the key less than the root's key.
    // so all nodes of left-subtree have the key less than the root's key
    // because the most-right-child has the the largest key in left-subtree
    bool isLess(TreeNode *left, TreeNode *root)
    {
        while(left->right) left = left->right;
        if(left->val < root->val)
            return true;
        return false;
    }
    // see above
    bool isGreater(TreeNode *right, TreeNode *root)
    {
        while(right->left) right = right->left;
        if(right->val > root->val)
            return true;
        return false;
    }
    
    bool dfs(TreeNode *root)
    {
        if(root == NULL) return true;
        if(root->left == NULL || root->left->val < root->val && dfs(root->left) && isLess(root->left, root))
        {
            if(root->right == NULL || root->right->val > root->val && dfs(root->right) && isGreater(root->right, root))
                return true;
        }
        return false;
    }
    
    bool isValidBST_1(TreeNode* root)
    {
        return dfs(root);
    }
    
    
    // Morris Traversal
    bool isValidBST_2(TreeNode* root)
    {
        TreeNode *current_node = root;
        TreeNode *previous_node = NULL;
        while(current_node)
        {
            if(current_node->left)
            {
                TreeNode *predecessor = current_node->left;
                while(predecessor->right && predecessor->right != current_node)
                    predecessor = predecessor->right;
                if(predecessor->right == NULL)
                {
                    predecessor->right = current_node;
                    current_node = current_node->left;
                }
                else        // predecessor->right == current_node
                {
                    predecessor->right = NULL;      // reset it to null
                    
                    if(previous_node)
                    {
                        if(previous_node->val >= current_node->val)
                            return false;
                    }
                    previous_node = current_node;
                    current_node = current_node->right;
                }
                
            }
            else
            {
                if(previous_node)
                {
                    if(previous_node->val >= current_node->val)
                        return false;
                }
                previous_node = current_node;
                current_node = current_node->right;
            }
        }
        
        return true;
    }
    
    
    // inorder traversal recursion using previous node
    bool isValidWithPrev(TreeNode *root, TreeNode *&prev)   // pass by reference
    {
        if(root == NULL) return true;
        if(!isValidWithPrev(root->left, prev)) return false;
        if(prev && prev->val >= root->val) return false;
        prev = root;
        return isValidWithPrev(root->right, prev);
    }
    bool isValidBST_3(TreeNode* root)
    {
        TreeNode *prev = NULL;
        return isValidWithPrev(root, prev);
    }
    
    // recursion using root node to be max_node in left-subtree traversal or min_node in right-subtree traversal
    bool isValidWithMinAndMax(TreeNode *root, TreeNode *min_node, TreeNode *max_node)
    {
        if(root == NULL) return true;
        if(min_node && min_node->val >= root->val || max_node && max_node->val <= root->val)
            return false;
        return isValidWithMinAndMax(root->left, min_node, root) && isValidWithMinAndMax(root->right, root, max_node);
    }
    bool isValidBST_4(TreeNode* root)
    {
        return isValidWithMinAndMax(root, NULL, NULL);
    }
};
