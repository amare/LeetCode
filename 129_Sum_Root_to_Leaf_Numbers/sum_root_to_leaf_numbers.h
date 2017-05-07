/*
 Author:            cuckoo
 Date:              2017/05/07 14:14:27
 Update:            
 Problem:           Sum Root to Leaf Numbers
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/sum-root-to-leaf-numbers/#/description

 */

#include <cstddef>          // for NULL

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersFirst(root);
    }
    
    void sumNumbersFirstAux(TreeNode *root, int num, int &sum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            sum += num * 10 + root->val;
            return;
        }
        
        num = num * 10 + root->val;
        if(root->left)
            sumNumbersFirstAux(root->left, num, sum);
        if(root->right)
            sumNumbersFirstAux(root->right, num, sum);
    }
    int sumNumbersFirst(TreeNode* root)
    {
        if(root == NULL)
            return 0;
            
        int sum = 0;
        sumNumbersFirstAux(root, 0, sum);
        
        return sum;
    }
};
