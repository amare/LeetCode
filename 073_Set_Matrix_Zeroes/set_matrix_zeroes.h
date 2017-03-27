/*
 Author:            cuckoo
 Date:              2017/03/27 10:53:13
 Update:            
 Problem:           Set Matrix Zeroes
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/set-matrix-zeroes/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        return setZeroes_2(matrix);
    }
    
    void setZeroes_1(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        if(0 == m) return;
        int n = matrix[0].size();
        
        vector<vector<bool>> isAccessed(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(!isAccessed[i][j] && 0 == matrix[i][j])
                {
                    for(int k = 0; k < n; ++k)
                    {
                        if(matrix[i][k] != 0)
                        {
                            isAccessed[i][k] = true;
                            matrix[i][k] = 0;
                        }
                    }
                    for(int l = 0; l < m; ++l)
                    {
                        if(matrix[l][j] != 0)
                        {
                            isAccessed[l][j] = true;
                            matrix[l][j] = 0;
                        }
                    }
                }
            }
        }
    }
    
    // using last_zero_row to control which column to be set zero
    void setZeroes_2(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        if(0 == m) return;
        int n = matrix[0].size();
        
        // find last row where there is a zero element
        int last_zero_row = -1;
        for(int i = m - 1; i >= 0 && last_zero_row == -1; --i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    last_zero_row = i;
                    break;
                }
            }
        }
        if(last_zero_row == -1)
            return;
            
        // set column's element in last zero row to zero when this column has zero element
        // and set all elements in the row which has zero element to zero
        for(int i = 0; i < last_zero_row; ++i)
        {
            bool is_zero_current_row = false;
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[last_zero_row][j] = 0;
                    is_zero_current_row = true;
                }
            }
            if(is_zero_current_row)
            {
                for(int j = 0; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // set all elements in the column which has zero element in the last zero row to zero
        for(int j = 0; j < n; ++j)
        {
            if(matrix[last_zero_row][j] == 0)
            {
                for(int i = 0; i < m; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // set all elements in the last zero row to zero
        for(int j = 0; j < n; ++j)
        {
            matrix[last_zero_row][j] = 0;
        }
    }
};
