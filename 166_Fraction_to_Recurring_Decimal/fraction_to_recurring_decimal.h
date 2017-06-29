/*
 Author:            cuckoo
 Date:              2017/06/09 15:51:24
 Update:            
 Problem:           Fraction to Recurring Decimal
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/fraction-to-recurring-decimal/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        return fractionToDecimalSecond(numerator, denominator);
    }

    // 有理数：可被表示为两个整数之比的数(a/b, b != 0)
    // 定理：每个有理数都一定能表示为一个有限小数或无限循环小数
    // 测试用例：1 / 2147483647 TLE - 考虑溢出
    string fractionToDecimalSecond(int numerator, int denominator)
    {
        if(denominator == 0 || numerator == 0)      // denominator cannot be 0
            return "0";
        
        // 处理商的整数部分，考虑溢出, 负数
        string result;
        if(numerator < 0 ^ denominator < 0)
            result = "-";
        long numerator_long = std::abs(static_cast<long>(numerator));
        long denominator_long = std::abs(static_cast<long>(denominator));
        long quotient = numerator_long / denominator_long, remainder = numerator_long % denominator_long;
        
        result += std::to_string(quotient);
        if(remainder == 0)      // 没有小数位
            return result;
        result += ".";
        
        // 处理商的小数部分
        unordered_map<long, int> hash;
        long dividend = remainder * 10;
        
        while(remainder != 0)       // 小数位存在循环
        {
            dividend = remainder * 10;
            quotient = dividend / denominator_long;
            if(hash.find(dividend) != hash.end())       // 遇到循环
            {
                result.insert(hash[dividend], 1, '(');
                result += ')';
                break;
            }
            hash[dividend] = result.size();
            result += std::to_string(quotient);
            remainder = dividend % denominator_long;
        }
        
        return result;
    }


    // 有理数：可被表示为两个整数之比的数(a/b, b != 0)
    // 定理：每个有理数都一定能表示为一个有限小数或无限循环小数
    // 测试用例：1 / 2147483647 TLE - 考虑溢出
    string fractionToDecimalFirst(int numerator, int denominator)
    {
        if(denominator == 0)
            return "";
        
        // 考虑溢出, 负数
        string result;
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            result = "-";
        long numerator_long = std::abs(static_cast<long>(numerator));
        long denominator_long = std::abs(static_cast<long>(denominator));
        long quotient = numerator_long / denominator_long, remainder = numerator_long % denominator_long;

        if(remainder == 0)
            return result + std::to_string(quotient);
        else
            result += std::to_string(quotient) + ".";
        
        
        unordered_map<long, int> hash;
        int index = 0;
        long dividend = remainder * 10;
        string decimal_fraction;
        
        while(true)
        {
            if(remainder == 0)
                break;
                
            dividend = remainder * 10;
            quotient = dividend / denominator_long;
            if(hash.find(dividend) == hash.end())
            {
                hash.insert({dividend, index++});
                decimal_fraction += std::to_string(quotient);
            }
            else
            {
                break;
            }
            remainder = dividend % denominator_long;
        }
        
        return remainder == 0 ? result + decimal_fraction
                              : result + decimal_fraction.substr(0, hash[dividend]) + "(" + decimal_fraction.substr(hash[dividend]) + ")";
    }
};

