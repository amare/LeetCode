/*
 Author:            cuckoo
 Date:              2017/04/19 22:35:18
 Update:            
 Problem:           Guess Number Higher or Lower II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/guess-number-higher-or-lower-ii/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for min(), max()

class Solution {
public:
    int getMoneyAmount(int n) {
        return getMoneyAmount2(n);
    }
    
    // recursive + memoization
    int recursive(int start, int end, vector<vector<int>> &dp)
    {
        if(start >= end)
            return 0;
        
        if(dp[start][end] != INT_MAX)
            return dp[start][end];
        
        for(int i = start; i <= end; ++i)
            dp[start][end] = std::min(dp[start][end], i + std::max(recursive(start, i - 1, dp), recursive(i + 1, end,dp)));
        
        return dp[start][end];
    }
    int getMoneyAmount1(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        return recursive(1, n, dp);
    }
    
    // Bottom to Up
    int getMoneyAmount2(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int j = 2; j <= n; ++j)
        {
            for(int i = j - 1; i >= 0; --i)
            {
                
                dp[i][j] = i == j - 1 ? i : INT_MAX;
                for(int k = i + 1; k < j; ++k)
                {
                    dp[i][j] = std::min(dp[i][j] , k + std::max(dp[i][k-1], dp[k+1][j]));
                }
            }
        }
        
        return dp[1][n];
    }
};
