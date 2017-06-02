/*
 Author:            cuckoo
 Date:              2017/05/27 08:31:00
 Update:            
 Problem:           Longest Uncommon Subsequence I
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/longest-uncommon-subsequence-i/#/description

 */

#include <string>
using std::string;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return findLUSlengthFirst(a, b);
    }
    
    int findLUSlengthFirst(string &a, string &b)
    {
        return a == b ? -1 : std::max(a.size(), b.size());
    }
};
