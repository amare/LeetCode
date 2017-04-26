/*
 Author:            cuckoo
 Date:              2017/04/25 21:40:38
 Update:            
 Problem:           Pascal's Triangle II
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/pascals-triangle-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return getRowFirst(rowIndex);
    }
    
    vector<int> getRowFirst(int rowIndex)
    {
        if(rowIndex < 0) return {};
        
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for(int i = 1; i < rowIndex + 1; ++i)
            for(int j = i; j >= 1; --j)
                result[j] += result[j - 1];
                
        return result;
    }
};
