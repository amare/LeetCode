/*
 Author:            cuckoo
 Date:              2017/03/02 10:18:59
 Update:
 Problem:           Roman to Integer
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/roman-to-integer/

 */

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> hash;
        hash.insert({'I', 1});
        hash.insert({'V', 5});
        hash.insert({'X', 10});
        hash.insert({'L', 50});
        hash.insert({'C', 100});
        hash.insert({'D', 500});
        hash.insert({'M', 1000});

        int ret = hash[s.at(0)];
        char pre, cur;
        for(int i = 1; i < s.size(); ++i)
        {
            pre = s.at(i - 1);
            cur = s.at(i);
            if(hash[cur] <= hash[pre])
            {
                ret += hash[cur];
            }
            else
            {
                ret = ret + hash[cur] - 2 * hash[pre];
            }
        }
        return ret;
    }
};
