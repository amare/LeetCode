/*
 Author:            cuckoo
 Date:              2017/04/10 20:20:22
 Update:            
 Problem:           Range Sum Query 2D - Immutable
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/range-sum-query-2d-immutable/#/description

 */

#include <vector>
using std::vector;

class NumMatrix {
public:
    /* old
    NumMatrix(vector<vector<int>> matrix)
    {
        int row_size = matrix.size();
        if(row_size != 0)
        {
            int col_size = matrix[0].size();
            sums.resize(row_size + 1, vector<int>(col_size + 1, 0));
            for(int i = 1; i <= row_size; ++i)
            {
                for(int j = 1; j <= col_size; ++j)
                {
                    sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1];
                }
            }
        }
                
    }
    */
    
    NumMatrix(vector<vector<int>> matrix)
    {
        int row_size = matrix.size();
        if(row_size != 0)
        {
            int col_size = matrix[0].size();
            sums.resize(row_size + 1, vector<int>(col_size + 1, 0));
            for(int i = 1; i <= row_size; ++i)
            {
                int sum = 0;
                for(int j = 1; j <= col_size; ++j)
                {
                    sum += matrix[i-1][j-1];
                    sums[i][j] = sum + sums[i-1][j];
                }
            }
        }
                
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        /* handle with out of the bound
        int row_size = sums.size(), col_size = 0;
        if(row_size != 0)
            col_size = sums[0].size();
        if(row1 >= row_size - 1 || row2 >= row_size - 1 || col1 >= col_size - 1 || col2 >= col_size - 1)
            return 0;
        */   
        return (sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1]);
    }
    
private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
