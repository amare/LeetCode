/*
 Author:            cuckoo
 Date:              2017/03/17 20:35:53
 Update:            2017/07/20 18:15:16
 Problem:           Missing Number
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/missing-number

 */

#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return MissingNumberThird(nums);
    }
    
    int MissingNumberFirst(vector<int>& nums)
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
    // all elements except one occur twice, find the one that occurs once
    int MissingNumberSecond(vector<int>& nums)
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
    
    // from LintCode - update at 2017/07/20 18:15:16
    int MissingNumberThird(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            while(nums[i] != i && nums[i] < n)
                std::swap(nums[i], nums[nums[i]]);
        }
        
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i)
                return i;
        
        return n;
    }
};
