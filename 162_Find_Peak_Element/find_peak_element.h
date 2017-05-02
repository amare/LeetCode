/*
 Author:            cuckoo
 Date:              2017/04/28 16:24:26
 Update:            
 Problem:           Find Peak Element
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/find-peak-element/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElementSecond(nums);
    }
    
    int findPeakElementFirst(vector<int> &nums)
    {
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i)
            if(nums[i] > nums[i + 1])
                return i;
                
        return n - 1;
    }
    
    int findPeakElementSecond(vector<int> &nums)
    {
        int n = nums.size();
        if(0 == n) return -1;
        if(1 == n) return 0;
        if(2 == n) return nums[0] > nums[1] ? 0 : 1;
        
        int low = 0, high = n - 1;
        while(low + 2 <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            if(nums[mid - 1] > nums[mid])
                high = mid;
            else
                low = mid;
        }
        
        return nums[low] > nums[high] ? low : high;
    }
};
