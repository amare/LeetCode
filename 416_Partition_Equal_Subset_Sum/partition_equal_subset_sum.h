/*
 Author:            cuckoo
 Date:              2017/04/22 15:23:17
 Update:            
 Problem:           Partition Equal Subset Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/partition-equal-subset-sum/#/description

 */

#include <vector>
using std::vector;

#include <numeric>        // for accumulate()

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        return canPartitionThird(nums);
    }
    
    // Time Limit Exceeded
    bool Backtracking(vector<int> &nums, int start, int count, int n)
    {
        if(start == n)
        {
            return count == 0 ? true : false;
        }
        
        for(int i = start; i < n; ++i)
        {
            if(Backtracking(nums, i + 1, count + nums[i], n) ||
                Backtracking(nums, i + 1, count - nums[i], n))
                return true;
        }
        
        return false;
    }
    bool canPartitionFirst(vector<int>& nums)
    {
        return Backtracking(nums, 0, 0, nums.size());
    }
    
    
    // DFS Solution - TLE
    bool BacktrackingSecond(vector<int> &nums, int start, int target, int n)
    {
        if(target <= 0)
            return target == 0;
        
        for(int i = start; i < n; ++i)
        {
            if(BacktrackingSecond(nums, i + 1, target - nums[i], n))
                return true;
        }
        return false;
    }
    bool canPartitionSecond(vector<int>& nums)
    {
        int target = std::accumulate(nums.begin(), nums.end(), 0);
        if(target & 0x1) return false;
        
        return BacktrackingSecond(nums, 0, target >> 1, nums.size());
    }
    
    // 0/1 knapsack
    bool canPartitionThird(vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum & 0x1)
            return false;
        
        sum >>= 1;
        
        int n = nums.size();
        // dp[i][j] represents whether the specific sum j can be gotten from the ith number
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        
        for(int j = 1; j < sum + 1; ++j)
            dp[0][j] = false;
        for(int i = 1; i < n + 1; ++i)
            dp[i][0] = true;
        
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 1; j < sum + 1; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};
