/*
 Author:            cuckoo
 Date:              2017/06/03 10:27:39
 Update:            
 Problem:           Shortest Unsorted Continuous Subarray
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/shortest-unsorted-continuous-subarray/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for sort(), max()

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        return FindUnsortedSubarraySecond(nums);
    }
    
    int FindUnsortedSubarrayFirst(vector<int>& nums)
    {
        // check if the input is valid
        
        //
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        int start = 0, end = copy.size() - 1;
        while(start < copy.size() && copy[start] == nums[start])
            ++start;
        while(end >= 0 && copy[end] == nums[end])       // end >= start will be better
            --end;
            
        return start >= end ? 0 : end + 1 - start;
    }
    
    int FindUnsortedSubarraySecond(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
        
        int n = nums.size();
        int max_value = nums[0], min_value = nums[n-1];
        int end = -1;
        for(int i = 1; i < n; ++i)
        {
            max_value = std::max(max_value, nums[i]);
            if(nums[i] < max_value)
                end = i;
        }
        int start = -1;
        for(int j = n - 2; j >= 0; --j)
        {
            min_value = std::min(min_value, nums[j]);
            if(nums[j] > min_value)
                start = j;
        }
        
        return start == -1 ? 0 : end + 1 - start;
    }
};
