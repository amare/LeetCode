/*
 Author:            cuckoo
 Date:              2017/04/01 20:39:12
 Update:            
 Problem:           Pascal's Triangle
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/pascals-triangle/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        return generate_1(numRows);
    }
    
    vector<vector<int>> generate_1(int numRows)
    {
        if(numRows <= 0) return {};
        vector<vector<int>> result(numRows);
        /*
        if(numRows == 1)
        {
          result[0] = {1};
          return result;
        }
        if(numRows == 2)
        {
            result[0] = {1};
            result[1] = {1, 1};
            return result;
        }
        
        result[0] = {1};
        result[1] = {1, 1};
        */
        for(int i = 0; i < numRows; ++i)
        {
            result[i].resize(i+1);
            result[i][0] = result[i][i] = 1;
            for(int j = 1; j < i; ++j)
                result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
        
        return result;
    }
};
