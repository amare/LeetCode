/*
 Author:            cuckoo
 Date:              2017/06/29 11:00:56
 Update:            
 Problem:           Interleaving String
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/interleaving-string/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleaveSecond(s1, s2, s3);
    }
    
    // TLE
    bool isInterleaveFirst(string &s1, string &s2, string &s3)
    {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        
        return size1 + size2 == size3
                ? isInterleaveFirstAux(0, s1, 0, s2, 0, s3)
                : false;
    }
    
    bool isInterleaveFirstAux(int i, string &s1, int j, string &s2, int k, string &s3)
    {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        
        // when i == size1 && j == size2, k must be equal to size3
        if(i == size1 && j == size2)
            return true;
        
        // s1 or s2 has no char
        if(i == size1)
            return s2.substr(j) == s3.substr(k);
        if(j == size2)
            return s1.substr(i) == s3.substr(k);
            
        // i != size1 && j != size2
        if(s1[i] == s3[k] && s2[j] == s3[k])
            return isInterleaveFirstAux(i+1, s1, j, s2, k+1, s3) || isInterleaveFirstAux(i, s1, j+1, s2, k+1, s3);
        if(s1[i] == s3[k] && s2[j] != s3[k])
            return isInterleaveFirstAux(i+1, s1, j, s2, k+1, s3);
        if(s1[i] != s3[k] && s2[j] == s3[k])
            return isInterleaveFirstAux(i, s1, j+1, s2, k+1, s3);
        
        return false;
    }
    
    // Dynamic Programming
    bool isInterleaveSecond(string &s1, string &s2, string &s3)
    {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        if(size1 + size2 != size3)
            return false;
        
        // dp[i][j] means whether s3.substr(0, i+j) is formed by the interleaving of s1.substr(0, i) and s2.substr(0, j). 
        vector<vector<bool>> dp(size1+1, vector<bool>(size2+1, false));
        dp[0][0] = true;
        for(int j = 1, k = 1; j <= size2; ++j, ++k)
            dp[0][j] = s2[j-1] == s3[k-1] && dp[0][j-1];
        for(int i = 1, k = 1; i <= size1; ++i, ++k)
            dp[i][0] = s1[i-1] == s3[k-1] && dp[i-1][0];
        
        for(int i = 1; i <= size1; ++i)
        {
            for(int j = 1; j <= size2; ++j)
            {
                if(s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if(s1[i-1] == s3[i+j-1])
                    dp[i][j] = dp[i-1][j];
                else if(s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[size1][size2];
    }
};
