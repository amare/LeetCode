/*
 Author:            cuckoo
 Date:              2017/04/12 19:17:24
 Update:            
 Problem:           Construct Binary Tree from Inorder and Postorder Traversal
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/#/description

 */

#include <cstddef>      // for NULL

#include <vector>
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree_1(inorder, postorder);
    }
    
    TreeNode * build(vector<int>& inorder, vector<int>& postorder, int post_order_index, int start, int end)
    {
        if(start > end)
            return NULL;
        int in_order_index = start;
        for(; in_order_index <= end; ++in_order_index)
            if(inorder[in_order_index] == postorder[post_order_index])
                break;
        
        TreeNode *root = new TreeNode(postorder[post_order_index]);
        root->left = build(inorder, postorder, post_order_index - (end + 1 - in_order_index), start, in_order_index - 1);
        root->right = build(inorder, postorder, post_order_index - 1, in_order_index + 1, end);
        
        return root;
    }
    
    TreeNode* buildTree_1(vector<int>& inorder, vector<int>& postorder)
    {
        return build(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
