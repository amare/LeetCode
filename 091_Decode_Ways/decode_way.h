/*
 Author:            cuckoo
 Date:              2017/03/31 09:28:55
 Update:            
 Problem:           Decode Ways
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/decode-ways/#/description

 */

#include <string>
using std::string;

class Solution {
public:
    int numDecodings(string s) {
        return numDecodings_1(s);
    }
    // DP
    int numDecodings_1(string &s)
    {
        int size = s.size();
        if(0 == size || s[0] == '0') return 0;
        if(1 == size) return 1;
        // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
        int r1 = 1, r2 = 1;
        for(int i = 1; i < size; ++i)
        {
            // zero voids ways of the last because zero cannot be used separately
            if(s[i] == '0') r1 = 0;
             // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
            if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
            {
                r1 = r1 + r2;
                r2 = r1 - r2;   // r2 = old_r1
            }
            // one-digit letter, no new way added
            else
            {
                r2 = r1;
            }
        }
        
        return r1;
    }
};
