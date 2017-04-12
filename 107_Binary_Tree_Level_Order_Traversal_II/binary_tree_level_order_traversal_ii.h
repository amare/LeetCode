/*
 Author:            cuckoo
 Date:              2017/04/12 16:14:06
 Update:            
 Problem:           Binary Tree Level Order Traversal II
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/binary-tree-level-order-traversal-ii/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <algorithm>        // for reverse()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return levelOrderBottom_1(root);
    }
    
    vector<vector<int>> levelOrderBottom_1(TreeNode* root)
    {
        vector<vector<int>> result(0);
        if(NULL == root) return result;
        
        vector<int> single;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *current = NULL;
            int size = q.size();
            single.resize(size, 0);
            for(int i = 0; i < size; ++i)
            {
                current = q.front();
                q.pop();
                
                single[i] = current->val;
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            result.insert(result.begin(), single);
        }
        
        return result;
    }

    // DFS
    void LevelOrder(TreeNode *root, int level, vector<vector<int>> &result)
    {
        if(root == NULL)
            return;
        if(level == result.size())
            result.push_back(vector<int>());
        
        result[level].push_back(root->val);
        LevelOrder(root->left, level + 1, result);
        LevelOrder(root->right, level + 1, result);
    }
    
    vector<vector<int>> levelOrderBottom_2(TreeNode* root)
    {
        vector<vector<int>> result;
        LevelOrder(root, 0, result);
        reverse(result.begin(), result.end());
        
        return result;
    }
};
