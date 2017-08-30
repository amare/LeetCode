/*
 Author:            cuckoo
 Date:              2017/07/22 09:56:47
 Update:            
 Problem:           Reverse String II
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/reverse-string-ii/#/description

 */

#include <string>
using std::string;

#include <algorithm>            // for std::min(), std::reverse()

class Solution {
public:
    string reverseStr(string s, int k) {
        return ReverseStringFirst(s, k);
    }
    
    string ReverseStringFirst(string &s, int k)
    {
        if(k <= 0)
            return "";
        
        int n = s.size(), left = n % (2 * k);
        int i = 0;
        for(; i < n - left; i += 2 * k)
        {
            int begin = i, end = i + k - 1;
            while(begin < end)
                std::swap(s[begin++], s[end--]);
        }
        
        int begin = i, end = std::min(n - 1, i + k - 1);
        while(begin < end)
            std::swap(s[begin++], s[end--]);
        
        return s;
    }
    
    string ReverseStringSecond(string &s, int k)
    {
        if(k <= 0)
            return "";
        
        for(int i = 0; i < s.size(); i += 2 * k)
            std::reverse(s.begin() + i, std::min(s.begin() + i+k, s.end()));
        
        return s;
    }
};
