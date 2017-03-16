/*
 Author:            cuckoo
 Date:              2017/03/16 22:07:01
 Update:
 Problem:           Search for a Range
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/search-for-a-range

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange_1(nums, target);
    }

    vector<int> searchRange_1(vector<int>& nums, int target)
    {
        vector<int> result = {-1, -1};
        int low = 0;
        int high = nums.size() - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        if(!nums.empty() && nums[low] == target)
            result[0] = low;

        high = nums.size() - 1;
        while(low < high)
        {
            int mid = (low + high) / 2 + 1;     // ^attention
            if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid;

        }
        if(!nums.empty() && nums[high] == target)
            result[1] = high;

        return result;
    }

    vector<int> searchRange_2(vector<int>& nums, int target)
    {
        auto idx1 = lower_bound(nums.begin(), nums.end(), target);
        auto idx2 = lower_bound(nums.begin(), nums.end(), target + 1) - 1;
        if (idx1 != nums.end() && *idx1 == target)
            return {idx1 - nums.begin(), idx2 - nums.begin()};
        else
            return {-1, -1};
    }
};
