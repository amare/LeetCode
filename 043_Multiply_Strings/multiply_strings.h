/*
 Author:            cuckoo
 Date:              2017/05/07 18:55:02
 Update:            
 Problem:           Multiply Strings
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/multiply-strings/#/description

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>        // for reverse()

class Solution {
public:
    string multiply(string num1, string num2) {
        return multiplyFirst(num1, num2);
    }
    
    string AddTwoString(string &num1, string &num2)
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
            
            carry = sum / 10;
            result += static_cast<char>(sum % 10 + '0');
        }
        if(carry == 1)
            result += '1';
        
        std::reverse(std::begin(result), std::end(result));
        
        return result;
    }
    
    string multiplyFirst(string &num1, string &num2)
    {
        int n1 = num1.size(), n2 = num2.size();
        if(n1 == 0 || n2 == 0)
            return string("0");
        if(n1 == 1 && num1[0] == '0' || n2 == 1 && num2[0] == '0')
            return string("0");
        
        string result;
        
        // store the result of 0-9 * num2
        vector<string> digits_multiply(10, string("0"));
        for(int i = 1; i < 10; ++i)
            digits_multiply[i] = AddTwoString(digits_multiply[i - 1], num2);
 
        for(int i = 0; i < n1; ++i)
        {
            string temp = digits_multiply[num1[i] - '0'];
            result = AddTwoString(result, temp.append(n1 - 1 - i, '0'));
        }
            
        return result;
    }


    string multiplySecond(string &num1, string &num2)
    {
        int n1 = num1.size(), n2 = num2.size();
        string result(n1 + n2, '0');
        
        for(int i = n1 - 1; i >= 0; --i)
        {
            int carry = 0;
            for(int j = n2 - 1; j >= 0; --j)
            {
                int sum = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                
                result[i + j + 1] = static_cast<char>(sum % 10 + '0');
                carry = sum / 10;
            }
            result[i] = static_cast<char>(result[i] + carry);
        }
        
        size_t start_pos = result.find_first_not_of('0');
        if(start_pos != string::npos)
            return result.substr(start_pos);
        
        return "0";
    }
};
