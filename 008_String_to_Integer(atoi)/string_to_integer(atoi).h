/*
 Author:            cuckoo
 Date:              2017/03/04 10:47:23
 Update:
 Problem:           String to Integer(atoi)
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/string-to-integer-atoi

 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cmath>
using std::pow;

#include <limits>
using std::numeric_limits;

#include <climits>  // for INT_MIN, INT_MAX
#include <cctype>    // for isdigit()

class Solution {
public:
    int myAtoi(string str) {
        return myAtoi_3(str);
    }

    int NumCharToInt(const char c)
    {
        switch(c)
        {
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            default:
                return -1;
        }
    }

    int myAtoi_1(string &s)
    {
        int size = s.size();
        if(size == 0)   // empty string ""
            return 0;

        // discards all whitespace characters followed by the first non-whitespace character
        int k = 0;
        while( k < size && s.at(k) == ' ')
        {
            ++k;
        }
        if(k == size)
            return 0;

        // handle optional initial plus or minus sign
        bool negative_flag = false;
        if(s.at(0) == '-')  // negative
        {
            negative_flag = true;
            s = s.substr(1);
        }
        else if(s.at(0) == '+') // positive
        {
            negative_flag = false;
            s = s.substr(1);
        }
        else
        {
            ;
        }
        size = s.size();
        if(size == 0)   // empty string ""
            return 0;

        // discards all zeros followed by the first non-zero character
        k = 0;
        while(k < size && s.at(k) == '0')   //bugfix @gps [if(s.at(0) == '0');] redundant semicolon!!
        {
            ++k;
        }
        s = s.substr(k);
        size = s.size();
        if(size == 0)
            return 0;

        // discards all characters not included in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] following by valid numerical character
        for(int i = 0; i < size; ++i)
        {
            if(NumCharToInt(s.at(i)) == -1)
            {
                s = s.substr(0, i);
                size = s.size();
                break;
            }
        }

        // Out of range of int
        if(size > 10)
        {
            if(negative_flag)
                return numeric_limits<int>().min();
            else
                return numeric_limits<int>().max();
        }
        if(negative_flag && size == 10 && s > string("2147483648")) // less than INT_MIN
            return numeric_limits<int>().min();
        if(!negative_flag && size == 10 && s > string("2147483647"))    // larger than INT_MAX
            return numeric_limits<int>().max();

        // convert to int
        int ans = 0;
        for(int i = 0, pow_bit = size - 1; i < size; ++i, --pow_bit)
        {
            ans += NumCharToInt(s.at(i)) * static_cast<int>(pow(10, pow_bit));
        }
        if(negative_flag)
            return ans *= -1;

        return ans;
    }

    int myAtoi_2(string &s)
    {
        if(s.empty()) return 0;
        int sign = 1, size = s.size();
        long result = 0;
        int i = s.find_first_not_of(' ');
        if(i == -1)
            return 0;
        if(s.at(i) == '+' || s.at(i) == '-')
            sign = (s.at(i++) == '+') ? 1 : -1;
        while(i < size && s.at(i) >= '0' && s.at(i) <= '9')
        {
            result = result * 10 + (s.at(i++) - '0');
            if(result * sign >= INT_MAX) return INT_MAX;
            if(result * sign <= INT_MIN) return INT_MIN;
        }

        return result * sign;
    }

    int myAtoi_3(string &s)
    {
        if(s.empty()) return 0;
        int sign = 1, i = 0, result = 0;
        int base = INT_MAX /10;
        int size = s.size();
        while(i < size && s.at(i) == ' '){++i;}
        if(i == s.size()) return 0;
        if(s.at(i) == '+' || s.at(i) == '-')
            sign = (s.at(i++) == '+') ? 1 : -1;
        while(i < size && isdigit(s.at(i)))
        {
            if(result > base || (result == base && s.at(i) - '0' > 7))
                return sign > 0 ? INT_MAX : INT_MIN;
            result = result * 10 + (s.at(i++) - '0');
        }

        return sign * result;
    }
};
