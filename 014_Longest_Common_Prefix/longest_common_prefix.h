/*
 Author:            cuckoo
 Date:              2017/03/09 22:25:01
 Update:
 Problem:           Longest Common Prefix
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/longest-common-prefix

 */
#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix_2(strs);
    }

    string longestCommonPrefix_1(vector<string>& strs)
    {
        string longest("");
        int size = strs.size();
        if(size == 0) return string("");
        if(size == 1) return strs.at(0);

        // find longest common prefix string<temp> between the first string and the second string
        string first = strs.at(0);
        string second = strs.at(1);
        string temp("");
        int i = 0, j = 0;
        while(i < first.size() && j < second.size() && first.at(i) == second.at(j))
        {
            temp = temp + first.at(i);
            ++i;
            ++j;
        }

        // match other strings in the arrays using character in the string<temp> one by one
        for(int i = 0; i < temp.size(); ++i)
        {
            int j = 2;
            while(j < strs.size() && i < strs.at(j).size() && strs.at(j).at(i) == temp.at(i))
            {
                ++j;
            }
            if(j == strs.size())
                longest = longest + temp.at(i);
        }

        return longest;
    }

    string longestCommonPrefix_2(vector<string>& strs)
    {
        if(strs.empty()) return "";
        for(int i = 0; i < strs[0].size(); ++i)
            for(int j = 0; j < strs.size(); ++j)
                if(i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0,i);
        return strs[0];
    }
};
