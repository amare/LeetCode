/*
 Author:            cuckoo
 Date:              2017/03/18 17:33:25
 Update:
 Problem:           Wildcard Matching
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/wildcard-matching

 */

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch_3(s, p);
    }

    void DeleteDulplicateAsterisk(string &s)
    {
        int count = 0;
        for(auto ch : s)
        {
            if(ch == '*')
                ++count;
            else
                break;
        }
        if(count > 1)
            s = s.substr(count - 1);
    }
    // Time Limit Exceeded
    bool isMatch_1(string s, string p)
    {
        if(p.empty()) return s.empty();
        if(p[0] == '*')
        {
            DeleteDulplicateAsterisk(p);
            return (isMatch_1(s, p.substr(1)) || (!s.empty() && isMatch_1(s.substr(1), p)));
        }
        else
            return (!s.empty() && (s[0] == p[0] || p[0] == '?') && isMatch_1(s.substr(1), p.substr(1)));
    }

    // ==========
    bool isAllAsterisk(string &p, int n)
    {
        for(int i = 0; i < n; ++i)
            if(p[i] != '*')
                return false;
        return true;
    }

    // Dynamic Programming
    bool isMatch_2(string &s, string &p)
    {
        int s_size = s.size(), p_size = p.size();
        vector<vector<bool>> table(s_size + 1, vector<bool>(p_size + 1, false));
        // initialize table
        table[0][0] = true;
        for(int j = 1; j <= p_size; ++j)
        {
            if(isAllAsterisk(p, j))
                table[0][j] = true;
        }

        for(int i = 1; i <= s_size; ++i)
        {
            for(int j = 1; j <= p_size; ++j)
            {
                if(p[j-1] != '*')
                    table[i][j] = table[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                else
                    table[i][j] = table[i][j-1] || table[i-1][j];
            }
        }

        return table[s_size][p_size];
    }

    // Backtracking, two pointer
    bool isMatch_3(string &s, string &p)
    {
        int s_size = s.size(), p_size = p.size();
        int s_index = 0, p_index = 0;
        int s_pre_index = -1, p_pre_index = -1;
        while(s_index < s_size)
        {
            if(s[s_index] == p[p_index] || p[p_index] == '?')
            {
                ++s_index;
                ++p_index;
                // continue;
            }
            else if(p[p_index] == '*')
            {
                p_pre_index = p_index;
                ++p_index;
                s_pre_index = s_index;
                // continue;
            }
            else
            {
                if(p_pre_index > -1)    // Backtracking
                {
                    p_index = p_pre_index + 1;
                    s_index = ++s_pre_index;
                    // continue;
                }
                else
                {
                    return false;
                }
            }
        }

        while(p[p_index] == '*') ++p_index;

        return p_index == p_size;
    }

};
