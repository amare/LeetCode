/*
 Author:            cuckoo
 Date:              2017/08/02 20:32:51
 Update:            
 Problem:           Repeated Substring Pattern
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/repeated-substring-pattern/description/

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       return RepeatedSubstringPatternSecond(s); 
    }
    
    bool RepeatedSubstringPatternFirst(string &s)
    {
        int n = s.size();
        for(int copy = 2; copy <= n; ++copy)     // multiple copies of the substring 
        {
            if(n % copy == 0)
            {
                int length = n / copy;
                int p1 = 0, p2 = p1 + length;
                while(p2 < n)
                {
                    if(s[p1] != s[p2])
                        break;
                    p1++;
                    p2++;
                }
                if(p2 == n)
                    return true;  
            }
        }
        
        return false;
    }
    
    // KMP
    bool RepeatedSubstringPatternSecond(string &s)
    {
        if(s.empty())
            return false;
        
        // lps[i] represents the longest proper prefix of s[0...i] which is also a suffix of s[0...i]
        int n = s.size();
        vector<int> lps(n, 0);
        
        int len = 0;            // the previous longest prefix suffix
        int i = 1;
        while(i < n)
        {
            if(s[i] == s[len])          // match
                lps[i++] = ++len;
            else
            {
                if(len == 0)
                    ++i;
                else                    // find the next smaller longest prefix suffix
                    len = lps[len - 1];
            }
        }
        
        return lps[n-1] > 0 && lps[n-1] % (n - lps[n-1]) == 0;
    }
};
