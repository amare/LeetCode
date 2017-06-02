/*
 Author:            cuckoo
 Date:              2017/05/27 16:36:38
 Update:            
 Problem:           Longest Uncommon Subsequence II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/longest-uncommon-subsequence-ii/#/description

 */

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>        // for sort()

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        return findLUSlengthThird(strs);
    }
    
    /*
    int findLUSlengthFirst(vector<string>& strs)
    {
        int index = 0;
        while(index < strs.size() - 1 && strs[index] == strs[index + 1])
            ++index;
        if(index == strs.size() - 1)
            return -1;
        
        int result = 0;
        for(auto &s : strs)
            result = std::max(result, static_cast<int>(s.size()));
            
        return result;
    }
    */
    
    // Brute Force
    void GetSubsequences(string &s, unordered_set<string> &subsequences)
    {
        subsequences.clear();
        subsequences.insert(string(""));

        for(int i = 0; i < s.size(); ++i)
        {
            unordered_set<string> temp = subsequences;
            for(auto &subseq : subsequences)
                temp.insert(subseq + s[i]);
            
            subsequences = std::move(temp);
        }
    }
    int findLUSlengthSecond(vector<string>& strs)
    {
        unordered_set<string> subsequences;
        unordered_map<string, int> hash;
        
        for(auto &s : strs)
        {
            GetSubsequences(s, subsequences);
            for(auto &subseq : subsequences)
            {
                if(hash.find(subseq) != hash.end())
                    ++hash[subseq];
                else
                    hash[subseq] = 1;
            }
        }
        
        int result = -1;
        for(auto &m : hash)
            if(m.second == 1)
                result = std::max(result, static_cast<int>(m.first.size()));    
        
        return result;
    }
    
    
    bool IsS1SubseqOfS2(string &s1, string &s2)
    {
        if(s1.size() > s2.size())
            return false;
        
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size())
        {
            if(s1[i] == s2[j])
                ++i;
            ++j;
        }
        
        return i == s1.size();
    }
    int findLUSlengthThird(vector<string>& strs)
    {
        auto compare = [](string s1, string s2){
            return s1.size() > s2.size() || s1.size() == s2.size() && s1 < s2;
        };
        
        std::sort(strs.begin(), strs.end(), compare);
        
        unordered_map<string, int> hash;
        for(auto &s : strs)
            ++hash[s];
        for(int i = 0; i < strs.size(); ++i)
        {
            if(hash[strs[i]] == 1)
            {
                int j = 0;
                while(j < i)
                {
                    if(IsS1SubseqOfS2(strs[i], strs[j]))
                        break;
                    ++j;
                }
                if(j == i)
                    return strs[i].size();
            }
        }
            
        return -1;
    }
    
};
