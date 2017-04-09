/*
 Author:            cuckoo
 Date:              2017/04/08 11:32:17
 Update:            
 Problem:           Maximal Square
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/maximal-square/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for min(), max(), pow(), sqrt()

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        return maximalSquare_1(matrix);
    }
    
    int maximalSquare_1(vector<vector<char>>& matrix)
    {
        int size_row = matrix.size();
        if(0 == size_row || 0 == matrix[0].size()) return 0;
        int size_col = matrix[0].size();
        
        // dp[row][col] represent the max-area from coordinate [row,col] to lower-right-corner of the matrix 
        vector<vector<int>> dp(size_row, vector<int>(size_col, 0));
        for(int row = size_row - 1; row >= 0; --row)
            dp[row][size_col-1] = matrix[row][size_col-1] == '0' ? 0 : 1;
        for(int col = size_col - 1; col >= 0; --col)
            dp[size_row-1][col] = matrix[size_row-1][col] == '0' ? 0 : 1;
        
        for(int row = size_row - 2; row >= 0; --row)
        {
            for(int col = size_col - 2; col >= 0; --col)
            {
                if(matrix[row][col] == '1')
                {
                    int min_area = std::min(dp[row+1][col+1], std::min(dp[row][col+1], dp[row+1][col]));
                    dp[row][col] = std::pow(std::sqrt(min_area) + 1, 2);
                }
                else
                    dp[row][col] = 0;
            }
        }
        
        int result = 0;
        for(auto &v : dp)
            for(auto i : v)
                result = std::max(result, i);
        
        return result;
    }
};
