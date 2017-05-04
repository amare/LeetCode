/*
 Author:            cuckoo
 Date:              2017/05/02 11:21:55
 Update:            
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
};
