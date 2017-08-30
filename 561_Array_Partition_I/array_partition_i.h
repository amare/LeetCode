/*
 Author:            cuckoo
 Date:              2017/07/28 09:39:43
 Update:            
 Problem:           Array Partition I
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/array-partition-i/tabs/solution

 */

#include <vector>
using std::vector;

#include <limits>               // for std::numeric_limits

#include <algorithm>            // for std::sort()

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        return ArrayPairSumFirst(nums);
    }
    
    int ArrayPairSumFirst(vector<int>& nums)
    {
        int n = nums.size();
        if(n & 0x01)
            return std::numeric_limits<int>::min();
        
        std::sort(nums.begin(), nums.end());
        
        int result = 0;
        for(int i = 0; i < n; i += 2)
            result += nums[i];
        
        return result;
    }
};
