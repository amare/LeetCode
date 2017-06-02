/*
 Author:            cuckoo
 Date:              2017/05/19 09:47:19
 Update:            
 Problem:           Excel Sheet Column Number
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/excel-sheet-column-number/#/description

 */

#include <cmath>            // for pow()

#include <string>
using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        return titleToNumberSecond(s);
    }
    
    int titleToNumberFirst(string &s)
    {
        int result = 0;
        
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            result += (s[i] - 'A' + 1) * std::pow(26, n - 1 - i);
        }
        
        return result;
    }
    
    int titleToNumberSecond(string &s)
    {
        int result = 0;
        
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            result = result * 26 + s[i] - 'A' + 1;
        }
        
        return result;
    }
};
