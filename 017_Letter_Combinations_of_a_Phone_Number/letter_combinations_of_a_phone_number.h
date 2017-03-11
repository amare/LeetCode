/*
 Author:            cuckoo
 Date:              2017/03/11 10:13:08
 Update:
 Problem:           Letter Combinations of a Phone Number
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/letter-combinations-of-a-phone-number

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

#include <iostream>
using std::cout;
using std::endl;

class Solution {
static unordered_map<char, vector<char>> map_table;
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinations_1(digits);
    }

    void BackTracking(int row, string &digits, string &local, vector<string> &ans)
    {
        //string temp = local;
        if(row == digits.size())
        {
            ans.push_back(local);
            return;
        }

        for(int col = 0; col < map_table[digits[row]].size(); ++col)
        {
            //local += map_table[digits[row]][col];
            local.push_back(map_table[digits[row]][col]);
            BackTracking(row + 1, digits, local, ans);
            //local = temp; // backtracking
            local.pop_back();
        }
    }

    vector<string> letterCombinations_1(string &digits)
    {
        vector<string> ans;
        if(digits.empty()) return ans;
        string local;
        BackTracking(0, digits, local, ans);

        return ans;
    }


    vector<string> letterCombinations_2(string &digits)
    {
        if(digits.empty()) return vector<string>();
        static const vector<string> charmap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        result.push_back("");  // add a seed for the initial case
        for(int i = 0; i < digits.size(); ++i)
        {
            int num = digits[i] - '0';
            if(num < 0 || num > 9) break;
            const string &candidate = charmap[num];
            if(candidate.empty()) continue;
            vector<string> temp;
            for(int j = 0; j < candidate.size(); ++j)
                for(int k = 0; k < result.size(); ++k)
                    temp.push_back(result[k] + candidate[j]);
            result.swap(temp);  // swap does not take memory copy
        }

        return result;
    }
};

unordered_map<char, vector<char>> Solution::map_table = {
        {'0', {}},
        {'1', {}},
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}},
    };


