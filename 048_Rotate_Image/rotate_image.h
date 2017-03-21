/*
 Author:            cuckoo
 Date:              2017/03/20 17:01:20
 Update:
 Problem:           Rotate Image
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/rotate-image

 */

#include <vector>
using std::vector;

#include <algorithm>    // for swap(), reverse()

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        rotate_1(matrix);
    }

    void rotate_1(vector<vector<int>>& matrix)
    {
        int size = matrix.size();
        for(int i = 0; i <= size / 2 - 1; ++i)
        {
            for(int j = i; j < size - 1 - i; ++j)
            {
                std::swap(matrix[i][j], matrix[j][size-1-i]);
                std::swap(matrix[i][j], matrix[size-1-i][size-1-j]);
                std::swap(matrix[i][j], matrix[size-1-j][i]);
            }
        }
    }

    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
     */
    void rotate_2(vector<vector<int>>& matrix)
    {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = i + 1; j < matrix[i].size(); ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
