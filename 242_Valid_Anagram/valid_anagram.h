/*
 Author:            cuckoo
 Date:              2017/03/21 16:12:00
 Update:
 Problem:           Valid Anagram
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/valid-anagram

 */

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

#include <set>
using std::multiset;

#include <algorithm>    // for sort()

class Solution {
public:
    bool isAnagram(string s, string t) {
        return isAnagram_6(s, t);
    }
    /*
    // Time Limit Exceeded
    bool isAnagram_1(string &s, string &t)
    {
        sort(s.begin(), s.end());
        do
        {
            if(s == t)
                return true;
        }while(next_permutation(s.begin(), s.end()));

        return false;
    }

    // backtracking - Time Limit Exceeded
    bool backtracking(string &s, int index, string &t)
    {
        if(index >= s.size())
        {
            if(s == t)
                return true;
        }

        for(int i = index; i < s.size(); ++i)
        {
            swap(s[i], s[index]);
            if(backtracking(s, index + 1, t))
                return true;
            swap(s[i], s[index]);
        }
        return false;
    }
    bool isAnagram_2(string &s, string &t)
    {
        return backtracking(s, 0, t);
    }
    */

    bool isAnagram_3(string &s, string &t)
    {
        multiset<char> hash1, hash2;
        for(auto ch : s) hash1.insert(ch);
        for(auto ch : t) hash2.insert(ch);
        if(hash1 == hash2) return true;
        return false;
    }

    bool isAnagram_4(string &s, string &t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    bool isAnagram_5(string &s, string &t)
    {
        int s_size = s.size(), t_size = t.size();
        if(s_size != t_size) return false;

        vector<int> count(26, 0);
        for(int i = 0; i < s_size; ++i)
        {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }

        for(auto i : count)
            if(i != 0)
                return false;
        return true;
    }

    bool isAnagram_6(string &s, string &t)
    {
        int s_size = s.size(), t_size = t.size();
        if(s_size != t_size) return false;

        unordered_map<char, int> count;
        for(int i = 0; i < s_size; ++i)
        {
            ++count[s[i]];
            --count[t[i]];
        }

        for(auto &i : count)
            if(i.second != 0)
                return false;
        return true;
    }
};
