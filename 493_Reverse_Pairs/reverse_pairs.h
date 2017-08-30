/*
 Author:            cuckoo
 Date:              2017/07/12 16:48:51
 Update:            
 Problem:           Reverse Pairs
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/reverse-pairs/#/description

 */

#include <cstddef>              // for NULL

#include <vector>
using std::vector;

#include <algorithm>            // for sort()

struct BSTTreeNode
{
    BSTTreeNode *left, *right;
    int val;
    int greater_and_equal_count;    // a count of elements in the subtree rooted at the current node 
                                    // that are greater than or equal to current node's value
    
    BSTTreeNode(int v) : val(v), greater_and_equal_count(1), left(NULL), right(NULL) {}
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return ReversePairsFirst(nums);
    }
    
    int ReversePairsFirst(vector<int>& nums)
    {
        vector<int> copy(nums);
        
        return MergeSortVariation(copy, 0, copy.size() - 1, nums);
    }
    
    int MergeSortVariation(vector<int> &A, int low, int high, vector<int> &B)
    {
        if(low >= high)
            return 0;
        
        int mid = low + high >> 1;
               
        // count
        int count = MergeSortVariation(B, low, mid, A) + MergeSortVariation(B, mid + 1, high, A);
        int p2 = mid + 1;
        for(int p1 = low; p1 <= mid; ++p1)
        {
            while(p2 <= high && A[p1] > A[p2] * 2LL)
                ++p2;
            count += p2 - 1 - mid;
        }
        
        // merge
        int i = low, j = mid + 1;
        for(int k = low; k <= high; ++k)
        {
            if(i <= mid && (j > high || A[i] <= A[j]))
                B[k] = A[i++];
            else
                B[k] = A[j++];
        }
        
        return count;
    }

    // update at 2017/07/14 18:54:44
    // BST
    int ReversePairsSecond(vector<int>& nums)
    {
        
        int result = 0;
        
        BSTTreeNode *root = NULL;
        for(int i = 0; i < nums.size(); ++i)
        {
            result += Search(root, nums[i] * 2LL + 1);
            root = Insert(root, nums[i]);
        }
        Clear(root);
            
        return result;
    }
    
    BSTTreeNode *Insert(BSTTreeNode *root, int value)
    {
        if(root == NULL)
            return new BSTTreeNode(value);
        
        if(root->val == value)
            root->greater_and_equal_count++;
        else if(root->val > value)
            root->left = Insert(root->left, value);
        else
        {
            root->greater_and_equal_count++;
            root->right = Insert(root->right, value);
        }
        
        return root;
    }
    
    int Search(BSTTreeNode *root, long long target)
    {
        if(root == NULL)
            return 0;
        
        if(root->val == target)
            return root->greater_and_equal_count;
        else if(root->val < target)
            return Search(root->right, target);
        else
            return root->greater_and_equal_count + Search(root->left, target);
    }
    
    void Clear(BSTTreeNode *root)
    {
        if(root == NULL)
            return;
        Clear(root->left);
        Clear(root->right);
        delete root;
    }
    
    // BIT - binary indexed tree
    // f[i]: whether number exists at index i or not(1 or 0)
    // bit[idx]: f[idx] + f[idx + 1] + ... + f[idx + 2^r - 1]
    int ReversePairsThird(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> copy(nums);
        std::sort(copy.begin(), copy.end());
        
        int result = 0;
        vector<int> bit(n + 1, 0);
        for(int i = 0; i < n; ++i)
        {
            result += Read(bit, std::lower_bound(copy.begin(), copy.end(), nums[i] * 2LL + 1) - copy.begin() + 1);
            Update(bit, std::lower_bound(copy.begin(), copy.end(), nums[i]) - copy.begin() + 1, 1);
        }
        
        return result;
    }
    
    int Read(vector<int> &bit, int index)
    {
        int sum = 0;
        while(index < bit.size())
        {
            sum += bit[index];
            index += index & -index;
        }
        
        return sum;
    }
    
    void Update(vector<int> &bit, int index, int value)
    {
        while(index > 0)
        {
            bit[index] += value;
            index -= index & -index;
        }
    }
};
