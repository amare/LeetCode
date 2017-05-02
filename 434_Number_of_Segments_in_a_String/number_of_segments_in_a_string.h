/*
 Author:            cuckoo
 Date:              2017/04/29 17:29:07
 Update:            
 Problem:           Number of Segments in a String
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/number-of-segments-in-a-string/#/description

 */

#include <string>
using std::string;

class Solution {
public:
    int countSegments(string s) {
        return countSegmentsFirst(s);
    }
    
    int countSegmentsFirst(string &s)
    {
        int i = 0, n = s.size(), result = 0;
        
        while(true)
        {
            while(i < n && s[i] == ' ') ++i;
            if(i == n) return result;
            
            while(i < n && s[i] != ' ') ++i;
            ++result;
            if(i == n) return result;
        }
    }
};
