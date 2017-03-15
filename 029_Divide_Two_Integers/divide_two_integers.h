/*
 Author:            cuckoo
 Date:              2017/03/14 15:32:25
 Update:
 Problem:           Divide Two Integers
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/divide-two-integers

 */

#include <climits>  // for INT_MAX, INT_MIN

class Solution {
public:
    int divide(int dividend, int divisor) {
        return divide_2(dividend, divisor);
    }
    // Time Limit Exceeded
    int divide_1(int dividend, int divisor)
    {
        int result = 0;
        if(0 == divisor) return INT_MAX;
        if(0 == dividend) return 0;
        if(INT_MIN == dividend && -1 == divisor) return INT_MAX;

        int sign = 0;
        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
        {
            sign = 1;
        }
        // make the sigh of two numbers become same
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;

        if(dividend > divisor) return 0;
        // subtracte one divisor after another
        while(dividend <= divisor)
        {
            dividend -= divisor;
            result += 1;
        }

        return sign ? -result : result;
    }

    int divide_2(int dividend, int divisor)
    {
        int result = 0;
        if(0 == divisor) return INT_MAX;
        if(0 == dividend) return 0;
        if(INT_MIN == dividend && -1 == divisor) return INT_MAX;

        int sign = 0;
        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
        {
            sign = 1;
        }
        // make the sigh of two numbers become same
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;

        if(dividend > divisor) return 0;

        while(dividend <= divisor)
        {
            long long temp = divisor, multiple = 1;
            while(dividend <= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }
            dividend -= temp;
            result += multiple;
        }

        return sign ? -result : result;
    }

    int divide_3(int dividend, int divisor)
    {
        if(0 == divisor) return INT_MAX;
        if(-1 == divisor && INT_MIN == dividend) return INT_MAX;

        bool sign = (dividend < 0) ^ (divisor < 0);

        unsigned int udividend = dividend < 0 ? -dividend : dividend;
        unsigned int udivisor = divisor < 0 ? -divisor : divisor;

        unsigned int single_difference = 0;
        unsigned int result = 0;        // quotient
        for(int i = 31; i >= 0; --i)
        {
            single_difference <<= 1;
            single_difference |= (udividend >> i) & 1;
            if(single_difference >= udivisor)
            {
                single_difference -= udivisor;
                result |= (1 << i);
            }
        }

        return sign ? -result : result;
    }
};
