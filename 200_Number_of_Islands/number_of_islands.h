/*
 Author:            cuckoo
 Date:              2017/06/10 20:45:37
 Update:            
 Problem:           Number of Islands
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/number-of-islands/#/description

 */

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <utility>
using std::pair;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        return numIslandsSecond(grid);
    }
    
    // Breadth-First-Search
    void GridBFS(vector<vector<char> > &grid, int row, int col)
    {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int> > q;
        q.push({row, col});
        
        while(!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();
            
            int i = current.first, j = current.second;
            if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1')
            {
                grid[i][j] = '#';
                q.push({i - 1, j});
                q.push({i + 1, j});
                q.push({i, j - 1});
                q.push({i, j + 1});
            }
        }
    }
    int numIslandsFirst(vector<vector<char>>& grid)
    {
        if(grid.empty())
            return 0;
        
        int result = 0;
        
        // check all the element. If there is a element is '1',
        // alter it and all its neighbor '1' elements to '#'
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++result;
                    GridBFS(grid, i, j);
                }
            }
        }
        // reset all '#' to '1'        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == '#')
                    grid[i][j] = '1';

        return result;
    }
    
    // Depth-First-Search
    void GridDFS(vector<vector<char> > &grid, int row, int col)
    {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1')
            return;
        
        grid[row][col] = '#';
        GridDFS(grid, row - 1, col);
        GridDFS(grid, row + 1, col);
        GridDFS(grid, row, col - 1);
        GridDFS(grid, row, col + 1);
    }
    int numIslandsSecond(vector<vector<char>>& grid)
    {
        if(grid.empty())
            return 0;
        
        int result = 0;
        
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++result;
                    GridDFS(grid, i, j);
                }
            }
        }
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == '#')
                    grid[i][j] = '1';

        return result;
    }
};
