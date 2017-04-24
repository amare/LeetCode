/*
 Author:            cuckoo
 Date:              2017/04/24 21:53:03
 Update:            
 Problem:           Predict the Winner
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/predict-the-winner/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for max(), min()
#include <numeric>          // for accumulate()

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return PredictTheWinnerSecondOptimized(nums);
    }
    
    int Backtracking(vector<int> &nums, int head, int tail, int count)
    {
        if(head > tail)
        {
            return count;
        }
        
        int choose_head = std::min(Backtracking(nums, head + 1, tail - 1, count + nums[head]),
                            Backtracking(nums, head + 2, tail, count + nums[head]));
        int choose_tail = std::min(Backtracking(nums, head, tail - 2, count + nums[tail]),
                            Backtracking(nums, head + 1, tail - 1, count + nums[tail]));
        
        return std::max(choose_head, choose_tail);
        
    }
    bool PredictTheWinnerFirst(vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int max =  Backtracking(nums, 0, nums.size() - 1, 0);
        
        return max >= (sum + 1) / 2;
    }
    
    // Backtracking + memorization
    int BacktrackingTwo(vector<int> &nums, int head, int tail, vector<vector<int>> &memo)
    {
        if(head > tail)
            return 0;
            
        if(memo[head][tail] != -1)
            return memo[head][tail];
        
        int choose_head = nums[head] + std::min(BacktrackingTwo(nums, head + 1, tail - 1, memo),
                                        BacktrackingTwo(nums, head + 2, tail, memo));
        int choose_tail = nums[tail] + std::min(BacktrackingTwo(nums, head, tail - 2, memo),
                                        BacktrackingTwo(nums, head + 1, tail - 1, memo));
        memo[head][tail] = std::max(choose_head, choose_tail);
        
        return memo[head][tail];
        
    }
    bool PredictTheWinnerFirstOptimized(vector<int>& nums)
    {
        int n = nums.size();
        if(0 == n) return true;
        
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(n, vector<int>(n, -1));
        int max =  BacktrackingTwo(nums, 0, nums.size() - 1, memo);
        
        return max >= (sum + 1) / 2;
    }


    bool PredictTheWinnerSecond(vector<int>& nums)
    {
        int n = nums.size();
        if(0 == n) return true;
        // dp[i][j] represents how much more scores that the first-in-action player will get from i to j
        // than the second player.
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i)
            dp[i][i] = nums[i];
        
        for(int i = n - 2; i >= 0; --i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                dp[i][j] = std::max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] >= 0;
    }
    
    bool PredictTheWinnerSecondOptimized(vector<int>& nums)
    {
        int n = nums.size();
        if(0 == n) return true;
        
        vector<int> dp(n, 0);
        for(int i = n - 1; i >= 0; --i)
        {
            dp[i] = nums[i];
            for(int j = i + 1; j < n; ++j)
            {
                dp[j] = std::max(nums[i] - dp[j], nums[j] - dp[j-1]);
            }
        }
        
        return dp[n-1] >= 0;
    }
};
