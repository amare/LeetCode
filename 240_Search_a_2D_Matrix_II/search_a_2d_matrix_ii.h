/*
 Author:            cuckoo
 Date:              2017/04/04 17:10:27
 Update:            
 Problem:           Search a 2D Matrix II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/search-a-2d-matrix-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix_1(matrix, target);
    }
    
    bool searchMatrix_1(vector<vector<int>>& matrix, int target)
    {
        int size_x = matrix.size(), size_y;
        if(size_x == 0 || (size_y = matrix[0].size()) == 0)
            return false;
        
        int row = 0, col = size_y - 1;
        while(row < size_x && col >= 0)
        {
            if(target == matrix[row][col]) return true;
            if(target < matrix[row][col]) --col;
            else ++row;
        }
        
        return false;
    }
};
