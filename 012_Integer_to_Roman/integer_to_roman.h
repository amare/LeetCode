/*
 Author:            cuckoo
 Date:              2017/06/08 10:05:08
 Update:            
 Problem:           Integer to Roman
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/integer-to-roman/#/description

 */

#include <string>
using std::string;

class Solution {
public:
    string intToRoman(int num) {
        return intToRomanFirst(num);
    }
    
    string intToRomanFirst(int num)
    {
        static const string dict[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        
        string result;
        result.append(dict[3][num / 1000]);
        result.append(dict[2][num / 100 % 10]);
        result.append(dict[1][num / 10 % 10]);
        result.append(dict[0][num % 10]);
        
        return result;
    }
};
