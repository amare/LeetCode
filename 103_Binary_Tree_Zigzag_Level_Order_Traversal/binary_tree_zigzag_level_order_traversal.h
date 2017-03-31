/*
 Author:            cuckoo
 Date:              2017/03/31 20:49:14
 Update:            
 Problem:           Binary Tree Zigzag Level Order Traversal
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::queue;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return zigzagLevelOrder_1(root);
    }
    
    // dfs preorder
    void PreOrderChanged(TreeNode *root, int depth, vector<vector<int>> &result)
    {
        if(root == NULL) return;
        if(result.size() == depth)
            result.push_back(vector<int>());
        if(depth & 0x1)
            result[depth].insert(result[depth].begin(), root->val);
        else
            result[depth].push_back(root->val); 
        
        PreOrderChanged(root->left, depth + 1, result);
        PreOrderChanged(root->right, depth + 1, result);
    }
    vector<vector<int>> zigzagLevelOrder_1(TreeNode* root)
    {
        vector<vector<int>> result;
        PreOrderChanged(root, 0, result);
        
        return result;
    }
    
    vector<vector<int>> zigzagLevelOrder_2(TreeNode* root)
    {
        if(root == NULL) return {};
        vector<vector<int>> result;
        bool isEvenDepth = true;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *current_node;
            auto size = q.size();
            // vector<int> single;
            vector<int> single(size);
            for(decltype(size) i = 0; i < size; ++i)
            {
                current_node = q.front();
                q.pop();
                if(current_node->left) q.push(current_node->left);
                if(current_node->right) q.push(current_node->right);
                if(isEvenDepth)     // left to right
                    // single.push_back(current_node->val);
                    single[i] = current_node->val;
                else                // right to left
                    // single.insert(single.begin(), current_node->val);
                    single[size-1-i] = current_node->val;
                /*
                int index = isEvenDepth ? i : size - 1 - i;
                single[index] = current_node->val;
                */
            }
            isEvenDepth = !isEvenDepth;
            result.push_back(single);
        }
        
        return result;
    }
};

