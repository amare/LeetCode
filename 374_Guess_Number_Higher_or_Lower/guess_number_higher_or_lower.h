/*
 Author:            cuckoo
 Date:              2017/04/19 21:58:54
 Update:            
 Problem:           Guess Number Higher or Lower
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/guess-number-higher-or-lower/#/description

 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return guessNumber1(n);
    }
    
    int guessNumber1(int n)
    {
        if(n <= 0) return 0;
        int start = 1, end = n;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(guess(mid) == 0)
                return mid;
            if(guess(mid) == -1)
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
};
