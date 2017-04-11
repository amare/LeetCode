/*
 Author:            cuckoo
 Date:              2017/04/11 20:37:17
 Update:            
 Problem:           Integer Break
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/integer-break/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for max()

class Solution {
public:
    int integerBreak(int n) {
        return integerBreak_2(n);
    }
    
    // math
    int integerBreak_1(int n)
    {
        if(n == 2) return 1;
        if(n == 3) return 2;
        
        int result = 1, temp = n;
        while(temp > 4)
        {
            result *= 3;
            temp -= 3;
        }
        result *= temp;
        
        return result;
    }
    
    int integerBreak_2(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[2] = 1, dp[3] = 2;
        for(int i = 3; i <= n; ++i)
            for(int j = 1; j <= i / 2; ++j)
                dp[i] = std::max(dp[i], std::max(j, dp[j]) * std::max(i - j, dp[i - j]));
        
        return dp[n];
    }
};
