/*
 Author:            cuckoo
 Date:              2017/05/02 11:21:55
 Update:            2017/07/20 22:36:36
 Problem:           Palindrome Number
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/palindrome-number/#/description

 */

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindromeFirst(x);
    }
    
    bool isPalindromeFirstAux(int x, int &low)
    {
        if(x == 0) return true;
        bool result = isPalindromeFirstAux(x / 10, low) && (x % 10 == low % 10);
        low = low / 10;
        
        return result;
    }
    bool isPalindromeFirst(int x)
    {
        if(x < 0) return false;
        
        return isPalindromeFirstAux(x, x);
    }

    // update at 2017/07/20 22:36:36
    // When the reversed number overflows, it will becomes negative number which will return false when compared with x
    bool isPalindromeSecond(int x)
    {
        if(x < 0) return false;
        int y = x;
        int res = 0;
        while(y != 0) {
            res = res * 10 + y % 10;
            y /= 10;
        }
        
        return x == res;
    }
    
    // best one
    bool isPalindromeThird(int x)
    {
        if(x < 0 || x != 0 && x % 10 == 0)      // 10, 200, 210
            return false;
        
        int half = 0;
        while(x > half)
        {
            half = half * 10 + x % 10;
            x /= 10;
        }
        
        return x == half || x == half / 10;
    }
};
