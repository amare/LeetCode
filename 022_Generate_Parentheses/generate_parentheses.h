/*
 Author:            cuckoo
 Date:              2017/03/11 21:49:55
 Update:
 Problem:           Generate Parentheses
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/generate-parentheses

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesis_1(n);
    }

    bool valid(string &local, int n)
    {
        int left_num = 0;
        for(char c : local)
            if('(' == c)
                ++left_num;
        return (left_num <= n && left_num >= local.size() - left_num) ? true : false;
    }

    void BackTracking(vector<string> &result, string &local, int n, int row)
    {
        if(row >= 2 * n)
        {
            result.push_back(local);
            return;
        }

        local.push_back('(');
        if(valid(local, n))
            BackTracking(result, local, n, row + 1);
        local.pop_back();

        local.push_back(')');
        if(valid(local, n))
            BackTracking(result, local, n, row + 1);
        local.pop_back();
    }

    vector<string> generateParenthesis_1(int n)
    {
        if(n < 0) return vector<string>();
        vector<string> result;
        string local;
        BackTracking(result, local, n, 0);

        return result;
    }
};
