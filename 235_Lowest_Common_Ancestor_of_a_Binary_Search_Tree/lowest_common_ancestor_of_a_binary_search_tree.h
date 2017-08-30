/*
 Author:            cuckoo
 Date:              2017/07/21 09:42:57
 Update:            
 Problem:           Lowest Common Ancestor of a Binary Search Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/#/description

 */

#include <cstddef>              // for NULL

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LowestCommonAncestorSecond(root, p, q);
    }
    
    TreeNode* LowestCommonAncestorFirst(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        
        if(p == q)
            return p;
        
        // ValidBST(root, p, q);
        
        TreeNode *result = root;
        while(result != NULL)
        {
            if(p->val < result->val && q->val > result->val || p->val > result->val && q->val < result->val ||
                p == result || q == result)             // ^attent: one node is a ancestor of another node
                return result;
            if(p->val > result->val && q->val > result->val)
                result = result->right;
            else
                result = result->left;
        }
        
        return result;
    }
    
    TreeNode* LowestCommonAncestorSecond(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        
        while(root != NULL && (p->val > root->val && q->val > root->val || p->val < root->val && q->val < root->val))
            root = p->val > root->val ? root->right : root->left;
        
        return root;
    }
};
