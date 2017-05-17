/*
 Author:            cuckoo
 Date:              2017/05/08 20:34:43
 Update:            
 Problem:           Summary Ranges
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/summary-ranges/#/description

 */

#include <vector>
using std::vector;

#include <string>           // for to_string()
using std::string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        return summaryRangesFirst(nums);
    }
    
    vector<string> summaryRangesFirst(vector<int>& nums)
    {
        vector<string> result;
        
        int n = nums.size(), start = 0, end = 0;
        while(end < n)
        {
            start = end;
            ++end;
            while(end < n && nums[end] - nums[end - 1] == 1)
                ++end;
            
            string temp = std::to_string(nums[start]);
            if(end - 1 != start)
                temp += "->" + std::to_string(nums[end - 1]);
            result.push_back(std::move(temp));
        }
        
        return result;
    }

    int BinarySearch(vector<int> &nums, int low, int high)
    {
        while(low + 1 < high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] - nums[low] == mid - low)
                low = mid;
            else
                high = mid;
        }
        
        return low;
    }
    vector<string> summaryRangesSecond(vector<int>& nums)
    {
        vector<string> result;
        
        int n = nums.size(), k = 0;
        for(int i = 0; i < n; i = k + 1)
        {
            k = BinarySearch(nums, i, n);
            if(i != k)
                result.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[k]));
            else
                result.push_back(std::to_string(nums[i]));
        }
        
        return result;
    }
};
