/*
 Author:            cuckoo
 Date:              2017/07/22 08:58:27
 Update:            
 Problem:           01 Matrix
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/01-matrix/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <utility>
using std::pair;
using std::make_pair;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        return UpdateMatrixThird(matrix);
    }
    
    // TLE
    vector<vector<int>> UpdateMatrixFirst(vector<vector<int>>& matrix)
    {
        if(matrix.empty())
            return {};
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > result(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                result[i][j] = DFSMatrix(matrix, i, j, 0);
            }                
        }
        
        return result;
    }
    
    int DFSMatrix(vector<vector<int> > &matrix, int row, int col, int distance)
    {
        int m = matrix.size(), n = matrix[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || matrix[row][col] == 2)
            return INT_MAX;
        
        int c = matrix[row][col];
        if(c == 0)
            return distance;
        
        matrix[row][col] = 2;
        int up = DFSMatrix(matrix, row + 1, col, distance + 1);
        int down = DFSMatrix(matrix, row - 1, col, distance + 1);
        int left = DFSMatrix(matrix, row, col + 1, distance + 1);
        int right = DFSMatrix(matrix, row, col - 1, distance + 1);
        matrix[row][col] = c;
        
        return std::min(up, std::min(down, std::min(left, right)));
    }
    
    // BFS
    vector<vector<int>> UpdateMatrixSecond(vector<vector<int>>& matrix)
    {
        if(matrix.empty())
            return {};
        
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > result(m, vector<int>(n, INT_MAX));
        
        queue<pair<int, int> > q;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    result[i][j] = 0;
                    q.push(make_pair(i, j));        // put all 0s in the queue
                }
            }
        }
        
        int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };       // direction: up, down, left, right
        while(!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();
            
            int row = current.first, col = current.second;
            for(int i = 0; i < 4; ++i)
            {
                int new_row = row + dir[i][0], new_col = col + dir[i][1];
                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && matrix[new_row][new_col] == 1)
                {
                    if(result[new_row][new_col] > result[row][col] + 1)
                    {
                        result[new_row][new_col] = result[row][col] + 1;
                        q.push(make_pair(new_row, new_col));
                    }
                }
            }
        }
        
        return result;
    }
    
    // Dynamic Programming
    vector<vector<int>> UpdateMatrixThird(vector<vector<int>>& matrix)
    {
        if(matrix.empty())
            return {};
        
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX - 100000));
        
        // First pass: check for top and left
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if(i > 0)
                        dp[i][j] = std::min(dp[i][j], dp[i-1][j] + 1);  // from top
                    if(j > 0)
                        dp[i][j] = std::min(dp[i][j], dp[i][j-1] + 1);  // from left
                }
            }
        }
        
        // Second pass: check for bottom and right
        for(int i =  m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(i < m - 1)
                    dp[i][j] = std::min(dp[i][j], dp[i+1][j] + 1);      // from bottom
                if(j < n - 1)
                    dp[i][j] = std::min(dp[i][j], dp[i][j+1] + 1);      // from right
            }
        }
        
        return dp;
    }
};
