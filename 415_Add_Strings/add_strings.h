/*
 Author:            cuckoo
 Date:              2017/05/07 16:51:58
 Update:            
 Problem:           Add Strings
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/add-strings/#/description

 */

#include <string>
using std::string;

#include <algorithm>        // for reverse()

class Solution {
public:
    string addStrings(string num1, string num2) {
        return addStringsFirst(num1, num2);
    }
    
    string addStringsFirst(string num1, string num2)
    {
        string result;
        
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while(i >= 0 || j >= 0)
        {
            int sum = carry;
            if(i >= 0)
                sum += num1[i--] - '0';
            if(j >= 0)
                sum += num2[j--] - '0';
            
            result += static_cast<char>(sum % 10 + '0');    // or use to_string()
            carry = sum / 10;
        }
        
        if(carry == 1)
            result += '1';
        std::reverse(std::begin(result), std::end(result));
        
        return result;
    }
};
