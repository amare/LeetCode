/*
 Author:            cuckoo
 Date:              2017/04/28 15:46:54
 Update:            
 Problem:           Search in Rotated Sorted Array II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/search-in-rotated-sorted-array-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return searchSecond(nums, target);
    }
    
    /* wrong
    bool searchFirst(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            
            if(nums[low] < nums[high])
            {
                if(target < nums[low] || target > nums[high])
                    return false;
                if(target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(target > nums[high])
                {
                    if(target < nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        } 
        
        return false;
    }
    */
    
    bool searchSecond(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            
            // the only difference from the first one, trickly case, just update low and high
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                ++low;
                --high;
            }
            
            else if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return false;
    }
};
