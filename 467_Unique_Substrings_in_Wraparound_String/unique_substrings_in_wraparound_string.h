/*
 Author:            cuckoo
 Date:              2017/04/24 20:25:45
 Update:            
 Problem:           Unique Substrings in Wraparound String
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/unique-substrings-in-wraparound-string/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

#include <numeric>          // for accumulate()
#include <algorithm>        // for max()

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        return findSubstringInWraproundStringSecond(p);   
    }
    
    // TLE
    int findSubstringInWraproundStringFirst(string &p)
    {
        unordered_set<string> visited;
        unordered_map<char, char> next = {
            {'b', 'a'}, {'c', 'b'}, {'d', 'c'}, {'e', 'd'}, {'f', 'e'}, {'g', 'f'},
            {'h', 'g'}, {'i', 'h'}, {'j', 'i'}, {'k', 'j'}, {'l', 'k'}, {'m', 'l'},
            {'n', 'm'}, {'o', 'n'}, {'p', 'o'}, {'q', 'p'}, {'r', 'q'}, {'s', 'r'},
            {'t', 's'}, {'u', 't'}, {'v', 'u'}, {'w', 'v'}, {'x', 'w'}, {'y', 'x'},
            {'z', 'y'}, {'a', 'z'}
        };
        
        int n = p.size();
        if(0 == n) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        visited.insert(p.substr(0, 1));
        for(int i = 1; i < n; ++i)
        {
            dp[i] = dp[i - 1];
            
            for(int j = i; j - 1 >= 0 && next[p[j]] == p[j - 1]; --j)
            {
                if(visited.find(p.substr(j - 1, i - j + 2)) == visited.end())
                {
                    visited.insert(p.substr(j - 1, i - j + 2));
                    ++dp[i];
                }
            }
            
            if(visited.find(p.substr(i, 1)) == visited.end())
            {
                visited.insert(p.substr(i, 1));
                ++dp[i];
            }
        }
        
        return dp[n - 1];
    }
    
    int findSubstringInWraproundStringSecond(string &p)
    {
        // count[i] is the maximum unique substring end with some letter.
        vector<int> count(26, 0);
        
        int n = p.size();
        if(0 == n) return 0;
        
        int max_current = 1;
        count[p[0] - 'a'] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25)
                ++max_current;
            else
                max_current = 1;
                
            count[p[i] - 'a'] = std::max(count[p[i] - 'a'], max_current);
        }
        
        return accumulate(count.begin(), count.end(), 0);
    }
};
