/*
 Author:            cuckoo
 Date:              2017/03/21 20:16:15
 Update:
 Problem:           Pow(x, n)
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/powx-n

 */

#include <cmath>    // for INFINITY, abs()

class Solution {
public:
    double myPow(double x, int n) {
        return myPow_2(x, n);
    }

    long double pow_aux(double x, unsigned int n)
    {
        if(n == 1)
            return x;
        if(n % 2 == 0)
        {
            long double tmp = pow_aux(x, n / 2);
            return tmp * tmp;
        }
        else
        {
            long double tmp = pow_aux(x, n / 2);
            return tmp * tmp * x;
        }
    }
    double myPow_1(double x, int n)
    {
        if(n == 0) return 1;
        if(x == 0 && n < 0) return INFINITY;
        if(n > 0)
            return pow_aux(x, n);
        else
            return pow_aux(1 / x, -n);
    }

    // iterative version
    double myPow_2(double x, int n)
    {
        double result = 1;
        unsigned int new_n = std::abs(n);
        while(new_n)
        {
            if(new_n & 1)
                result *= x;
            new_n >>= 1;
            x *= x;
        }

        return n < 0 ? 1 / result : result;
    }
};
