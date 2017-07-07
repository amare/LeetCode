/*
 Author:            cuckoo
 Date:              2017/03/27 22:37:12
 Update:            2017/07/07 19:59:58
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
        // A[c]: the number of character c in t
        // B[c]: the number of character c in window
        // hash[c]: A[c] - B[c]
        while(end < size)
        {
            if(hash[s[end]] > 0)    // char s[end] exists in target and the number of s[end]
                --count;            // in window is not larger than in target
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
                if(hash[s[start]] > 0)  // char s[begin] exists in target and the number of char
                    ++count;            // s[begin] in window will less than in target after shrink
                ++start;
            }
        }
        if(min_length != INT_MAX)
            return s.substr(min_start, min_length);
        return "";
    }

    // update by gps 2017/07/07 20:00:10
    string MinWindowSecond(string &s, string &t)
    {
        
        unordered_map<char, int> counts;
        for(auto c : t)
            ++counts[c];
        
        int count = 0;      // count represents the number of chars of t which had been found in s
        unordered_map<char, int> window;
        int begin = 0, end = 0, min_begin = 0, min_length = INT_MAX;
        for(; end < s.size(); ++end)
        {
            char c = s[end];
            if(counts.count(c))     // ignore all characters which not exist in t
            {
                ++window[c];
                if(window[c] <= counts[c])
                    ++count;
                /*
                else                // when the number of current character in window is larger than in t, shrink the window
                {
                    while(window[c] > counts[c])
                    {
                        char begin_c = s[begin];
                        if(counts.count(begin_c))
                        {
                            --window[begin_c];
                            if(window[begin_c] < counts[begin_c])
                                --count;
                        }
                        ++begin;
                    }
                }
                */
                // when we found a valid window, move begin to find a smaller window
                while(count == t.size())
                {
                    if(end + 1 - begin < min_length)
                    {
                        min_begin = begin;
                        min_length = end + 1 - begin;
                    }
                    
                    char begin_c = s[begin];
                    if(counts.count(begin_c))
                    {
                        --window[begin_c];
                        if(window[begin_c] < counts[begin_c])
                            --count;
                    }
                    ++begin;
                }
            }
        }
        
        return min_length == INT_MAX ? "" : s.substr(min_begin, min_length);
    }
};
