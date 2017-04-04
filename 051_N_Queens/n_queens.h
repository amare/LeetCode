/*
 Author:            cuckoo
 Date:              2017/04/04 09:57:23
 Update:            
 Problem:           N-Queens
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/n-queens/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        return solveNQueens_1(n);
    }
    
    
    bool canplace(vector<int> &Q, int row, int col)
    {
        for(int i = 0; i < row; ++i)
            if(col == Q[i] || col == Q[i] - i + row || col == Q[i] + i - row)
                return false;
        
        return true;
    }
    
    void search(int row, int n, vector<vector<string>> &result, vector<int> &Q)
    {
        if(row >= n)
        {
            vector<string> temp(n, string(n, '.'));
            for(int i = 0; i < n; ++i)
                temp[i][Q[i]] = 'Q';
            result.push_back(std::move(temp));
            
            return;
        }
        
        for(int col = 0; col < n; ++col)
        {
            if(canplace(Q, row, col))
            {
                Q[row] = col;
                search(row + 1, n, result, Q);
                Q[row] = -1;
            }
        }
    }
    
    vector<vector<string>> solveNQueens_1(int n)
    {
        if(n <= 0) return vector<vector<string>>(1);
        vector<vector<string>> result;
        vector<int> Q(n, -1);           // Q[row]: the column position of Queen in the current row
        search(0, n, result, Q);
        
        return result;
    }
};
