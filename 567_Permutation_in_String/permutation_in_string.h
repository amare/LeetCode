/*
 Author:            cuckoo
 Date:              2017/08/16 16:46:19
 Update:            
 Problem:           Permutation in String
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/permutation-in-string/description/

 */

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        return CheckInclusionSecond(s1, s2);
    }
    
    bool CheckInclusionFirst(string &s1, string &s2)
    {
        unordered_map<char, int> hash;
        for(auto c : s1)
            ++hash[c];
        
        int count = s1.size(), begin = 0, end = 0;
        while(end < s2.size())
        {
            if(hash[s2[end]] > 0)
                --count;
            --hash[s2[end]];
            // ++end;
            
            if(end + 1 - begin > s1.size())             // window's length is larger than s1.size()
            {
                ++hash[s2[begin]];
                if(hash[s2[begin]] > 0)
                    ++count;
                ++begin;
            }
            ++end;
            
            if(count == 0)
                return true;
        }
        
        return false;
    }
    
    bool CheckInclusionSecond(string &s1, string &s2)
    {
        unordered_map<char, int> counts, window;
        for(auto c : s1)
            ++counts[c];
        
        int begin = 0, count = 0;
        for(int end = 0; end < s2.size(); ++end)
        {
            ++window[s2[end]];
            if(window[s2[end]] <= counts[s2[end]])
                ++count;
            
            if(end + 1 - begin > s1.size())
            {
                --window[s2[begin]];
                if(window[s2[begin]] < counts[s2[begin]])
                    --count;
                ++begin;
            }
            
            if(count == s1.size())
                return true;
        }
        
        return false;
    }
};
