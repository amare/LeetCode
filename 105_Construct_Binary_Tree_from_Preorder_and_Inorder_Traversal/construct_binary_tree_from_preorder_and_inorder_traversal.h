/*
 Author:            cuckoo
 Date:              2017/04/01 19:37:58
 Update:            
 Problem:           Construct Binary Tree from Preorder and Inorder Traversal
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_1(preorder, inorder);
    }
    
    TreeNode * build(vector<int>& preorder, vector<int>& inorder, int root_pre_index, int start, int last)
    {
        if(start > last) return NULL;
        
        int root_in_index = start;
        for(; root_in_index <= last; ++root_in_index)
            if(inorder[root_in_index] == preorder[root_pre_index])
                break;
                
        TreeNode *root = new TreeNode(preorder[root_pre_index]);
        root->left = build(preorder, inorder, root_pre_index + 1, start, root_in_index - 1);
        // (root_in_index - start) the count of left-subtree nodes
        root->right = build(preorder, inorder, root_pre_index + root_in_index - start  + 1, root_in_index + 1, last);
        
        return root;
    }
    TreeNode* buildTree_1(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
        // destroy tree to avoid memory leak
    }
};
