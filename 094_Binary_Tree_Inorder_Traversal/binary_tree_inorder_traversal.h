/*
 Author:            cuckoo
 Date:              2017/03/30 20:22:17
 Update:            
 Problem:           Binary Tree Inorder Traversal
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/binary-tree-inorder-traversal/#/description

 */

#include <vector>
using std::vector;

#include <stack>
using std::stack;

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
    vector<int> inorderTraversal(TreeNode* root) {
        return inorderTraversal_3(root);
    }
    
    void dfs(TreeNode *root, vector<int> &result)
    {
        if(root == NULL) return;
        dfs(root->left, result);
        result.push_back(root->val);
        dfs(root->right, result);
    }
    vector<int> inorderTraversal_1(TreeNode* root)
    {
        if(root == NULL) return {};
        vector<int> result;
        dfs(root, result);
        
        return result;
    }
    
    // iterative solution using a stack
    vector<int> inorderTraversal_2(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> s;
        while(1)
        {
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            if(s.empty()) break;    // all elements have been accessed when stack is empty
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }
        
        return result;
    }
    
    // Morris traversal
    vector<int> inorderTraversal_3(TreeNode* root)
    {
        vector<int> result;
        TreeNode *current_node = root;
        while(current_node)
        {
            if(current_node->left)
            {
                TreeNode *ancestor = current_node->left;
                while(ancestor->right && ancestor->right != current_node)
                    ancestor = ancestor->right;
                if(ancestor->right == NULL)
                {
                    ancestor->right = current_node;
                    current_node = current_node->left;
                }
                else    // ancestor->right == current_node
                {
                    ancestor->right = NULL;
                    result.push_back(current_node->val);
                    current_node = current_node->right;
                }
            }
            else
            {
                result.push_back(current_node->val);
                current_node = current_node->right;
            }
        }
        
        return result;
    }
};
