/*
 Author:            cuckoo
 Date:              2017/04/23 10:24:46
 Update:            
 Problem:           Longest Palindromic Subsequence
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/longest-palindromic-subsequence/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>        // for max()

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return longestPalindromeSubseqThird(s);
    }
    
    int longestPalindromeSubseqFirst(string s)
    {
        int n = s.size();
        if(0 == n) return 0;
        
        // dp[i][j] represent the longest palindromic subsequence's length in substring(i, j)
        // i <= j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }
    
    // Evolved version derived from First Solution
    int longestPalindromeSubseqSecond(string s)
    {
        int n = s.size();
        if(0 == n) return 0;
        
        // dp[i][j] represent the longest palindromic subsequence's length in substring(i, j)
        // i <= j
        vector<int> dp(n, 0);
        int prev = 0, current = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            dp[i] = 1;
            prev = 0;
            for(int j = i + 1; j < n; ++j)
            {
                current = dp[j];
                if(s[i] == s[j])
                    dp[j] = prev + 2;
                else
                    dp[j] = std::max(dp[j], dp[j-1]);
                
                prev = current;
            }
        }
        
        return dp[n-1];
    }
    
    // Top to Bottom recursive version with memoization
    int longestPalindromeSubseqThirdAux(string &s, int i, int j, vector<vector<int>> &memo)
    {
        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(s[i] == s[j])
            memo[i][j] = longestPalindromeSubseqThirdAux(s, i + 1, j - 1, memo) + 2;
        else
            memo[i][j] = std::max(longestPalindromeSubseqThirdAux(s, i + 1, j, memo),
                            longestPalindromeSubseqThirdAux(s, i, j - 1, memo));
        
        return memo[i][j];
    }
    int longestPalindromeSubseqThird(string &s)
    {
        int n = s.size();
        if(0 == n) return 0;
        
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return longestPalindromeSubseqThirdAux(s, 0, n - 1, memo);
    }
};
