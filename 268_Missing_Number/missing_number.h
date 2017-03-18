/*
 Author:            cuckoo
 Date:              2017/03/17 20:35:53
 Update:
 Problem:           Missing Number
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/missing-number

 */

#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return missingNumber_1(nums);
    }

    int missingNumber_1(vector<int>& nums)
    {
        int size = nums.size();
        vector<bool> exist_flag(size + 1, false);
        for(auto i : nums)
        {
            exist_flag[i] = true;
        }
        for(int i = 0; i < size + 1; ++i)
        {
            if(!exist_flag[i])
                return i;
        }

        return 0;
    }

    // xor
    int missingNumber_2(vector<int>& nums)
    {
        int result = nums.size();
        int i = 0;
        for(auto num : nums)
        {
            result ^= num;
            result ^= i;
            ++i;
        }

        return result;
    }
};
