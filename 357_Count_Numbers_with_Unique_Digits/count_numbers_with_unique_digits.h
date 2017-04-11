/*
 Author:            cuckoo
 Date:              2017/04/11 21:35:22
 Update:            
 Problem:           Count Numbers with Unique Digits
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/count-numbers-with-unique-digits/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        return countNumbersWithUniqueDigits_2(n);
    }
    
    int permutation(int n, int r)
    {
        if(r == 0)
            return 1;
        return n * permutation(n - 1, r - 1);
    }
    
    int countNumbersWithUniqueDigits_1(int n)
    {
        if(0 == n) return 1;
        int sum = 1;
        int end = n > 10 ? 10 : n;
        for(int i = 0; i < end; ++i)
            sum += 9 * permutation(9, i);
        
        return sum;
    }
    
    int countNumbersWithUniqueDigits_2(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        int end = n > 10 ? 10 : n;
        for(int index = 1; index <= end; ++index)
            dp[index] = 9 * permutation(9, index - 1) + dp[index - 1];
            
        return end == 10 ? dp[10] : dp[n];
    }
};
