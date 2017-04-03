/*
 Author:            cuckoo
 Date:              2017/04/03 21:54:24
 Update:            
 Problem:           Unique Paths II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/unique-paths-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return uniquePathsWithObstacles_2(obstacleGrid);
    }
    
    // DP without optimization
    int uniquePathsWithObstacles_1(vector<vector<int>>& obstacleGrid)
    {
        int size_x = obstacleGrid.size();
        if(0 == size_x)
            return 0;
        int size_y = obstacleGrid[0].size();
        if(0 == size_y)
            return 0;
            
        vector<vector<int>> dp_table(size_x, vector<int>(size_y, 0));
        for(int i = 0; i < size_x; ++i)
        {
            if(obstacleGrid[i][0] == 1)
                break;
            dp_table[i][0] = 1;
        }
        for(int j = 0; j < size_y; ++j)     // obstacleGrid[0][0] == 1
        {
            if(obstacleGrid[0][j] == 1)
                break;
            dp_table[0][j] = 1;
        }

        for(int i = 1; i < size_x; ++i)
            for(int j = 1; j < size_y; ++j)
                if(obstacleGrid[i][j] != 1)
                    dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1];
        
        return dp_table[size_x-1][size_y-1];
    }
    
    // DP optimized
    int uniquePathsWithObstacles_2(vector<vector<int>>& obstacleGrid)
    {
        int size_x = obstacleGrid.size();
        if(0 == size_x)
            return 0;
        int size_y = obstacleGrid[0].size();
        if(0 == size_y)
            return 0;
            
        vector<int> dp_table(size_y, 0);
        for(int j = 0; j < size_y; ++j)
        {
            if(obstacleGrid[0][j] == 1)
                break;
            dp_table[j] = 1;
        }
        
        for(int i = 1; i < size_x; ++i)
        {
            if(obstacleGrid[i][0] == 1)
                dp_table[0] = 0;
            for(int j = 1; j < size_y; ++j)
                dp_table[j] = obstacleGrid[i][j] == 1 ? 0 : dp_table[j-1] + dp_table[j];
        }
        
        return dp_table[size_y-1];
    }
};
