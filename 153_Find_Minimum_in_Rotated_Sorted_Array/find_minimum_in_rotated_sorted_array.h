/*
 Author:            cuckoo
 Date:              2017/04/25 22:02:53
 Update:            
 Problem:           Find Minimum in Rotated Sorted Array
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>            // for min()

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinSecond(nums);
    }
    
    // O(n)
    int findMinFirst(vector<int>& nums)
    {
        int n = nums.size();
        if(0 == n) return INT_MIN;
        
        int i = 1;
        while(i < n && nums[i - 1] < nums[i]) ++i;
        if(i == n)
            return nums[0];
        
        return nums[i];
    }
    
    // Binary Search - O(log(n))
    int findMinSecond(vector<int>& nums)
    {
        int n = nums.size();
        if(0 == n) return INT_MIN;
        if(1 == n) return nums[0];
        
        int head = 0, tail = n - 1;
        while(head < tail)
        {
            int mid = head + (tail - head) / 2;
            if(nums[mid] > nums[head])
                head = mid;
            else
                tail = mid;         // when head == mid, jump out of the loop
        }
        
        return std::min(nums[head + 1], nums[0]);   // handle with [0, 1, 2]
    }
};
