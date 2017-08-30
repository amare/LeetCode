/*
 Author:            cuckoo
 Date:              2017/08/02 10:23:42
 Update:            
 Problem:           Count of Range Sum
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/count-of-range-sum/description/

 */

#include <cstddef>              // for NULL

#include <vector>
using std::vector;

#include <algorithm>            // for std::sort()

struct BSTNode
{
    long long value;
    int greater_or_equal_count;
    int smaller_or_equal_count;
    BSTNode *left, *right;
    
    BSTNode(long long value_): value(value_), greater_or_equal_count(1), smaller_or_equal_count(1), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        return CountRangeSumSecond(nums, lower, upper);
    }
    
    // BST
    int CountRangeSumFirst(vector<int>& nums, int lower, int upper)
    {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for(int i = 0; i < n; ++i)
            sums[i+1] = sums[i] + nums[i];
        
        int result = 0;
        BSTNode *root = new BSTNode(0);
        for(int i = 1; i <= n; ++i)
        {
            // result += SearchBigger(root, sums[i] - upper) + SearchSmaller(root, sums[i] - lower) - i;
            result += SearchBigger(root, sums[i] - upper) - SearchBigger(root, sums[i] - lower + 1);
            insert(root, sums[i]);
        }
        Clear(root);
        
        return result;
    }
    
    BSTNode *insert(BSTNode *root, long long val)
    {
        if(root == NULL)
            return new BSTNode(val);
        
        if(root->value == val)
        {
            ++root->greater_or_equal_count;
            ++root->smaller_or_equal_count;
        }
        else if(root->value < val)
        {
            root->right = insert(root->right, val);
            ++root->greater_or_equal_count;
        }
        else
        {
            root->left = insert(root->left, val);
            ++root->smaller_or_equal_count;
        }
        
        return root;
    }
    
    int SearchBigger(BSTNode *root, long long target)
    {
        if(root == NULL)
            return 0;
        
        if(root->value == target)
            return root->greater_or_equal_count;
        if(root->value < target)
            return SearchBigger(root->right, target);
        else
            return root->greater_or_equal_count + SearchBigger(root->left, target);
    }
    
    int SearchSmaller(BSTNode *root, long long target)
    {
        if(root == NULL)
            return 0;
        
        if(root->value == target)
            return root->smaller_or_equal_count;
        if(root->value > target)
            return SearchSmaller(root->left, target);
        else
            return root->smaller_or_equal_count + SearchSmaller(root->right, target);
    }
        
    void Clear(BSTNode *root)
    {
        if(root == NULL)
            return;
        Clear(root->left);
        Clear(root->right);
        delete root;
    }
    
    // Merge Sort - the best one
    int CountRangeSumSecond(vector<int>& nums, int lower, int upper)
    {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for(int i = 0; i < n; ++i)
            sums[i+1] = sums[i] + nums[i];
        
        vector<long> copy(sums);
        
        return MergeSortVariation(copy, 0, copy.size() - 1, sums, lower, upper);
    }
    
    int MergeSortVariation(vector<long> &A, int low, int high, vector<long> &B, int lower, int upper)
    {
        if(low >= high)
            return 0;
        
        int mid = low + (high - low >> 1);
        // count
        int count = MergeSortVariation(B, low, mid, A, lower, upper) + MergeSortVariation(B, mid + 1, high, A, lower, upper);
        
        int p2 = mid + 1, p3 = mid + 1;
        for(int left = low; left <= mid; ++left)
        {
            while(p2 <= high && A[p2] - A[left] < lower)        // find the first element in right half which meets A[p2] - A[left] >= lower
                ++p2;
            while(p3 <= high && A[p3] - A[left] <= upper)       // find the first element in right half which meets A[p3] - A[left] > upper
                ++p3;
            count += p3 - p2;
        }
        
        // merge
        int i = low, j = mid + 1;
        for(int k = low; k <= high; ++k)
        {
            if(i <= mid && (j > high || A[i] < A[j]))
                B[k] = A[i++];
            else
                B[k] = A[j++];
        }
        
        return count;
    }
    
    // BIT: binary index tree
    // f[i]: whether number exists at index i or not(1 or 0)
    // bit[idx]: f[idx] + f[idx + 1] + ... + f[idx + 2^r - 1]
    int CountRangeSumThird(vector<int>& nums, int lower, int upper)
    {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for(int i = 0; i < n; ++i)
            sums[i+1] = sums[i] + nums[i];
        
        vector<long> copy(sums);
        std::sort(copy.begin(), copy.end());
        
        int result = 0;
        vector<int> bit1(copy.size() + 1, 0);
        
        // sums[i] >= s[j] - upper && sums[i] <= s[j] - lower
        for(int i = 0; i <= n; ++i)
        {
            result += Read(bit1, std::lower_bound(copy.begin(), copy.end(), sums[i] - upper) - copy.begin() + 1) -
                Read(bit1, std::lower_bound(copy.begin(), copy.end(), sums[i] - lower + 1) - copy.begin() + 1);
            Update(bit1, std::lower_bound(copy.begin(), copy.end(), sums[i]) - copy.begin() + 1, 1);
        }
        
        return result;
    }
    
    // count from index to bit1.size() - 1, a.k.a, how many elements in current bits which are larger than or equal to sums[index-1]
    int Read(vector<int> &bit1, int index)
    {
        int sum = 0;
        while(index < bit1.size())
        {
            sum += bit1[index];
            index += index & -index;
        }
        
        return sum;
    }
    void Update(vector<int> &bit1, int index, int value)
    {
        while(index > 0)
        {
            bit1[index] += value;
            index -= index & -index;
        }
    }
};
