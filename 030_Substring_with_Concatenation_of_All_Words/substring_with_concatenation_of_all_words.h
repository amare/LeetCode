/*
 Author:            cuckoo
 Date:              2017/07/07 17:31:18
 Update:            
 Problem:           Substring with Concatenation of All Words
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/substring-with-concatenation-of-all-words/#/description

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        return FindSubstringSecond(s, words);
    }
    
    vector<int> FindSubstringFirst(string s, vector<string>& words)
    {
        vector<int> result;
        
        unordered_map<string, int> counts;
        for(auto &word : words)
            ++counts[word];
        
        int s_size = s.size(), num = words.size(), length = words[0].size();
        for(int i = 0; i + num * length - 1 < s_size; ++i)
        {
            unordered_map<string, int> seen;
            int j = 0;
            for(; j < num; ++j)
            {
                string word = s.substr(i + j * length, length);
                if(counts.find(word) != counts.end())
                {
                    ++seen[word];
                    if(seen[word] > counts[word])
                        break;
                }
                else
                    break;
            }
            if(j == num)
                result.push_back(i);
        }
        
        return result;
    }
    
    vector<int> FindSubstringSecond(string s, vector<string>& words)
    {
        vector<int> result;
        if(s.empty() || words.empty())
            return {};
        
        unordered_map<string, int> counts;
        for(auto &word : words)
            ++counts[word];
        
        int word_length = words[0].size();
        for(int i = 0; i < word_length; ++i)
        {
            int begin = i, count = 0;           // count - the number of words in window which exist in words list as well
            unordered_map<string, int> seen;
            for(int end = i; end + word_length - 1 < s.size(); end += word_length)
            {
                string curr_word = s.substr(end, word_length);
                if(counts.count(curr_word))     // current word is in words list
                {
                    ++seen[curr_word];
                    if(seen[curr_word] <= counts[curr_word])
                        ++count;
                    else        // when the number of current word in window is larger than in words list, shrink the window
                    {
                        while(seen[curr_word] > counts[curr_word])
                        {
                            string begin_word = s.substr(begin, word_length);
                            --seen[begin_word];
                            if(seen[begin_word] < counts[begin_word])
                                --count;
                            begin += word_length;
                        }
                    }
                    
                    // when found the valid window, shrink the window
                    if(count == words.size())
                    {
                        result.push_back(begin);
                        --seen[s.substr(begin, word_length)];
                        --count;
                        begin += word_length;
                    }
                }
                else        // not valid word, reset all vars
                {
                    seen.clear();
                    begin = end + word_length;
                    count = 0;
                }
            }
        }
        
        return result;
    }
};
