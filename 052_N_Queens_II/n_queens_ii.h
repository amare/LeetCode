/*
 Author:            cuckoo
 Date:              2017/04/04 10:26:49
 Update:            
 Problem:           N-Queens II
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/n-queens-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int totalNQueens(int n) {
        return totalNQueens_1(n);
    }
    
    bool canplace(vector<int> &Q, int row, int col)
    {
        for(int i = 0; i < row; ++i)
            if(col == Q[i] || col == Q[i] - i + row || col == Q[i] + i - row)
                return false;
        
        return true;
    }
    
    void search(int row, vector<int> &Q, int &result, int n)
    {
        if(row >= n)
        {
            result += 1;
            return;
        }
        for(int col = 0; col < n; ++col)
        {
            if(canplace(Q, row, col))
            {
                Q[row] = col;
                search(row + 1, Q, result, n);
                Q[row] = -1;
            }
        }
    }
    
    int totalNQueens_1(int n)
    {
        if(n <= 0) return 0;
        int result = 0;
        vector<int> Q(n, -1);
        search(0, Q, result, n);
        
        return result;
    }
};
