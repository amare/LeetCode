/*
 Author:            cuckoo
 Date:              2017/05/06 18:48:54
 Update:            
 Problem:           Binary Tree Preorder Traversal
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/binary-tree-preorder-traversal/#/description

 */

#include <cstddef>          // for NULL

#include <vector>
using std::vector;

#include <stack>
using std::stack;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return preorderTraversalThird(root);
    }
    
    // recursion
    void preorderTraversalFirstAux(TreeNode *root, vector<int> &result)
    {
        if(root == NULL)
            return;
        
        result.push_back(root->val);
        preorderTraversalFirstAux(root->left, result);
        preorderTraversalFirstAux(root->right, result);
    }
    vector<int> preorderTraversalFirst(TreeNode* root)
    {
        vector<int> result;
        preorderTraversalFirstAux(root, result);
        
        return result;
    }
    
    // using a stack
    vector<int> preorderTraversalSecond(TreeNode* root)
    {
        if(root == NULL)
            return {};
            
        vector<int> result;
        
        stack<TreeNode *> s;
        s.push(root);
        while(s.empty() == false)
        {
            TreeNode *current = s.top();
            s.pop();
            
            result.push_back(current->val);
            if(current->right)
                s.push(current->right);
            if(current->left)
                s.push(current->left);
        }
        
        return result;
    }

    // using a stack, only store right child
    vector<int> preorderTraversalFourth(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode *> s;
        while(true)
        {
            while(root != NULL)
            {
                result.push_back(root->val);
                if(root->right)
                    s.push(root->right);
                root = root->left;
            }
            if(s.empty() == true)
                break;
            root = s.top();
            s.pop();
        }
        
        return result;
    }
    
    // morris traversal
    vector<int> preorderTraversalThird(TreeNode* root)
    {
        vector<int> result;
        TreeNode *current = root;
        while(current != NULL)
        {
            if(current->left)
            {
                TreeNode *ancestor = current->left;
                while(ancestor->right && ancestor->right != current)
                    ancestor = ancestor->right;
                if(ancestor->right == NULL)
                {
                    ancestor->right = current;
                    result.push_back(current->val);
                    current = current->left;
                }
                else    // ancestor->right == current
                {
                    ancestor->right = NULL;
                    current = current->right;
                }
            }
            else
            {
                result.push_back(current->val);
                current = current->right;
            }
        }
        
        return result;
    }
};
