/*
 Author:            cuckoo
 Date:              2017/03/03 10:57:36
 Update:
 Problem:           Longest Palindromic Substring
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/longest-palindromic-substring

 */

#include <string>
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        return LongestPalindrome_3(s);
    }

    bool IsPalindrome(string &s, int i, int j)
    {
        while(i < j && s.at(i) == s.at(j))
        {
            ++i;
            --j;
        }
        if(j <= i)
            return true;
        return false;
    }

    string LongestPalindrome_1(string &s)
    {
        int size = s.size();
        int longest_i = 0, longest_j = 0;

        for(int i = 0; i <= size - 2; ++i)
        {
            for(int j = size - 1; j > i; --j)
            {
                if(longest_j - longest_i >= j - i)
                {
                    break;
                }

                if(IsPalindrome(s, i, j))
                {
                    if(j-i > longest_j-longest_i)
                    {
                        longest_j = j;
                        longest_i = i;
                        break;
                    }
                }
            }

        }

        return s.substr(longest_i, longest_j-longest_i+1);
    }

    int ExpandAroundCenter(string &s, int left, int right)
    {
       while(left >= 0 && right < s.size() && s.at(left) == s.at(right))
       {
           --left;
           ++right;
       }

       return right - left - 1; // attention
    }
    string LongestPalindrome_2(string &s)
    {
        int size = s.size();
        int start = 0, end = 0;
        for(int i = 0; i < size; ++i)
        {
            int len1 = ExpandAroundCenter(s, i, i);
            int len2 = ExpandAroundCenter(s, i, i+1);
            int len = len1 >= len2 ? len1 : len2;

            if(len > end - start + 1)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    string LongestPalindrome_3(string &s)
    {
        bool form[1000][1000];
        int size = s.size();
        int longest_i = 0, longest_j = 0;

        for(int i = 0; i < size; ++i)
        {
            for(int j = i; j < size; ++j)
            {
                form[i][j] = false;
            }
        }
        // P(i, i) = true
        for(int i = 0; i < size; ++i)
        {
            form[i][i] = true;
            longest_j = i;
            longest_i = i;
        }
        // P(i, i+1) == (S(i) == S(i+1))
        for(int i = 0; i < size - 1; ++i)
        {
            if(s.at(i) == s.at(i+1))
            {
                form[i][i+1] = true;
                longest_j = i + 1;
                longest_i = i;
            }
        }

        // P(i, j) == (P(i+1, j-1) && S(i) == S(j))
        for(int k = 2; k < size; ++k)
        {
            for(int i = 0; i < size - k; ++i)
            {
                if(form[i+1][i+k-1] && s.at(i) == s.at(i+k))
                {
                    form[i][i+k] = true;
                    if(i+k - i > longest_j - longest_i)
                    {
                        longest_j = i+k;
                        longest_i = i;
                    }
                }
            }
        }

        return s.substr(longest_i, longest_j - longest_i + 1);
    }
};
