/*
 Author:            cuckoo
 Date:              2017/03/21 10:03:04
 Update:
 Problem:           Maximum Subarray
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/maximum-subarray

 */

#include <vector>
using std::vector;

#include <algorithm>    // for max()

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_2(nums);
    }

    // Dynamic Programming - Time Limit Exceeded
    int maxSubArray_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return INT_MIN;

        int result = nums[0];
        // table[i][j] means the sum of the subarray of [i,...,j]
        vector<vector<int>> table(size, vector<int>(size, nums[0]));

        table[0][0] = nums[0];
        for(int k = 1; k < size; ++k)
        {
            table[0][k] = table[0][k-1] + nums[k];
            result = std::max(result, table[0][k]);
        }

        for(int i = 1; i < size; ++i)
        {
            for(int j = i; j < size; ++j)
            {
                table[i][j] = table[i-1][j] - nums[i-1];
                result = std::max(result, table[i][j]);
            }
        }

        return result;
    }

    // ======
    int maxSubArray_2(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return INT_MIN;

        int result = nums[0];
        // table means the maximum subarray ending with nums[i]
        vector<int> table(size, INT_MIN);
        table[0] = nums[0];
        for(int i = 1; i < size; ++i)
        {
            table[i] = nums[i] + (table[i-1] > 0 ? table[i-1] : 0);
            result = std::max(result, table[i]);
        }

        return result;
    }
};
