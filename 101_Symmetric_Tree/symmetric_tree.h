/*
 Author:            cuckoo
 Date:              2017/03/29 22:41:23
 Update:            
 Problem:           Symmetric Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/symmetric-tree/#/description

 */

#include <cstddef>      // for NULL

#include <queue>
using std::queue;

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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric_1(root);
    }
    
    bool recursion(TreeNode *left_tree, TreeNode *right_tree)
    {
        if(left_tree == NULL && right_tree == NULL)
            return true;
        if(left_tree != NULL && right_tree != NULL && left_tree->val == right_tree->val)
            return (recursion(left_tree->left, right_tree->right) && recursion(left_tree->right, right_tree->left));
        return false;
    }
    
    bool isSymmetric_1(TreeNode* root)
    {
        if(root == NULL || root->left == NULL && root->right == NULL)
            return true;
        if(root->left != NULL && root->right != NULL)
            return recursion(root->left, root->right);
        return false;
    }

    bool isSymmetric_2(TreeNode* root)
    {
        if(root == NULL || root->left == NULL && root->right == NULL)
            return true;
        if(root->left == NULL || root->right == NULL)
            return false;
        
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode *left_tree = q.front();
            q.pop();
            TreeNode *right_tree = q.front();
            q.pop();
            
            if(left_tree == NULL && right_tree == NULL) continue;
            if(left_tree == NULL || right_tree == NULL) return false;
            if(left_tree->val != right_tree->val) return false;
            
            q.push(left_tree->left);
            q.push(right_tree->right);
            q.push(left_tree->right);
            q.push(right_tree->left);
        }
        return true;
    }
};
