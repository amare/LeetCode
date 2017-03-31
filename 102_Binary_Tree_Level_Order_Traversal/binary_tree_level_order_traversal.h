/*
 Author:            cuckoo
 Date:              2017/03/31 17:22:39
 Update:            
 Problem:           Binary Tree Level Order Traversal
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/binary-tree-level-order-traversal/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <cstddef>      // for NULL

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        return levelOrder_1(root);
    }
    
    vector<vector<int>> levelOrder_1(TreeNode* root)
    {
        if(root == NULL) return {};
        vector<vector<int>> result;
        long num = 1;               // record count of the next level, and the depth of tree cann't over 64
        long level_count = 0;       // receive current level count from variable num
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            level_count = num;
            vector<int> single(level_count);
            num = 0;
            
            TreeNode *current_node = NULL;
            for(int i = 0; i < level_count; ++i)
            {
                current_node = q.front();
                if(current_node->left)
                {
                    ++num;
                    q.push(current_node->left);
                }
                if(current_node->right)
                {
                    ++num;
                    q.push(current_node->right);
                }
                q.pop();
                single[i] =current_node->val;
            }
            result.push_back(single);
        }
        
        return result;
    }

    // dfs preorder traversal
    void PreOrder(TreeNode *root, int depth, vector<vector<int>> &result)
    {
        if(root == NULL) return;
        if(result.size() == depth)
            result.push_back(vector<int>());
        result[depth].push_back(root->val);
        PreOrder(root->left, depth + 1, result);
        PreOrder(root->right, depth + 1, result);
    }
    vector<vector<int>> levelOrder_2(TreeNode* root)
    {
        vector<vector<int>> result;
        PreOrder(root, 0, result);
        
        return result;
    }
};
