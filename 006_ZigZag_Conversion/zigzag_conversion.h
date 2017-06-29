/*
 Author:            cuckoo
 Date:              2017/04/29 16:39:23
 Update:            2017/06/04 12:47:26
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
        return convertSecond(s, numRows);
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
    
    // 2017/06/04
    /*
        cycle = 2 * numRow - 2;
        supposed the current row is i
        the first element: j = i + k * cycle,   k = 0, 1, 2, ...
        the second element: second_index = (k + 1) * cycle - i,     k = 0, 1, 2, ...
    */
    string convertSecond(string &s, int numRows)
    {
        // check input
        if(numRows <= 1)
            return s;
        
        string result;
        int cycle = 2 * (numRows - 1);
        for(int i = 0; i < numRows; ++i)
        {
            for(int j = i; j < s.size(); j += cycle)
            {
                result += s[j];
                int second_index = j + cycle - 2 * i;
                if(i != 0 && i != numRows - 1 && second_index < s.size())
                    result += s[second_index];
            }
        }
        
        return result;
    }
};
