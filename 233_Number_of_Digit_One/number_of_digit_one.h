/*
 Author:            cuckoo
 Date:              2017/07/06 11:13:17
 Update:            
 Problem:           Number of Digit One
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/number-of-digit-one/#/description

 */

#include <string>
using std::string;

#include <cmath>        // for pow()

class Solution {
public:
    int countDigitOne(int n) {
        return countDigitOneFirst(n);
    }
    
    int countDigitOneFirst(int n)
    {
        if(n <= 0)
            return 0;
        
        string n_str = std::to_string(n);
        
        return CountDigtiOneFirstAux(n_str, 0);
    }
    
    int CountDigtiOneFirstAux(string &n, int index)
    {
        int first = n[index] - '0';
        if(index == n.size() - 1)
            return first == 0 ? 0 : 1;
        
        int length = n.size() - index;
        // 首位为1的数目
        int first_one_count = 0;
        if(first > 1)
            first_one_count = std::pow(10, length - 1);
        else if(first == 1)
            first_one_count = std::stoi(n.substr(index + 1)) + 1;
        // 其他位为1的数目
        int other_one_count = first * (length - 1) * std::pow(10, length - 2);
        
        return first_one_count + other_one_count + CountDigtiOneFirstAux(n, index + 1);
    }

    
    // from Editorial Solution
    int countDigitOneSecond(int n)
    {
        int result = 0;
        for(long long i = 1; i <= n; i *= 10)
        {
            long long divider = i * 10;
            result += n / divider * i + std::min(std::max(n % divider - i + 1, 0LL), i);
        }
        
        return result;
    }
};
