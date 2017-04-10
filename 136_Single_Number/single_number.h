/*
 Author:            cuckoo
 Date:              2017/04/10 22:37:16
 Update:            
 Problem:           Single Number
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/single-number/#/description

 */

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return singleNumber_2(nums);
    }
    
    int singleNumber_1(vector<int>& nums)
    {
        int result = 0;
        for(auto i : nums)
            result ^= i;
        
        return result;
    }
    
    int singleNumber_2(vector<int>& nums)
    {
        unordered_set<int> hash;
        for(auto i : nums)
        {
            if(hash.find(i) == hash.end())
                hash.insert(i);
            else
                hash.erase(i);
        }

        return *(hash.begin());
    }
};
