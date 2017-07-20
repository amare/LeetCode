/*
 Author:            cuckoo
 Date:              2017/04/04 16:20:46
 Update:            2017/07/17 16:03:12
 Problem:           Kth Largest Element in an Array
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/kth-largest-element-in-an-array/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::priority_queue;

#include <algorithm>            // std::nth_element

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return FindKthLargestFourth(nums, k);
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
    
    int FindKthLargestFirst(vector<int>& nums, int k)
    {
        int size = nums.size();
        if(k < 1 || k > size)
            return INT_MIN;
        
        return QuickSortVariant(nums, 0, size - 1, k);
    }

    // update at 2017/07/17 16:03:24
    // nth_element
    int FindKthLargestSecond(vector<int>& nums, int k)
    {
        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
        return nums[k-1];
    }
    
    // Max Heap
    int FindKthLargestThird(vector<int>& nums, int k)
    {
        priority_queue<int> max_heap(nums.begin(), nums.end());

        while(k-- > 1)
            max_heap.pop();
        
        return max_heap.top();
    }
    
    // Min Heap
    int FindKthLargestFourth(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, std::greater<int> > min_heap;
        for(auto num : nums)
        {
            if(min_heap.size() == k)
            {
                if(num > min_heap.top())
                {
                    min_heap.pop();
                    min_heap.push(num);
                }
            }
            else
                min_heap.push(num);
        }
        
        return min_heap.top();
    }
    
    // From LintCode
    int FindKthLargestFifth(vector<int> &nums, int k)
    {
        if(nums.empty() || k <= 0)
            return -1;
            
        int n = nums.size();
        
        return kthLeastElementSecondAux(nums, 0, n - 1, n - k + 1);
    }
    
    int kthLeastElementSecondAux(vector<int> &nums, int low, int high, int k)
    {
        if(low > high)
            return -1;
            
        int position = Partition(nums, low, high);
        if(position + 1 == k)
            return nums[position];
        else if(position + 1 < k)
            return kthLeastElementSecondAux(nums, position + 1, high, k);
        else
            return kthLeastElementSecondAux(nums, low, position - 1, k);
    }
    
    int Partition(vector<int> &nums, int low, int high)
    {
        int pivot_index = low;
        while(low <= high)
        {
            while(low <= high && nums[low] <= nums[pivot_index])
                ++low;
            while(low <= high && nums[high] > nums[pivot_index])
                --high;
            if(low <= high)
                std::swap(nums[low], nums[high]);
        }
        std::swap(nums[high], nums[pivot_index]);
        
        return high;
    }
};
