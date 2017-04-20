/*
 Author:            cuckoo
 Date:              2017/04/18 22:26:33
 Update:            
 Problem:           Maximum XOR of Two Numbers in an Array
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/#/description

 */

#include <cstddef>          // for NULL

#include <vector>
using std::vector;

#include <algorithm>        // for max()

class Solution {
public:
    struct TreeNode
    {
        TreeNode *next[2];
        TreeNode()
        {
            next[0] = NULL;
            next[1] = NULL;
        }
    };
    TreeNode * BuildTree(vector<int> &nums)
    {
        TreeNode *root = new TreeNode(), *current;
        for(auto num : nums)
        {
            current = root;
            for(int i = 31; i >= 0; --i)
            {
                int index = (num >> i) & 1;
                if(current->next[index] == NULL)
                    current->next[index] = new TreeNode();
                current = current->next[index];
            }
        }
        
        return root;
    }
    void DestroyTree(TreeNode *root)
    {
        if(root == NULL) return;
        if(root->next[0])
            DestroyTree(root->next[0]);
        if(root->next[1])
            DestroyTree(root->next[1]);
        delete root;
    }
    int FindMaximumXORAux(TreeNode *root, int num)
    {
        int result = 0;
        TreeNode *current = root;
        for(int i = 31; i >= 0; --i)
        {
            int index = (num >> i) & 1;
            if(current->next[index ^ 1] != NULL)
            {
                result += 1 << i;
                current = current->next[index ^ 1];
            }
            else
            {
                current = current->next[index];
            }
        }
        
        return result;
    }
    int findMaximumXOR(vector<int>& nums)
    {
        int result = 0;
        TreeNode *root = BuildTree(nums);
        for(auto num : nums)
            result = std::max(result, FindMaximumXORAux(root, num));
        DestroyTree(root);
        
        return result;
    }
};
