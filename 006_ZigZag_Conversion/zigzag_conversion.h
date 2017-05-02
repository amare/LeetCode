/*
 Author:            cuckoo
 Date:              2017/04/29 16:39:23
 Update:            
 Problem:           ZigZag Conversion
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/zigzag-conversion/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        return convertFirst(s, numRows);
    }
    
    string convertFirst(string &s, int numRows)
    {
        if(numRows <= 0)
            return s;
        
        int n = s.size();
        vector<string> storage(numRows, string());
        
        int i = 0;
        while(i < n)
        {
            for(int j = 0; j < numRows; ++j)
            {
                if(i >= n) break;
                storage[j] += s[i++];
            }
            for(int j = numRows - 2; j > 0; --j)
            {
                if(i >= n) break;
                storage[j] += s[i++];
            }
        }
        
        string result;
        for(auto &s : storage)
            result += s;
        
        return result;
    }
};
