/*
 Author:            cuckoo
 Date:              2017/04/11 19:44:37
 Update:            
 Problem:           Counting Bits
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/counting-bits/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        return countBits_2(num);
    }
    
    vector<int> countBits_1(int num)
    {
        // i & (i - 1) is equal to the old i whose original right-most 1 bit is set to 0
        vector<int> dp(num + 1, 0);
        dp[0] = 0;
        for(int i = 1; i <= num; ++i)
            dp[i] = dp[i & (i - 1)] + 1;
        
        return dp;
    }
    
    vector<int> countBits_2(int num)
    {
        vector<int> dp(num + 1, 0);
        dp[0] = 0;
        for(int i = 1; i <= num; ++i)
            dp[i] = dp[i >> 1] + (i & 1);
        
        return dp;
    }
};
