/*
 Author:            cuckoo
 Date:              2017/06/03 12:48:20
 Update:            
 Problem:           Nth Digit
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/nth-digit/#/description

 */

#include <string>           // for to_string()

class Solution {
public:
    int findNthDigit(int n) {
        return FindNthDigitFirst(n);
    }
    
    int FindNthDigitFirst(int n)
    {
        if(n <= 0)
            return -1;
            
        long bits = 1, count = 9, start = 1;
        while(n > bits * count)
        {
            n -= bits * count;
            ++bits;
            count *= 10;
            start *= 10;
        }
        
        int temp = (n - 1) / bits;
        int number = start + temp;
        int nth = (n - 1) % bits;
        
        
        int ans = 0;
        while(nth < bits)
        {
            ans = number % 10;
            number /= 10;
            ++nth;
        }

        return ans;
        
        
        // return to_string(number)[nth-1] - '0';
    }
};
