/*
 Author:            cuckoo
 Date:              2017/04/07 18:28:07
 Update:            
 Problem:           Word Break
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/word-break/#/description

 */

#include <cmath>        // for max(), min()

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <queue>
using std::queue;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreak_1(s, wordDict);
    }
    
    bool wordBreak_1(string &s, vector<string> &wordDict)
    {
        int size = s.size();
        
        int max_length = 0;
        unordered_set<string> hash;
        for(auto &str : wordDict)
        {
            hash.insert(str);
            max_length = std::max(max_length, static_cast<int>(str.size()));
        }
        
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= size; ++i)
        {
            for(int j = i - 1; j >= std::max(0, i - max_length); --j)
            {
                if(dp[j])
                {
                    string word = s.substr(j, i - j);
                    if(hash.find(word) != hash.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[size];
    }

    // BFS
    bool wordBreak_2(string &s, vector<string> &wordDict)
    {
        int size = s.size();
        int max_length = 0, min_length = 0;
        unordered_set<string> word_dicts;
        for(auto &word : wordDict)
        {
            word_dicts.insert(word);
            max_length = std::max(max_length, static_cast<int>(word.size()));
            min_length = std::min(min_length, static_cast<int>(word.size()));
        }
        
        unordered_set<int> is_visited;  // keep track of the visited nodes to avoid repeating the same work
        queue<int> visit;       // traversal the graph using BFS 
        visit.push(0);
        while(!visit.empty())
        {
            int start = visit.front();
            visit.pop();
            if(is_visited.find(start) == is_visited.end())
            {
                is_visited.insert(start);
                for(int end = start + min_length - 1; end < std::min(start + max_length, static_cast<int>(size)); ++end)
                {
                    string word = s.substr(start, end - start + 1);
                    if(word_dicts.find(word) != word_dicts.end())
                    {
                        if(end + 1 == size)
                            return true;
                        visit.push(end + 1);
                    }
                }
            }
            
        }
        
        return false;
    }
};
