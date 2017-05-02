/*
 Author:            cuckoo
 Date:              2017/04/28 19:51:14
 Update:            
 Problem:           Ransom Note
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/ransom-note/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        return canConstructFirst(ransomNote, magazine);
    }
    
    bool canConstructFirst(string &ransomNote, string &magazine)
    {
        vector<int> count(26, 0);
        for(auto c : magazine)
            ++count[c - 'a'];
        for(auto c : ransomNote)
            if(count[c - 'a']-- == 0)
                return false;
        
        return true;
    }
};
