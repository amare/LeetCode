/*
 Author:            cuckoo
 Date:              2017/05/09 21:34:42
 Update:            
 Problem:           Kth Smallest Element in a BST
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/kth-smallest-element-in-a-bst/#/description

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
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestFirst(root, k);
    }
    
    // Morris Traversal
    void InorderTraversal(TreeNode *root, vector<int> &inorder_sequence)
    {
        TreeNode *current = root;
        while(current != NULL)
        {
            if(current->left)
            {
                TreeNode *ancestor = current->left;
                while(ancestor->right != NULL && ancestor->right != current)
                    ancestor = ancestor->right;
                    
                if(ancestor->right == NULL)
                {
                    ancestor->right = current;
                    current = current->left;
                }
                else        // ancestor->right == current;
                {
                    ancestor->right = NULL;
                    inorder_sequence.push_back(current->val);
                    current = current->right;
                }
            }
            else
            {
                inorder_sequence.push_back(current->val);
                current = current->right;
            }
        }
    }
    int kthSmallestFirst(TreeNode* root, int k)
    {
        vector<int> inorder_sequence;
        InorderTraversal(root, inorder_sequence);
        
        int n = inorder_sequence.size();
        if(k < 1 || k > n)
            return INT_MIN;
            
        return inorder_sequence[k - 1];
    }

    // Binary Search
    int NumberOfNodes(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        return NumberOfNodes(root->left) + NumberOfNodes(root->right) + 1;
    }
    int kthSmallestSecond(TreeNode* root, int k)
    {
        int count = NumberOfNodes(root->left);
        if(count == k - 1)
            return root->val;
        
        if(count >= k)
            return kthSmallestSecond(root->left, k);
        else
            return kthSmallestSecond(root->right, k - 1 - count);
    }

    // In-order Traversal
    int kthSmallestThird(TreeNode* root, int k)
    {
        int count = 0;
        stack<TreeNode *> s;
        while(root != NULL || s.empty() == false)
        {
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(++count == k)
                return root->val;
            root = root->right;
        }
        
        return INT_MIN;
    }
    
};
