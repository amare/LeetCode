/*
 Author:            cuckoo
 Date:              2017/03/21 16:53:20
 Update:
 Problem:           Group Anagrams
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/anagrams

 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

#include <algorithm>    // for sort()


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return groupAnagrams_2(strs);
    }

    bool isAnagram(string &s1, string &s2)
    {
        int s1_size = s1.size(), s2_size = s2.size();
        if(s1_size != s2_size) return false;

        vector<int> count(26, 0);
        for(int i = 0; i < s1_size; ++i)
        {
            ++count[s1[i] - 'a'];
            --count[s2[i] - 'a'];
        }

        for(auto i : count)
            if(i != 0)
                return false;
        return true;
    }
    // Time limit Exceeded
    vector<vector<string>> groupAnagrams_1(vector<string>& strs)
    {
        vector<vector<string>> result;
        for(auto &str : strs)
        {
            int i = 0;
            bool is_find = false;
            while(i < result.size())
            {
                if(isAnagram(str, result[i][0]))
                {
                    result[i].push_back(str);
                    is_find = true;
                    break;
                }
                ++i;
            }
            if(!is_find)
            {
                vector<string> temp(1, str);
                result.push_back(std::move(temp));
            }
        }

        return result;
    }

    // ======
    vector<vector<string>> groupAnagrams_2(vector<string>& strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hash;
        for(const auto &str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(str);
        }
        for(auto &v : hash)
        {
            result.push_back(std::move(v.second));
        }

        return result;
    }
};
