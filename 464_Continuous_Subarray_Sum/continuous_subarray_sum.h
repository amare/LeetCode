/*
 Author:            cuckoo
 Date:              2017/04/25 20:28:58
 Update:            
 Problem:           Continuous Subarray Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/continuous-subarray-sum/#/description

 */

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <numeric>          // for accumulate()

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        return checkSubarraySumSecond(nums, k);
    }
    
    bool checkSubarraySumFirst(vector<int>& nums, int k)
    {
        int size = nums.size();
    
        // handle with (n * k == 0)
        for(int i = 0; i + 1 < size; ++i)
            if(nums[i] == 0 && nums[i + 1] == 0)        // if there are two continuous zero
                return true;
        
        if(k == 0) return false;            // make sure that (dp[j] % k) is valid
        
        // dp[i][j] represents the sum of sub-array from i to j in array
        // dp[i][j] = dp[i + 1][j] + nums[i];
        vector<int> dp(size, 0);
        for(int i = size - 1; i >= 0; --i)
        {
            dp[i] = nums[i];
            for(int j = i + 1; j < size; ++j)
            {
                dp[j] = dp[j] + nums[i];
                if(dp[j] % k == 0)
                    return true;
            }
        }
        
        return false;
    }

    bool checkSubarraySumSecond(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash = { {0, -1} };
        
        int running_sum = 0, n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            running_sum += nums[i];
            if(k != 0)
                running_sum %= k;
            
            auto iter = hash.find(running_sum);
            if(iter != hash.end() && i - iter->second > 1)
                return true;
            else
                hash.insert({running_sum, i});
        }
        
        return false;
    }
};
