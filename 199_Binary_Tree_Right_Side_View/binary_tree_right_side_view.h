/*
 Author:            cuckoo
 Date:              2017/06/10 17:13:48
 Update:            
 Problem:           Binary Tree Right Side View
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/binary-tree-right-side-view/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::queue;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        return rightSideViewSecond(root);
    }
    
    // level-order traversal, find the last element of every level
    vector<int> rightSideViewFirst(TreeNode* root)
    {
        if(root == NULL)
            return {};
        
        vector<int> result;
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            TreeNode *node = NULL;
            for(int i = 0; i < n; ++i)
            {
                node = q.front();
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            result.push_back(node->val);
        }
        
        return result;
    }
    
    // DFS - variant preorder traversal
    void VarientPreOrder(TreeNode *root, vector<int> &result, int level)
    {
        if(root == NULL)
            return;
        if(level == result.size())
            result.push_back(root->val);
        
        VarientPreOrder(root->right, result, level + 1);
        VarientPreOrder(root->left, result, level + 1);
    }
    vector<int> rightSideViewSecond(TreeNode* root)
    {
        vector<int> result;
        VarientPreOrder(root, result, 0);
        
        return result;
    }
};
