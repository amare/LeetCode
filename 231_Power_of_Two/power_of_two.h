/*
 Author:            cuckoo
 Date:              2017/06/29 16:03:35
 Update:            
 Problem:           Power of Two
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/power-of-two/#/description

 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return isPowerOfTwoFirst(n);
    }
    
    bool isPowerOfTwoFirst(int n)
    {
        return n > 0 && ((n & n - 1) == 0);
    }
};
