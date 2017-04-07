/*
 Author:            cuckoo
 Date:              2017/04/07 16:33:39
 Update:            
 Problem:           Triangle
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/triangle/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for min()

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return minimumTotal_1(triangle);
    }
    
    int minimumTotal_1(vector<vector<int>>& triangle)
    {
        int level = triangle.size();
        if(0 == level || 0 == triangle[0].size()) return 0;
        
        vector<int> dp(level, 0);
        dp[0] = triangle[0][0];
        
        for(int row = 1; row < level; ++row)
        {
            triangle[row].resize(row+1);    // handle with invalid triangle
            
            int dp_pre_col = dp[0];        // make a copy because the old value will be changed
            dp[0] = triangle[row][0] + dp[0];
            for(int col = 1; col < row; ++col)
            {
                int dp_cur_col = dp[col];
                dp[col] = triangle[row][col] + std::min(dp_pre_col, dp[col]);
                dp_pre_col = dp_cur_col;
            }
            dp[row] = triangle[row][row] + dp_pre_col;
        }
        /*
        // more clear
        for(int row = 1; row < level; ++row)
        {
            vector<int> dp_copy(dp);        // make a copy because the old value will be changed
            dp[0] = triangle[row][0] + dp_copy[0];
            for(int col = 1; col < row; ++col)
                dp[col] = triangle[row][col] + min(dp_copy[col-1], dp_copy[col]);
            dp[row] = triangle[row][row] + dp_copy[row-1];
        }
        */
        
        int result = dp[0];
        for(int i = 1; i < level; ++i)
            if(dp[i] < result)
                result = dp[i];
        
        return result;
    }
    
    
    int minimumTotal_2(vector<vector<int>>& triangle)
    {
        int level = triangle.size();
        if(0 == level || 0 == triangle[0].size()) return 0;
        
        vector<vector<int>> dp(level);
        dp[0].resize(1);
        dp[0][0] = triangle[0][0];
        
        for(int row = 1; row < level; ++row)
        {
            triangle[row].resize(row+1);
            dp[row].resize(row+1);
            
            dp[row][0] = triangle[row][0] + dp[row-1][0];
            for(int col = 1; col < row; ++col)
                dp[row][col] = triangle[row][col] + std::min(dp[row-1][col-1], dp[row-1][col]);
            dp[row][row] = triangle[row][row] + dp[row-1][row-1];
        }

        int result = dp[level-1][0];
        for(int j = 1; j < level; ++j)
            if(dp[level-1][j] < result)
                result = dp[level-1][j];
        
        return result;
    }
};
