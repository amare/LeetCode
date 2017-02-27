/*
 Author:            cuckoo
 Date:              2017/02/27 22:01:26
 Update:
 Problem:           Longest Substring Without Repeating Characters
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/longest-substring-without-repeating-characters/
 Note:
 Given a string, find the length of the longest substring without repeating characters.

 Input: "abcabcbb"
 Output: 3

 Solution: 1. search substring one by one. O(n*n*n)

 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <string>
using std::string;


//
int lengthOfLongestSubstring_1(string s)
{
    vector<char> current_substring;
    int longest = 0;
    //
    for(auto iter = s.begin(); iter != s.end(); ++iter)
    {
        current_substring.clear();
        current_substring.push_back(*iter);
        //
        auto iter2 = iter + 1;
        for(; iter2 != s.end(); ++iter2)
        {
            bool breakflag = false;
            auto iter3 = current_substring.begin();
            for(; iter3 != current_substring.end(); ++iter3)
            {
                if(*iter2 == *iter3)
                {
                    if(longest < current_substring.size())
                    {
                        longest = current_substring.size();
                    }
                    breakflag = true;
                    break;
                }
            }
            //
            if(breakflag)
            {
                break;
            }
            if(iter3 == current_substring.end())
            {
                current_substring.push_back(*iter2);
            }
        }
        if(iter2 == s.end())
        {
            if(longest < current_substring.size())
            {
                longest = current_substring.size();
            }
        }
    }

    return longest;
}

int lengthOfLongestSubstring(string s)
{
    return lengthOfLongestSubstring_1(s);
}

int main()
{
    string s;
    while(cin >> s)
    {
        cout << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
