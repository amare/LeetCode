/*
 Author:            cuckoo
 Date:              2017/03/12 22:08:22
 Update:            2017/08/02 21:10:38
 Problem:           Implement strStr()
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/implement-strstr

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return StrStrSecond(haystack, needle);
    }

    int StrStrFirst(string &haystack, string &needle)
    {
        int needle_size = needle.size();
        int haystack_size = haystack.size();
        if(0 == needle_size) return 0;
        for(int i = 0; i <= haystack_size - needle_size; ++i)
        {
            int j = 0;
            // find the first element which equals to the first element in needle
            while(i <= haystack_size - needle_size && haystack[i] != needle[0]) ++i;

            int temp = i;
            while(j < needle_size && haystack[temp] == needle[j])
            {
                ++j;
                ++temp;
            }
            if(j == needle_size) return i;
        }

        return -1;
    }

    // update at 2017/08/02 21:10:38
    // from http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
    int StrStrSecond(string &haystack, string &needle)
    {
        if(needle.empty())
            return 0;
        //
        vector<int> lps = ComputeLPSArray(needle);
        //
        int i = 0, j = 0;
        while(i < haystack.size())
        {
            if(haystack[i] == needle[j])
            {
                if(j == needle.size() - 1)              // the last character match
                {
                    return i - needle.size() + 1;
                    // std::cout << "Found pattern at index " << i - j << std::endl;
                    // j = lps[j - 1];
                }
                else
                {
                    ++i;
                    ++j;
                }
            }
            else        // mismatch after j matches
            {
                if(j == 0)
                    ++i;
                else
                    j = lps[j - 1];
            }
        }
        //
        return -1;
    }
    //
    vector<int> ComputeLPSArray(string &s)
    {
        // lps[i] represents the longest proper prefix of s[0...i] which is also a suffix of s[0...i]
        int n = s.size();
        vector<int> lps(n, 0);
        //
        int len = 0;        // the length of previous longest prefix suffix
        int i = 1;
        while(i < n)
        {
            if(s[i] == s[len])          // match
            {
                ++len;
                lps[i] = len;
                ++i;
            }
            else
            {
                if(len == 0)
                {
                    lps[i] = 0;
                    ++i;
                }
                else                    // find the next smaller longest prefix suffix
                {
                    len = lps[len - 1];
                }
            }
        }
        //
        return lps;
    }
};

