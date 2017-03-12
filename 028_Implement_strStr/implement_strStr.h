/*
 Author:            cuckoo
 Date:              2017/03/12 22:08:22
 Update:
 Problem:           Implement strStr()
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/implement-strstr

 */

#include <string>
using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return strStr_1(haystack, needle);
    }

    int strStr_1(string &haystack, string &needle)
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
};

