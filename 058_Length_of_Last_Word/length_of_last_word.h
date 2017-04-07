/*
 Author:            cuckoo
 Date:              2017/04/06 22:50:29
 Update:            
 Problem:           Length of Last Word
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/length-of-last-word/#/description

 */

#include <string>
using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        return lengthOfLastWord_1(s);
    }
    
    int lengthOfLastWord_1(string &s)
    {
        int size = s.size();
        int start = 0, end = size - 1, last_space = -1;
        while(end >= 0 && s[end] == ' ') --end;     // attention
        while(start <= end)
        {
            if(s[start] == ' ')
                last_space = start;
            ++start;
        }
        
        return end - last_space;
    }
};
