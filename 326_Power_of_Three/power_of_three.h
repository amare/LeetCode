/*
 Author:            cuckoo
 Date:              2017/06/29 16:55:01
 Update:            
 Problem:           Power of Three
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/power-of-three/#/description

 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        return isPowerOfThreeFirst(n);
    }
    
    bool isPowerOfThreeFirst(int n)
    {
        if(n < 1)
            return false;
            
        while(n % 3 == 0)
            n /= 3;
        return n == 1;
    }

    // Integer Limitations
    bool isPowerOfThreeSecond(int n)
    {
        return n > 0 && (1162261467 % n == 0);
    }
};
