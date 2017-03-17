/*
 Author:            cuckoo
 Date:              2017/03/17 08:52:45
 Update:
 Problem:           Valid Sudoku
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/valid-sudoku

 */

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidSudoku_1(board);
    }

    bool isValidSudoku_1(vector<vector<char>>& board)
    {
        /*
         * used1: check each row
         * used2: check each column
         * used3: check each sub-box
         */
        bool used1[9][9] = {false}, used2[9][9] = {false}, used3[9][9] = {false};
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;      // ^core code
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = true;
                }
            }
        }
        return true;
    }

    bool isValidSudoku_2(vector<vector<char>>& board)
    {
        vector<short> row(9, 0), col(9, 0), block(9, 0);
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] != '.')
                {
                    int k = i / 3 * 3 + j / 3;
                    int curr = 1 << (board[i][j] - '0');
                    if(curr & row[i] || curr & col[j] || curr & block[k])
                        return false;
                    row[i] |= curr;
                    col[j] |= curr;
                    block[k] |= curr;
                }
            }
        }
        return true;
    }

    // hash
    bool isValidSudoku_3(vector<vector<char>>& board)
    {
        unordered_map<char, short> row[9], col[9], block[9];
        char c;
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                c = board[i][j];
                if((c != '.') && (row[i][c]++ > 0 || col[j][c]++ > 0 || block[i / 3 * 3 + j / 3][c]++ > 0))
                    return false;
            }
        }
        return true;
    }
};
