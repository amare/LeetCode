/*
 Author:            cuckoo
 Date:              2017/04/27 17:09:07
 Update:            
 Problem:           Reverse String
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/reverse-string/#/description

 */

#include <string>
using std::string;

#include <algorithm>        // for swap()

class Solution {
public:
    string reverseString(string s) {
        return reverseStringFirst(s);
    }
    
    string reverseStringFirst(string &s)
    {
        int head = 0, tail = s.size() - 1;
        while(head <= tail)
            std::swap(s[head++], s[tail--]);
            
        return s;
    }
};
