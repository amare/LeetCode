/*
 Author:            cuckoo
 Date:              2017/04/28 17:01:53
 Update:            
 Problem:           Reverse Vowels of a String
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/reverse-vowels-of-a-string/#/description

 */

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <algorithm>            // for swap()

class Solution {
public:
    string reverseVowels(string s) {
        return reverseVowelsFirst(s);
    }
    
    bool IsVowel(char c)
    {
        static unordered_set<char> hash = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if(hash.find(c) != hash.end())
            return true;
        return false;
    }
    string reverseVowelsFirst(string s)
    {
        int head = 0, tail = s.size() - 1;
        while(head <= tail)
        {
            while(head <= tail && !IsVowel(s[head])) ++head;
            while(head <= tail && !IsVowel(s[tail])) --tail;
            if(head > tail) break;
            
            std::swap(s[head++], s[tail--]);
        }
        
        return s;
    }
};
