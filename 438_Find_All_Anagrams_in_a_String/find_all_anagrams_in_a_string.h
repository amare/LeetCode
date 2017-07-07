/*
 Author:            cuckoo
 Date:              2017/07/06 21:50:13
 Update:            
 Problem:           Find All Anagrams in a String
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

#include <algorithm>            // for sort(), next_permutation()

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        return FindAnagramsFourth(s, p);
    }
    
    // Memory Limit Exceeded
    vector<int> FindAnagramsFirst(string &s, string &p)
    {
        vector<int> result;
        
        unordered_set<string> hash;
        std::sort(p.begin(), p.end());
        do
        {
            hash.insert(p);
        }while(std::next_permutation(p.begin(), p.end()));
        
        int s_size = s.size(), p_size = p.size();
        for(int i = 0; i + p_size <= s_size; ++i)
        {
            if(hash.find(s.substr(i, p_size)) != hash.end())
                result.push_back(i);
        }
        
        return result;
    }
    
    // Time Limit Exceeded
    vector<int> FindAnagramsSecond(string &s, string &p)
    {
        unordered_map<char, int> count;
        for(auto c : p)
            ++count[c];
        
        vector<int> result;
        int s_size = s.size(), p_size = p.size();
        for(int i = 0; i + p_size <= s_size; ++i)
        {
            string s2 = s.substr(i, p_size);
            if(IsAnagram(count, s2))
                result.push_back(i);
        }
        
        return result;
    }
    
    bool IsAnagram(unordered_map<char, int> &count, string &s2)
    {
        unordered_map<char, int> count2;
        for(auto c : s2)
            ++count2[c];
        for(auto c : s2)
            if(count[c] != count2[c])
                return false;
        return true;
    }
    
    // Sliding window
    vector<int> FindAnagramsThird(string &s, string &p)
    {
        vector<int> result;
        int s_size = s.size(), p_size = p.size();
        
        unordered_map<char, int> count1, count2;
        for(int i = 0; i < p_size; ++i)
        {
            ++count1[p[i]];
            ++count2[s[i]];
        }
        
        auto iter = count1.begin();
        while(iter != count1.end())
        {
            if(iter->second != count2[iter->first])
                break;
            ++iter;
        }
        if(iter == count1.end())
            result.push_back(0);
                    
        for(int i = 1; i + p_size <= s_size; ++i)
        {
            --count2[s[i-1]];
            ++count2[s[i+p_size-1]];
            
            auto iter = count1.begin();
            while(iter != count1.end())
            {
                if(iter->second != count2[iter->first])
                    break;
                ++iter;
            }
            if(iter == count1.end())
                result.push_back(i);
        }
        
        return result;
    }
    
    vector<int> FindAnagramsFourth(string &s, string &p)
    {
        unordered_map<char, int> hash;
        for(auto c : p)
            ++hash[c];
        
        vector<int> result;
        
        int begin = 0, end = 0, count = p.size();   // count represents the number of chars of p to be found in s
        
        while(end < s.size())
        {
            if(hash[s[end]] > 0)        // s[end] exists in p and the number of char s[end] in window is not larger than in p
                --count;
            --hash[s[end]];
            ++end;
            
            if(count == 0)
                result.push_back(begin);
            
            if(end - begin == p.size())
            {
                ++hash[s[begin]];
                if(hash[s[begin]] > 0)  // s[begin] exist in p and the number of char s[begin] in window
                    ++count;            // will be less than in p after slide
                ++begin;
            }
        }
        
        return result;
    }
};
