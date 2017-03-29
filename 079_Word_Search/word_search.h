/*
 Author:            cuckoo
 Date:              2017/03/29 08:45:35
 Update:            
 Problem:           Word Search
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/word-search/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return exist_1(board, word);
    }
    
    //
    bool backtracking(vector<vector<char>>& board, string &word, int index, int row, int col, vector<vector<bool>> &accessed)
    {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || accessed[row][col])
            return false;
        if(index == word.size() - 1)
            return word[index] == board[row][col];
        
        if(word[index] == board[row][col])
        {
            accessed[row][col] = true;
            if(backtracking(board, word, index + 1, row, col - 1, accessed) ||
                backtracking(board, word, index + 1, row, col + 1, accessed) ||
                backtracking(board, word, index + 1, row - 1, col, accessed) ||
                backtracking(board, word, index + 1, row + 1, col, accessed))
                return true; 
            /*
            if(backtracking(board, word, index + 1, row, col - 1, accessed)) return true;     // left
            if(backtracking(board, word, index + 1, row, col + 1, accessed)) return true;     // right
            if(backtracking(board, word, index + 1, row - 1, col, accessed)) return true;     // top
            if(backtracking(board, word, index + 1, row + 1, col, accessed)) return true;     // bottom
            */
            accessed[row][col] = false;
        }
        
        return false;
    }
    
    bool exist_1(vector<vector<char>>& board, string &word)
    {
        size_t size_x = board.size();
        if(0 == size_x || 0 == word.size()) return false;
        size_t size_y = board[0].size();
            
        vector<vector<bool>> accessed(size_x, vector<bool>(size_y, false));
        for(int i = 0; i < size_x; ++i)
        {
            for(int j = 0; j < size_y; ++j)
            {
                if(board[i][j] == word[0])
                {
                    if(backtracking(board, word, 0, i, j, accessed))
                        return true;
                }
                /* it's redundant, accessed[i][j] will be set false in backtracking()
                   and will cause Time Limit Exceeded
                for(int i = 0; i < size_x; ++i)
                {
                    for(int j = 0; j < size_y; ++j)
                    {
                        accessed[i][j] = false;
                    }
                }
                */
            }
        }
        
        return false;
    }
};
