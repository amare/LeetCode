/*
 Author:            cuckoo
 Date:              2017/04/07 10:58:37
 Update:            
 Problem:           Add Binary
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/add-binary/#/description

 */

#include <iterator>

#include <string>
using std::string;

#include <algorithm>        // for reverse()

class Solution {
public:
    string addBinary(string a, string b) {
        return addBinary_2(a, b);
    }
    
    string addBinary_1(string a, string b)
    {
        string result;
        int carry = 0, sum = 0;
        int size_a = a.size(), size_b = b.size();
        
        // eliminate redundant zero 
        int k = 0;
        while(k < size_a && a[k] == '0') ++k;
        a = a.substr(k);
        k = 0;
        while(k < size_b && b[k] == '0') ++k;
        b = b.substr(k);
        if(0 == a.size() && 0 == b.size()) return string("0");
        
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 && j >= 0)
        {
            int number_a = a[i] - '0';
            int number_b = b[j] - '0';
            
            int count_1 = number_a + number_b + carry;
            switch(count_1)
            {
                case 0:
                    sum = 0; carry = 0; break;
                case 1:
                    sum = 1; carry = 0; break;
                case 2:
                    sum = 0; carry = 1; break;
                case 3:
                    sum = 1; carry = 1; break;
                default:
                    /* handle with exception */
                    break;
            }
            char temp = sum == 0 ? '0' : '1';
            result.insert(0, 1, temp);
            
            --i;
            --j;
        }
        
        // handle with the situation which the a's length is not equal b's
        if(i == -1 && j == -1 && carry == 1)
            result.insert(0, 1, '1');
        else if(i == -1)
        {
            while(j >= 0)
            {
                int number_b = b[j] - '0';
                sum = carry ^ number_b;
                carry = carry & number_b;
                char temp = sum == 0 ? '0' : '1';
                result.insert(0, 1, temp);
                
                --j;
            }
            if(carry == 1)
                result.insert(0, 1, '1');
        }
        else
        {
            while(i >= 0)
            {
                int number_a = a[i] - '0';
                sum = carry ^ number_a;
                carry = carry & number_a;
                char temp = sum == 0 ? '0' : '1';
                result.insert(0, 1, temp);
                
                --i;
            }
            if(carry == 1)
                result.insert(0, 1, '1');
        }
            
        
        return result;
    }
    
    string addBinary_2(string a, string b)
    {
        string result;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while(i >= 0 || j >= 0)
        {
            int sum = carry;
            if(i >= 0)
                sum += a[i--] - '0';
            if(j >= 0)
                sum += b[j--] - '0';
            result.push_back(static_cast<char>(sum % 2 + '0'));
            carry = sum / 2;
        }
        if(carry == 1)
            result.push_back('1');
        reverse(std::begin(result), std::end(result));
        
        return result;
    }
};
