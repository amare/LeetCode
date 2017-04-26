/*
 Author:            cuckoo
 Date:              2017/04/26 21:37:56
 Update:            
 Problem:           Remove Duplicates from Sorted Array II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicatesFirst(nums);
    }
    
    
    int removeDuplicatesFirst(vector<int>& nums)
    {
        int count = 0;
        for(auto num : nums)
        {
            if(count < 2 || num > nums[count - 2])
                nums[count++] = num;
        }
        
        return count;
    }
};
