/*
 Author:            cuckoo
 Date:              2017/04/23 16:59:10
 Update:            
 Problem:           Target Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/target-sum/#/description

 */

#include <vector>
using std::vector;

#include <numeric>          // for accumulate()

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWaysThirdOptimized(nums, S);
    }
    
    // O(2^n)
    void Backtracking(vector<int> &nums, int start, int target, int &count)
    {
        if(start == nums.size())
        {
            if(target == 0)
                ++count;
            return;
        }
        
        Backtracking(nums, start + 1, target - nums[start], count);
        Backtracking(nums, start + 1, target + nums[start], count);
    }
    int findTargetSumWaysFirst(vector<int>& nums, int S)
    {
        int count = 0;
        Backtracking(nums, 0, S, count);
        
        return count;
    }
    
    // 0/1 knapsack
    int findTargetSumWaysThird(vector<int> &nums, int S)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(S < -sum || S > sum) return 0;
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, 0));
        
        if(nums[0] == 0)
            dp[0][sum] = 2;
        else
            dp[0][sum + nums[0]] = dp[0][sum - nums[0]] = 1;
        
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < 2 * sum + 1; ++j)
            {
                if(j + nums[i] < 2 * sum + 1)
                    dp[i][j] += dp[i-1][j + nums[i]];
                if(j - nums[i] >= 0)
                    dp[i][j] += dp[i-1][j - nums[i]];
            }
        }

        return dp[n-1][sum + S];
    }
    
    // space complexity : O(n)
    int findTargetSumWaysThirdOptimized(vector<int> &nums, int S)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(S < -sum || S > sum) return 0;
        
        int n = nums.size();
        vector<int> dp(2 * sum + 1, 0);
        
        if(nums[0] == 0)
            dp[sum] = 2;
        else
            dp[sum + nums[0]] = dp[sum - nums[0]] = 1;
        
        for(int i = 1; i < n; ++i)
        {
            vector<int> dp_next(2 * sum + 1, 0);
            for(int j = 0; j < 2 * sum + 1; ++j)
            {
                if(j + nums[i] < 2 * sum + 1)
                    dp_next[j] += dp[j + nums[i]];
                if(j - nums[i] >= 0)
                    dp_next[j] += dp[j - nums[i]];   
            }
            dp = dp_next;
        }
        
        return dp[sum + S];
    }
};
