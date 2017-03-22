/*
 Author:            cuckoo
 Date:              2017/03/22 20:20:50
 Update:
 Problem:           Spiral Matrix
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/spiral-matrix

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return spiralOrder_1(matrix);
    }

    void LeftToRight(vector<vector<int>> &matrix, int i, int left_limit, int right_limit, vector<int> &result, int &count)
    {
        for(int j = left_limit; j <= right_limit; ++j)
        {
            result.push_back(matrix[i][j]);
            ++count;
        }
    }
    void TopToBottom(vector<vector<int>> &matrix, int j, int top_limit, int bottom_limit, vector<int> &result, int &count)
    {
        for(int i = top_limit; i <= bottom_limit; ++i)
        {
            result.push_back(matrix[i][j]);
            ++count;
        }
    }

    void RightToLeft(vector<vector<int>> &matrix, int i, int right_limit, int left_limit, vector<int> &result, int &count)
    {
        for(int j = right_limit; j >= left_limit; --j)
        {
            result.push_back(matrix[i][j]);
            ++count;
        }
    }
    void BottomToTop(vector<vector<int>> &matrix, int j, int bottom_limit, int top_limit, vector<int> &result, int &count)
    {
        for(int i = bottom_limit; i >= top_limit; --i)
        {
            result.push_back(matrix[i][j]);
            ++count;
        }
    }
    vector<int> spiralOrder_1(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int m = matrix.size();
        if(0 == m) return result;

        int n = matrix[0].size();
        int count = 0;
        int left_limit = 0, right_limit = n - 1;
        int top_limit = 0, bottom_limit = m - 1;

        while(count < m * n)
        {
            LeftToRight(matrix, top_limit, left_limit, right_limit, result, count); ++top_limit;
            if(count >= m * n) break;
            TopToBottom(matrix, right_limit, top_limit, bottom_limit, result, count); --right_limit;
            if(count >= m * n) break;
            RightToLeft(matrix, bottom_limit, right_limit, left_limit, result, count); --bottom_limit;
            if(count >= m * n) break;
            BottomToTop(matrix, left_limit, bottom_limit, top_limit, result, count); ++left_limit;
        }

        return result;
    }

    vector<int> spiralOrder_1_concise(vector<vector<int>> &matrix)
    {
        if(matrix.empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> result(m * n, 0);   // allocation of spaces in advance is faster.

        int count = 0;
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;

        while(true)
        {
            for(int j = left; j <= right; ++j) result[count++] = matrix[top][j];
            if(++top > bottom) break;
            for(int i = top; i <= bottom; ++i) result[count++] = matrix[i][right];
            if(--right < left) break;
            for(int j = right; j >= left; --j) result[count++] = matrix[bottom][j];
            if(--bottom < top) break;
            for(int i = bottom; i >= top; --i) result[count++] = matrix[i][left];
            if(++left > right) break;
        }

        return result;
    }
};
