/*
 Author:            cuckoo
 Date:              2017/04/20 22:01:59
 Update:            
 Problem:           Search a 2D Matrix
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/search-a-2d-matrix/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix2(matrix, target);
    }
    
    bool searchMatrix1(vector<vector<int>>& matrix, int target)
    {
        int all_row = matrix.size();
        if(all_row == 0 || matrix[0].size() == 0) return false;
        
        int row = 0, col = matrix[0].size() - 1;
        while(row < all_row && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            
            if(matrix[row][col] < target)
                ++row;
            else
                --col;
        }
        
        return false;
    }
    
    // treat this 2D matrix as a sorted array
    // matrix[i][j] => array[i * n + j]
    // array[i] => matrix[i / n][i % n]
    bool searchMatrix2(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size(), n = 0;
        if(m == 0 || (n = matrix[0].size()) == 0)
            return false;
            
        int head = 0, tail = m * n - 1;
        while(head <= tail)
        {
            int mid = head + (tail - head) / 2;
            if(matrix[mid / n][mid % n] == target)
                return true;
            else if(matrix[mid / n][mid % n] < target)
                head = mid + 1;
            else
                tail = mid - 1;
        }
        
        return false;
    }
};
