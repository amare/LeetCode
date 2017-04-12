/*
 Author:            cuckoo
 Date:              2017/04/12 21:58:41
 Update:            
 Problem:           Path Sum II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/path-sum-ii/#/description

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        return pathSum_1(root, sum);
    }
    
    void PreOrderTraversal(TreeNode *root, vector<vector<int>> &result, vector<int> &single, int sum)
    {
        if(root == NULL)
            return;
            
        single.push_back(root->val);
        sum -= root->val;
        if(0 == sum && root->left == NULL && root->right == NULL)
            result.push_back(single);
        PreOrderTraversal(root->left, result, single, sum);
        PreOrderTraversal(root->right, result, single, sum);
        single.pop_back();
    }
    vector<vector<int>> pathSum_1(TreeNode* root, int sum)
    {
        vector<vector<int>> result;
        vector<int> single;
        PreOrderTraversal(root, result, single, sum);
        
        return result;
    }
};
