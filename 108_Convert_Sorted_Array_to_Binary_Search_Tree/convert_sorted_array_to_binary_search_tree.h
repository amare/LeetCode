/*
 Author:            cuckoo
 Date:              2017/04/01 20:01:41
 Update:            
 Problem:           Convert Sorted Array to Binary Search Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/#/description

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_1(nums);
    }
    
    TreeNode * build(vector<int> &nums, int start, int last)
    {
        if(start > last) return NULL;
        // int mid = start + (last - start) / 2;
        int mid = start + (last - start + 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid - 1);
        root->right = build(nums, mid + 1, last);
        
        return root;
    }
    TreeNode* sortedArrayToBST_1(vector<int>& nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};
