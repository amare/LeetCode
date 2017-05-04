/*
 Author:            cuckoo
 Date:              2017/05/04 10:23:55
 Update:            
 Problem:           Isomorphic Strings
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/isomorphic-strings/#/description

 */

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphicFirst(s, t);
    }
    
    // check is necessary, because no two characters may map to the same character
    bool check(unordered_map<char, char> &map, char new_char)
    {
        for(auto &m : map)
            if(m.second == new_char)
                return false;
        return true;
    }
    bool isIsomorphicFirst(string &s, string &t)
    {
        int s_size = s.size(), t_size = t.size();
        if(s_size != t_size) return false;
        
        unordered_map<char, char> hash;
        for(int i = 0; i < s_size; ++i)
        {
            if(hash.find(s[i]) != hash.end())
                if(hash[s[i]] != t[i])
                    return false;
                else
                    continue;
            
            if(!check(hash, t[i]))
                return false;
            hash.insert({s[i], t[i]});
        }
        
        return true;
    }

    bool isIsomorphicSecond(string &s, string &t)
    {
        int s_size = s.size(), t_size = t.size();
        if(s_size != t_size) return false;
        
        vector<char> s_to_t(128, -1), t_to_s(128, -1);
        for(int i = 0; i < s_size; ++i)
        {
            if(s_to_t[s[i]] == -1 && t_to_s[t[i]] == -1)
            {
                s_to_t[s[i]] = t[i];
                t_to_s[t[i]] = s[i];
            }
            else
            {
                if(s_to_t[s[i]] != t[i] || t_to_s[t[i]] != s[i])
                    return false;
            }
        }
        
        return true;
    }
};
