/*
 Author:            cuckoo
 Date:              2017/04/28 17:36:56
 Update:            
 Problem:           Reverse Words in a String
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/reverse-words-in-a-string/#/description

 */

#include <string>
using std::string;

#include <algorithm>            // for swap()

class Solution {
public:
    void reverseWords(string &s) {
        return reverseWordsFirst(s);   
    }
    
    void RemoveSpaces(string &s)
    {
        int n = s.size();
        int i = 0, j = 0;
        
        while(j < n)
        {
            while(j < n && s[j] == ' ') ++j;
            while(j < n && s[j] != ' ') s[i++] = s[j++];
            while(j < n && s[j] == ' ') ++j;
            if(j < n) s[i++] = ' ';
        }
        
        s = s.substr(0, i);
        // s.resize(i);
    }
    void reverse(string &s, int head, int tail)
    {
        while(head <= tail)
            std::swap(s[head++], s[tail--]);
    }
    void reverseWordsFirst(string &s)
    {
        int n = s.size();
        reverse(s, 0, n - 1);
        
        int begin = 0, end = 0;
        while(end < n)
        {
            while(begin < n && s[begin] == ' ') ++begin;
            if(begin == n) break;
            
            end = begin;
            while(end < n && s[end] != ' ') ++end;
            reverse(s, begin, end - 1);
            
            begin = end;
        }
        
        RemoveSpaces(s);
    }
};
