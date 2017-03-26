/*
 Author:            cuckoo
 Date:              2017/03/26 14:52:54
 Update:            
 Problem:           Sqrt(x)
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/sqrtx/#/description

 */

#include <climits>      // for INT_MIN

class Solution {
public:
    int mySqrt(int x) {
        return mySqrt_1(x);
    }
    
    int mySqrt_1(int x)
    {
        if(x < 0) return INT_MIN;
        if(x == 0) return 0;

        int left = 1, right = x;
        while(1)
        {
            int mid = left + (right - left) / 2;
            //if(mid > x / mid)
            if(x < mid * mid)
            {
                right = mid - 1;
            }
            else
            {
                if(mid + 1 > x / (mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
    }
    
    // Time Limit Exceeded
    int mySqrt_2(int x)
    {
        if(x < 0) return INT_MIN;
        if(x == 0) return 0;
        
        for(int i = 1; i <= x; ++i)
        {
            if(i * i > x)
                return i - 1;
        }
        return 0;
    }
};
