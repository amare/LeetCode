/*
 Author:            cuckoo
 Date:              2017/03/25 17:40:00
 Update:
 Problem:           Unique Paths
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/unique-paths/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return uniquePaths_3(m, n);
    }

    void searchPath(int row, int col, int &result, int m, int n)
    {
        if(row == m && col == n)
            result += 1;
        if(row > m || col > n)
            return;
        // turn to right
        if(col + 1 <= n)
            searchPath(row, col + 1, result, m, n);
        // turn to down
        if(row + 1 <= m)
            searchPath(row + 1, col, result, m, n);
    }
    // Time Limited Exceeded
    int uniquePaths_1(int m, int n)
    {
        int result = 0;
        searchPath(1, 1, result, m, n);

        return result;
    }
    // DP
    // f[i][j] means the number of unique paths to reach the position [i][j]
    int uniquePaths_2(int m, int n)
    {
        if(m == 0 || n == 0) return 0;
        // f[i][j] probabley beyond the range of int type
        vector<vector<long>> nums(m, vector<long>(n, 0));
        for(int j = 0; j < n; ++j)
            nums[0][j] = 1;
        for(int i = 1; i < m; ++i)
            nums[i][0] = 1;

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                nums[i][j] = nums[i-1][j] + nums[i][j-1];
            }
        }
        return nums[m-1][n-1];
    }
    // DP optimized
    int uniquePaths_3(int m, int n)
    {
        if(m == 0 || n == 0) return 0;
        // f[i][j] probabley beyond the range of int type
        vector<int> nums(n);
        for(int j = 0; j < n; ++j)
            nums[j] = 1;
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                nums[j] = nums[j-1] + nums[j];

        return nums[n-1];
    }
};
