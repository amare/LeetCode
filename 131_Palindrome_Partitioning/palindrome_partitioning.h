/*
 Author:            cuckoo
 Date:              2017/04/17 20:17:48
 Update:            
 Problem:           Palindrome Partitioning
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/palindrome-partitioning/#/description

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        return partition1(s);
    }
    
    bool IsPalindrome(string &s)
    {
        int start = 0, end = s.size() - 1;
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        
        return true;
    }
    void backtracking(vector<vector<string>> &result, vector<string> &single, string &s, int start)
    {
        if(start == s.size())
        {
            result.push_back(single);
            return;
        }
        for(int i = 1; start + i <= s.size(); ++i)
        {
            string temp = s.substr(start, i);
            if(IsPalindrome(temp))
            {
                single.push_back(temp);
                backtracking(result, single, s, start + i);
                single.pop_back();
            }
        }
    }
    vector<vector<string>> partition1(string &s)
    {
        vector<vector<string>> result;
        vector<string> single;
        backtracking(result, single, s, 0);
        
        return result;
    }
};
