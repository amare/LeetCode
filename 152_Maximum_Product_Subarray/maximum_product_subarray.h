/*
 Author:            cuckoo
 Date:              2017/04/07 22:41:06
 Update:            2017/07/14 21:44:10
 Problem:           Maximum Product Subarray
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/maximum-product-subarray/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for max()

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return MaxProductFirst(nums);
    }
    
    // best one
    int MaxProductFirst(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size)
            return 0;
            
        int result = nums[0];
        int max_current = nums[0];
        int min_current = nums[0];
        for(int i = 1; i < size; ++i)
        {
            if(nums[i] < 0)
                std::swap(max_current, min_current);
            
            max_current = std::max(max_current * nums[i], nums[i]);
            min_current = std::min(min_current * nums[i], nums[i]);
            
            result = std::max(result, max_current);
        }
        
        return result;
    }

    // update at 2017/07/14 21:46:21
    int MaxProductSecond(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> max_dp(n, nums[0]);     // max_dp[i] represents the maximum product value in the subarray ending with nums[i]
        vector<int> min_dp(n, nums[0]);     // min_dp[i] represents the minimum product value in the subarray ending with nums[i] 
        
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] < 0)
            {
                max_dp[i] = std::max(min_dp[i-1] * nums[i], nums[i]);
                min_dp[i] = std::min(max_dp[i-1] * nums[i], nums[i]);
            }
            else
            {
                max_dp[i] = std::max(max_dp[i-1] * nums[i], nums[i]);
                min_dp[i] = std::min(min_dp[i-1] * nums[i], nums[i]);
            }
        }
        
        int result = nums[0];
        for(auto num : max_dp)
            result = std::max(result, num);
        
        return result;
    }
};
