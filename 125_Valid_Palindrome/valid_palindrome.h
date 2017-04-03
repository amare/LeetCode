/*
 Author:            cuckoo
 Date:              2017/04/02 17:45:00
 Update:            
 Problem:           Valid Palindrome
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/valid-palindrome/#/description

 */

#include <string>
using std::string;

#include <cctype>       // for isalnum(), toupper()

class Solution {
public:
    bool isPalindrome(string s) {
        return isPalindrome_2(s);
    }
    
    bool isSameChar(char lhs, char rhs)
    {
        if(lhs >= 'a' && lhs <= 'z')
            lhs += 'A' - 'a';
        if(rhs >= 'a' && rhs <= 'z')
            rhs += 'A' - 'a';
        if(lhs == rhs)
            return true;
        return false;
    }
    bool isValidChar(char ch)
    {
        if(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }
    bool isPalindrome_1(string &s)
    {
        int start = 0, last = s.size() - 1;
        while(start < last)
        {
            // notice that 'start < last' is must be present in while loop
            while(start < last && !isValidChar(s[start])) ++start;
            while(start < last && !isValidChar(s[last])) -- last;
            if(!isSameChar(s[start++], s[last--]))
                return false;
        }
        
        return true;
    }
    
    
    bool isPalindrome_2(string &s)
    {
        int start = 0, last = s.size() - 1;
        while(start < last)
        {
            while(start < last && !std::isalnum(s[start])) ++start;
            while(start < last && !std::isalnum(s[last])) --last;
            if(std::toupper(s[start++]) != std::toupper(s[last--]))
                return false;
        }
        
        return true;
    }
};
