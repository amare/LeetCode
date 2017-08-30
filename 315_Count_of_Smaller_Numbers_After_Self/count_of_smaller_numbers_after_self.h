/*
 Author:            cuckoo
 Date:              2017/07/28 20:48:03
 Update:            
 Problem:           Count of Smaller Numbers After Self
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/count-of-smaller-numbers-after-self/tabs/description/

 */

#include <cstddef>          // for NULL

#include <vector>
using std::vector;

struct BSTTreeNode
{
    int value;
    BSTTreeNode *left, *right;
    int smaller_and_equal_count;    // a count of elements in the subtree rooted at the current node 
                                    // that are smaller than or equal to current node's value
    
    BSTTreeNode(int val): value(val), left(NULL), right(NULL), smaller_and_equal_count(1) {}
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        return CountSmallerFirst(nums);
    }
    
    vector<int> CountSmallerFirst(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 0)
            return {};
        
        BSTTreeNode *root = new BSTTreeNode(nums[n-1]);
        vector<int> result(n, 0);
        // iterate from back to front: i < j and nums[i] > nums[j]
        for(int i = n - 2; i >= 0; --i)
        {
            result[i] = Search(root, nums[i] - 1);      // find the number of smaller elements to the right of nums[i]
            InsertNode(root, nums[i]);
        }
        Clear(root);
        
        return result;
    }
    
    // insert a new node to BST
    BSTTreeNode *InsertNode(BSTTreeNode *root, int val)
    {
        if(root == NULL)
            return new BSTTreeNode(val);
        
        if(root->value == val)
            root->smaller_and_equal_count++;
        else if(root->value < val)
            root->right = InsertNode(root->right, val);
        else
        {
            root->smaller_and_equal_count++;
            root->left = InsertNode(root->left, val);
        }
        
        return root;
    }
    
    // find the number of node whose value is smaller than or equal to val
    int Search(BSTTreeNode *root, int val)
    {
        if(root == NULL)
            return 0;
        
        if(root->value == val)
            return root->smaller_and_equal_count;
        else if(root->value > val)
            return Search(root->left, val);
        else
            return root->smaller_and_equal_count + Search(root->right, val);
    }
    
    void Clear(BSTTreeNode *root)
    {
        if(root == NULL)
            return;
        Clear(root->left);
        Clear(root->right);
        delete root;
    }
    
};
