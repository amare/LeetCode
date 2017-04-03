/*
 Author:            cuckoo
 Date:              2017/04/03 20:25:15
 Update:            
 Problem:           Same Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/same-tree/#/description

 */

#include <cstddef>      // for NULL

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTree_1(p, q);
    }
    
    bool isSameTree_1(TreeNode* tree1, TreeNode* tree2)
    {
        if(tree1 == NULL && tree2 == NULL)
            return true;
        if(tree1 == NULL || tree2 == NULL || tree1->val != tree2->val)
            return false;
        
        return isSameTree_1(tree1->left, tree2->left) && isSameTree_1(tree1->right, tree2->right);
    }

    // BFS
    bool isSameTree_2(TreeNode* tree1, TreeNode* tree2)
    {
        queue<TreeNode *> q1, q2;
        q1.push(tree1);
        q2.push(tree2);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode *current_node1 = q1.front();
            q1.pop();
            TreeNode *current_node2 = q2.front();
            q2.pop();
            
            if(current_node1 == NULL && current_node2 == NULL)
                continue;
            if(current_node1 == NULL || current_node2 == NULL || current_node1->val != current_node2->val)
                return false;
        
            q1.push(current_node1->left);
            q1.push(current_node1->right);
            q2.push(current_node2->left);
            q2.push(current_node2->right);
        }
        
        return true;
    }
};
