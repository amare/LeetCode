/*
 Author:            cuckoo
 Date:              2017/05/08 19:47:19
 Update:            
 Problem:           Word Pattern
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/word-pattern/#/description

 */

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <vector>
using std::vector;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        return wordPatternSecond(pattern, str);
    }
    
    bool check(vector<string> &hash, string &word)
    {
        for(auto &s : hash)
            if(s == word)
                return false;
        return true;
    }
    int NumberOfWord(string &s)
    {
        int n = s.size(), count = 0;
        if(0 == n)
            return 0;
            
        for(int i = 0; i < n; ++i)
            if(s[i] == ' ')
                ++count;
        
        return ++count;
    }
    bool wordPatternFirst(string &pattern, string &str)
    {
        if(pattern.size() != NumberOfWord(str) || pattern.size() == 0)
            return false;
        
        vector<string> hash(26, string());
        int start = 0, end = -1, n = str.size();
        
        for(auto c : pattern)
        {
            start = end + 1;
            ++end;
            while(end < n && str[end] != ' ')
                ++end;
            
            string word = str.substr(start, end - start);
            if(hash[c - 'a'].empty() == false)
                if(hash[c - 'a'] != word)
                    return false;
                else
                    continue;
                
            if(!check(hash, word))
                return false;
            hash[c - 'a'] = word;
        }
        
        return true;
    }
    
    // faster
    bool wordPatternSecond(string &pattern, string &str)
    {
        if(pattern.size() != NumberOfWord(str) || pattern.size() == 0)
            return false;
        
        vector<string> hash(26, string());
        unordered_set<string> set;
        int start = 0, end = -1, n = str.size();
        
        for(auto c : pattern)
        {
            start = end + 1;
            ++end;
            while(end < n && str[end] != ' ')
                ++end;
            
            string word = str.substr(start, end - start);
            if(hash[c - 'a'].empty() == false)
                if(hash[c - 'a'] != word)
                    return false;
                else
                    continue;
                
            if(set.find(word) != set.end())
                return false;
            hash[c - 'a'] = word;
            set.insert(word);
        }
        
        return true;
    }
};
