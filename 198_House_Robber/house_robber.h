/*
 Author:            cuckoo
 Date:              2017/04/08 09:36:04
 Update:            
 Problem:           House Robber
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/house-robber/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for max()

class Solution {
public:
    int rob(vector<int>& nums) {
        return rob_2(nums);
    }
    
    int rob_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return 0;
        if(1 == size) return nums[0];
        if(2 == size) return std::max(nums[0], nums[1]);
        
        vector<int> dp(size);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < size; ++i)
            dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
        
        return dp[size-1];
    }
    
    int rob_2(vector<int>& nums)
    {
        int size = nums.size();
        
        int previous_prev = 0, previous = 0;
        for(int i = 0; i < size; ++i)
        {
            int current = std::max(previous_prev + nums[i], previous);
            previous_prev = previous;
            previous = current;
        }
        
        return previous;
    }
};
