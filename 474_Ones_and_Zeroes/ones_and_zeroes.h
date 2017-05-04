/*
 Author:            cuckoo
 Date:              2017/05/04 16:05:26
 Update:            
 Problem:           Ones and Zeroes
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/ones-and-zeroes/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>                // for max()

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return findMaxFormFirst(strs, m, n);
    }

    int findMaxFormFirst(vector<string>& strs, int m, int n)
    {
        if(m < 0 || n < 0)
            return 0;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int num_zero = 0, num_one = 0;
        
        for(auto &str : strs)
        {
            num_zero = num_one = 0;
            for(auto c : str)
            {
                if(c == '0')
                    ++num_zero;
                else
                    ++num_one;
            }
            
            for(int i = m; i >= num_zero; --i)
                for(int j = n; j >= num_one; --j)
                    dp[i][j] = std::max(dp[i][j], dp[i - num_zero][j - num_one] + 1);
        }
        
        return dp[m][n];
    }
};
