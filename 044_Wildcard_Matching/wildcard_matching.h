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
    // Time Limit Exceeded?     @gps: maybe the copy of the string? see isMatch_4
    bool isMatch_1_v2(string &s, string &p)
    {
        if(p.empty()) return s.empty();
        if(p[0] == '*')
        {
            // DeleteDulplicateAsterisk(p);
            int i = 0;
            while(i + 1 < p.size() && p[i + 1] == '*') ++i;     // skip duplicate '*'

            string new_p = p.substr(i + 1);
            bool ret = isMatch_1(s, new_p);

            bool ret2 = false;
            if(!s.empty())
            {
                string new_s = s.substr(1);
                ret2 = isMatch_1(new_s, p);
            }

            return ret || ret2;
        }
        else if(!s.empty())
        {
            string new_p = p.substr(1);
            string new_s = s.substr(1);
            return (s[0] == p[0] || p[0] == '?') && isMatch_1(new_s, new_p);
        }
        else
        {
            return false;
        }
    }

    // ==========
    // Dynamic Programming
    bool isMatch_2(string &s, string &p)
    {
        int s_size = s.size(), p_size = p.size();
        vector<vector<bool>> table(s_size + 1, vector<bool>(p_size + 1, false));
        // initialize table
        table[0][0] = true;
        for(int j = 1; j <= p_size; ++j)
        {
            if(p[j-1] == '*')
                table[0][j] = table[0][j-1];
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
            if(p_index < p_size && (s[s_index] == p[p_index] || p[p_index] == '?'))
            {
                ++s_index;
                ++p_index;
                // continue;
            }
            else if(p_index < p_size && p[p_index] == '*')
            {
                p_pre_index = p_index;
                ++p_index;
                s_pre_index = s_index;
                // continue;
            }
            else if(p_pre_index > -1)    // Backtracking
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

        while(p_index < p_size && p[p_index] == '*') ++p_index;

        return p_index == p_size;
    }

    // ==========
    // return value:
    // 0: reach the end of s but unmatched
    // 1: unmatched without reaching the end of s
    // 2: matched
    int dfs(string& s, string& p, int si, int pi)
    {
        if (si == s.size() and pi == p.size()) return 2;
        if (si == s.size() and p[pi] != '*') return 0;
        if (pi == p.size()) return 1;
        if (p[pi] == '*')
        {
            if (pi + 1 < p.size() and p[pi+1] == '*')
                return dfs(s, p, si, pi + 1); // skip duplicate '*'
            for(int i = 0; i <= s.size() - si; ++i)
            {
                int ret = dfs(s, p, si + i, pi + 1);
                if (ret == 0 or ret == 2) return ret;
            }
        }
        if (p[pi] == '?' or s[si] == p[pi])
            return dfs(s, p, si + 1, pi + 1);
        return 1;
    }

    bool isMatch_4(string &s, string &p)
    {
         return dfs(s, p, 0, 0) > 1;
    }
};
