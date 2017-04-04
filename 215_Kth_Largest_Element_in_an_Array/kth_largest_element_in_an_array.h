/*
 Author:            cuckoo
 Date:              2017/04/04 16:20:46
 Update:            
 Problem:           Kth Largest Element in an Array
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/kth-largest-element-in-an-array/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_1(nums, k);
    }
    
    /* findKthLargest_0
     * 1. sort
     * 2. find the (k-1)th element in the sorted array
     */
    
    // using quick-sort solution
    int QuickSortVariant(vector<int> &nums, int start, int last, int k)
    {
        if(start >= last)
            return nums[start];
        
        int pivot = nums[start];
        int i = start, j = last;
        while(i < j)
        {
            while(i < j && nums[j] <= pivot) --j;
            std::swap(nums[i], nums[j]);
            while(i < j && nums[i] > pivot) ++i;
            std::swap(nums[i], nums[j]);
        }
        if(i == k - 1) return nums[i];
        
        return i < k - 1 ? QuickSortVariant(nums, i + 1, last, k)
                         : QuickSortVariant(nums, start, i - 1, k);
    }
    
    int findKthLargest_1(vector<int>& nums, int k)
    {
        int size = nums.size();
        if(k < 1 || k > size)
            return INT_MIN;
        
        return QuickSortVariant(nums, 0, size - 1, k);
    }
};
