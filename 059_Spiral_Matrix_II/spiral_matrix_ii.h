/*
 Author:            cuckoo
 Date:              2017/04/20 21:06:18
 Update:            
 Problem:           Spiral Matrix II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/spiral-matrix-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        return generateMatrix1(n);
    }
    
    vector<vector<int>> generateMatrix1(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int value = 0;
        
        while(true)
        {
            for(int j = left; j <= right; ++j) matrix[top][j] = ++value;
            if(++top > bottom) break;
            for(int i = top; i <= bottom; ++i) matrix[i][right] = ++value;
            if(--right < left) break;
            for(int j = right; j >= left; --j) matrix[bottom][j] = ++value;
            if(--bottom < top) break;
            for(int i = bottom; i >= top; --i) matrix[i][left] = ++value;
            if(++left > right) break;
        }
        
        return matrix;
    }
};
