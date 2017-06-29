/*
 Author:            cuckoo
 Date:              2017/06/29 16:18:45
 Update:            
 Problem:           Power of Four
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/power-of-four/#/description

 */

class Solution {
public:
    bool isPowerOfFour(int num) {
        return isPowerOfFourFirst(num);    
    }
    
    bool isPowerOfFourFirst(int n)
    {
        return n > 0 && ((n & n - 1) == 0) && ((n & 0x55555555) != 0);
    }
};
