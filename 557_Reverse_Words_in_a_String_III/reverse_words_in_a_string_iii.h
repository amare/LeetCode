/*
 Author:            cuckoo
 Date:              2017/07/22 10:33:22
 Update:            
 Problem:           Reverse Words in a String III
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description

 */

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

class Solution {
public:
    string reverseWords(string s) {
        return ReverseWordsSecond(s);
    }
    
    string ReverseWordsFirst(string &s)
    {
        int i = 0;
        while(i < s.size())
        {
            int begin = i, end = i;
            while(end < s.size() && s[end] != ' ')
                ++end;
            i = end + 1;
            --end;
            
            while(begin < end)
                std::swap(s[begin++], s[end--]);
        }
        
        return s;
    }
    
    string ReverseWordsSecond(string &s)
    {
        istringstream iss(s);
        auto iter = s.begin();
        string word;
        while(iss >> word)
        {
            iter = std::copy(word.rbegin(), word.rend(), iter);
            ++iter;
        }
        
        return s;
    }
};
