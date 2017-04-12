/*
 Author:            cuckoo
 Date:              2017/04/12 21:41:59
 Update:            
 Problem:           Path Sum
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/path-sum/#/description

 */

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
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum_2(root, sum);
    }
    
    /* wrong
    bool hasPathSum_1Aux(TreeNode* root, int sum)
    {
        if(root == NULL)
            return sum == 0 ? true : false;

        sum -= root->val;
        if(hasPathSum_1Aux(root->left, sum) || hasPathSum_1Aux(root->right, sum))
            return true;
        
        return false;
    }
    bool hasPathSum_1(TreeNode* root, int sum)
    {
        return root == NULL ? false : hasPathSum_1Aux(root, sum);
    }
    */
    
    bool hasPathSum_2(TreeNode* root, int sum)
    {
        if(root == NULL)
            return false;
            
        sum -= root->val;
        if(0 == sum && root->left == NULL && root->right == NULL)
            return true;
        return hasPathSum_2(root->left, sum) || hasPathSum_2(root->right, sum);
    }
    
};
