/*
 Author:            cuckoo
 Date:              2017/05/07 11:23:31
 Update:            
 Problem:           Binary Tree Postorder Traversal
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/binary-tree-postorder-traversal/#/description

 */

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <algorithm>            // for reverse()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return postorderTraversalThird(root);
    }
    
    // recursion
    void postorderTraversalFirstAux(TreeNode *root, vector<int> &result)
    {
        if(root == NULL)
            return;
            
        postorderTraversalFirstAux(root->left, result);
        postorderTraversalFirstAux(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversalFirst(TreeNode* root)
    {
        vector<int> result;
        postorderTraversalFirstAux(root, result);
        
        return result;
    }
    
    // using a stack
    vector<int> postorderTraversalSecond(TreeNode* root)
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
            if(current->left)
                s.push(current->left);
            if(current->right)
                s.push(current->right);
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
    
    // using a stack, only store left child
    vector<int> postorderTraversalThird(TreeNode *root)
    {
        vector<int> result;
        
        stack<TreeNode *> s;
        while(true)
        {
            while(root != NULL)
            {
                result.push_back(root->val);
                if(root->left)
                    s.push(root->left);
                root = root->right;
            }
            if(s.empty() == true)
                break;
                
            root = s.top();
            s.pop();
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};
