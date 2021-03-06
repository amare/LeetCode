/*
 Author:            cuckoo
 Date:              2017/02/27 22:01:26
 Update:            2017/03/28 15:38:04 | 2017/07/22 14:13:20
 Problem:           Longest Substring Without Repeating Characters
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/longest-substring-without-repeating-characters/
 Note:
 Given a string, find the length of the longest substring without repeating characters.

 Input: "abcabcbb"
 Output: 3

 Solution: 1. add to substring one by one. O((1+2+...+n)*256)
                [a][ab][abc]
                [b][bc][bca]
                [c][ca][cab]
                [a][ab][abc]
                [b][bc]
                [c][cb]
                [b]
                [b]
           2. divide into different block, and then check if there is repeated char. O(n*n*n)
              ***HORRIBLE!! ALOMOSTLY WRONG!!***
                [abcabcbb]
                [abcabcb][bcabcbb]
                [abcabc][bcabcb][cabcbb]
                [abcab][bcabc][cabcb][abcbb]
                [abca][bcab][cabc][abcb][bcbb]
                [abc][bca][cab][abc][bcb][cbb]
                [ab][bc][ca][ab][bc][cb][bb]
                [a][b][c][a][b][c][b][b]

           https://leetcode.com/articles/longest-substring-without-repeating-characters/
           3. Sliding Window - set
           4. Sliding Window Optimized - map
           5. Sliding Window Optimized - vector

 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::max;

#include <map>
using std::map;

#include <set>
using std::set;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstringSixth(s);
    }
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
    
    // Fail: Time Limit Exceeded
    int lengthOfLongestSubstring_2(string s)
    {
        int longest = 0;
        int length = s.size();
        for(int n = length; n > 0; --n)
        {
            cout << "n = " << n << endl;

            int move = length - n;  // move block
            for(int start = 0; start <= move; ++start)
            {
                //if there is repeated char or not
                string sub_string = s.substr(start, n);
                int frequency[256] = {0};
                //
                auto iter = sub_string.begin();         // the size of substring is n
                for(; iter != sub_string.end(); ++iter)
                {
                    if(frequency[*iter] >= 1)
                    {
                        cout << "repeated char: " << *iter << endl;
                        break;
                    }
                    frequency[*iter]++;
                }
                if(iter == sub_string.end())
                {
                    if(longest < sub_string.size())
                    {
                        longest = sub_string.size();
                        cout << sub_string << endl;
                    }
                }
            }
        }
        //
        return longest;
    }
    
    int lengthOfLongestSubstring_3(string s)
    {
        int n = s.size();
        int i = 0, j = 0, max_length = 0;
        set<char> sub_string;
        while(i < n && j < n)
        {
            if(sub_string.find(s.at(j)) == sub_string.end())    //find: O(log(n))
            {
                sub_string.insert(s.at(j++));
                max_length = max(max_length, static_cast<int>(sub_string.size()));
            }
            else
            {
                sub_string.erase(sub_string.find(s.at(i++)));
            }
        }
        
        return max_length;
    }
    
    int lengthOfLongestSubstring_4(string s)
    {
        map<char, size_t> sub_string;
        size_t max_length = 0, start = 0;
        for(size_t end = 0; end < s.size(); ++end)
        {
            auto found = sub_string.find(s.at(end));
            if(found != sub_string.end() && found->second >= start)     // repeated
            {
                max_length = max(max_length, end - start);
                start = found->second + 1;
            }
            sub_string[s.at(end)] = end;
        }
        
        return max(max_length, s.size() - start);
    }
    
    int lengthOfLongestSubstring_5(string s)
    {
        vector<int> sub_string(256, -1);
        size_t max_length = 0, start = 0;
        for(size_t end = 0; end < s.size(); ++end)
        {
            int found = sub_string[s.at(end)];
            if(found != -1 && found >= start)
            {
                max_length = max(max_length, end - start);
                start = found + 1;
            }
            sub_string[s.at(end)] = end;
        }
        
        return max(max_length, s.size() - start);
    }
    
    int lengthOfLongestSubstring_6(string &s)
    {
        vector<int> hash(128, 0);
        size_t begin = 0, end = 0, max_length = 0;
        size_t size = s.size(), count = 0;
        while(end < size)
        {
            if(hash[s[end]] > 0)
                ++count;
            ++hash[s[end]];
            ++end;
            while(count > 0)
            {
                if(hash[s[begin]] > 1)
                    --count;
                --hash[s[begin]];
                ++begin;
            }
            max_length = max(max_length, end - begin);
        }
        
        return max_length;
    }
    
    // update at 2017/07/22 14:13:29
    int lengthOfLongestSubstringSixth(string &s)
    {
        int result = 0;
        
        unordered_set<char> window;
        int begin = 0, end = 0;
        while(end < s.size())
        {
            if(window.count(s[end]))
            {                
                // shrink the window
                while(s[begin] != s[end])
                {
                    window.erase(s[begin]);
                    ++begin;
                }
                ++begin;
            }
            else
            {
                window.insert(s[end]);
                // update the length of the current longest substring without repeating character
                result = std::max(result, static_cast<int>(window.size()));
            }
            
            ++end;
        }
        
        return result;
    }
};
