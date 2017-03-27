/*
 Author:            cuckoo
 Date:              2017/03/27 22:37:12
 Update:            
 Problem:           Minimum Window Substring
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/minimum-window-substring/#/description

 */

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    string minWindow(string s, string t) {
        return minWindow_1(s, t);
    }
    
    string minWindow_1(string &s, string &t)
    {
        unordered_map<char, int> hash;
        for(auto ch : t) hash[ch]++;        // Statistic for count of char in t
        size_t start = 0, end = 0, min_start = 0, min_length = INT_MAX;
        size_t size = s.size(), count = t.size();       // count represents the number of chars of t to be found in s.
        // Move end to find a valid window.
        while(end < size)
        {
            if(hash[s[end]] > 0)
                --count;
            --hash[s[end]];     // if char does not exist in t, hash[s[end]] would be negative
            ++end;
            // When we found a valid window, move start to find smaller window.
            while(count == 0)
            {
                if(end - start < min_length)
                {
                    min_start = start;
                    min_length = end - start;
                }
                ++hash[s[start]];
                if(hash[s[start]] > 0)
                    ++count;
                ++start;
            }
        }
        if(min_length != INT_MAX)
            return s.substr(min_start, min_length);
        return "";
    }
};
