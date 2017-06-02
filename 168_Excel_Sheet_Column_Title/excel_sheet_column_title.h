/*
 Author:            cuckoo
 Date:              2017/05/19 09:13:07
 Update:            
 Problem:           Excel Sheet Column Title
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/excel-sheet-column-title/#/description

 */

#include <string>
using std::string;

#include <algorithm>            // for reverse()
#include <iterator>             // for begin(), end()

class Solution {
public:
    string convertToTitle(int n) {
        return convertToTitleFirst(n);
    }
    
    // 类似26进制，只是没有0这个表示符
    string convertToTitleFirst(int n)
    {
        char mapping[27] = { "" };  // mapping[0] = ""
        for(int i = 1; i < 27; ++i)
            mapping[i] = 'A' + i - 1;
        
        string result;
        
        while(n > 26)
        {
            int quotient = n / 26, remainder = n % 26;
            if(remainder == 0)             // key point
            {
                --quotient;
                result += mapping[26];
            }
            else
            {
                result += mapping[remainder];
            }
            n = quotient; 
        }
        
        result += mapping[n];
        std::reverse(std::begin(result), std::end(result));
        
        return result;
    }
};
