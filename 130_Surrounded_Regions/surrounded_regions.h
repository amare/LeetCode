/*
 Author:            cuckoo
 Date:              2017/05/19 21:47:59
 Update:            
 Problem:           Surrounded Regions
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/surrounded-regions/#/description

 */

#include <queue>
using std::queue;

#include <utility>
using std::pair;
using std::make_pair;

#include <vector>
using std::vector;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        return SolveFirst(board);
    }
    
    void SolveFirst(vector<vector<char>>& board)
    {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        
        // check the four borders of the matrix. If there is a element is 'O',
        // alter it and all its neighbor 'O' elements to '#'. 
        int m = board.size(), n = board[0].size();
        for(int j = 0; j < n; ++j)
        {
            if(board[0][j] == 'O')
                BoundaryBFS(board, 0, j);
            if(board[m - 1][j] == 'O')
                BoundaryBFS(board, m - 1, j);
        }
        for(int i = 0; i < m; ++i)
        {
            if(board[i][0] == 'O')
                BoundaryBFS(board, i, 0);
            if(board[i][n - 1] == 'O')
                BoundaryBFS(board, i, n - 1);
        }
        
        // alter all 'O' to 'X', and all '#' to 'O'
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    void BoundaryBFS(vector<vector<char> > &board, int row, int col)
    {
        int m = board.size(), n = board[0].size();
        
        queue<pair<int, int> > q;
        q.push(make_pair(row, col));
        while(q.empty() == false)
        {
            pair<int, int> current = q.front();
            q.pop();
            
            int i = current.first, j = current.second;
            if(i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')
            {
                board[i][j] = '#';
                q.push(make_pair(i - 1, j));
                q.push(make_pair(i + 1, j));
                q.push(make_pair(i, j - 1));
                q.push(make_pair(i, j + 1));
            }
        }
    }
};
