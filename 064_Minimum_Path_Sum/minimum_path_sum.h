/*
 Author:            cuckoo
 Date:              2017/04/03 22:18:06
 Update:            
 Problem:           Minimum Path Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/minimum-path-sum/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for min()

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return minPathSum_1(grid);
    }
    
    int minPathSum_1(vector<vector<int>>& grid)
    {
        int size_x = grid.size();
        if(0 == size_x) return 0;
        int size_y = grid[0].size();
        if(0 == size_y) return 0;
        
        vector<int> dp_table(size_y, 0);
        dp_table[0] = grid[0][0];
        for(int j = 1; j < size_y; ++j)
            dp_table[j] = dp_table[j-1] + grid[0][j];
        for(int i = 1; i < size_x; ++i)
        {
            dp_table[0] = dp_table[0] + grid[i][0];
            for(int j = 1; j < size_y; ++j)
                dp_table[j] = std::min(dp_table[j], dp_table[j-1]) + grid[i][j];           
        }
        
        return dp_table[size_y-1];
    }
};
