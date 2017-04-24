/*
 Author:            cuckoo
 Date:              2017/04/21 21:49:01
 Update:            
 Problem:           Is Subsequence
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/is-subsequence/#/description

 */

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        return isSubsequenceSecond(s, t);
    }
    
    // two pointer
    bool isSubsequenceFirst(string &s, string &t)
    {
        int s_size = s.size(), t_size = t.size();
        if(s_size > t_size) return false;
        
        int s_index = 0, t_index = 0;
        while(s_index < s_size && t_index < t_size)
        {
            while(t_index < t_size && s[s_index] != t[t_index]) ++t_index;
            if(t_index == t_size) return false;
            ++s_index;
            ++t_index;
        }
        
        if(s_index == s_size)
            return true;
    
        return false;
    }
    
    // 返回第一个大于target的值, 不存在则返回-1
    int BinarySearch(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return start == nums.size() ? -1 : nums[start];
    }
    // Follow Up Solution
    bool isSubsequenceSecond(string &s, string &t)
    {
        int t_size = t.size();
        
        unordered_map<char, vector<int>> hash;
        for(int i = 0; i < t_size; ++i)
        {
            if(hash.find(t[i]) == hash.end())
                hash.insert({t[i], vector<int>()});
            hash[t[i]].push_back(i);
        }
        
        int s_size = s.size(), index = -1;
        for(int i = 0; i < s_size; ++i)
        {
            char c = s[i];
            if(hash.find(c) == hash.end())
                return false;
            
            vector<int> temp = hash[c];
            index = BinarySearch(temp, index);
            if(index == - 1)
                return false;
        }
        
        return true;
    }
};
