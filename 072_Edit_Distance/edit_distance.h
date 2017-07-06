/*
 Author:            cuckoo
 Date:              2017/07/05 10:49:20
 Update:            
 Problem:           Edit Distance
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/edit-distance/#/description

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>        // for min()

class Solution {
public:
    int minDistance(string word1, string word2) {
        return minDistanceFirst(word1, word2);
    }
    
    // Dynamic Programming
    int minDistanceFirst(string &word1, string &word2)
    {
        int size1 = word1.size(), size2 = word2.size();
        
        // dp[i][j] means the minimum number of steps required to convert word1.substr(0, i) to word2.substr(0, j)
        vector<vector<int> > dp(size1 + 1, vector<int>(size2 + 1, 0));
        dp[0][0] = 0;
        for(int i = 1; i <= size1; ++i)
            dp[i][0] = i;   // operation delete
        for(int j = 1; j <= size2; ++j)
            dp[0][j] = j;   // operation insert
        
        for(int i = 1; i <= size1; ++i)
        {
            for(int j = 1; j <= size2; ++j)
            {
                dp[i][j] = std::min(dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1),  // operation replace
                                   std::min(dp[i-1][j] + 1, dp[i][j-1] + 1));       // operation delete and insert
            }
        }
        
        return dp[size1][size2];
    }
};
