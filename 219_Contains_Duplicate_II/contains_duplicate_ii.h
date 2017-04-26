/*
 Author:            cuckoo
 Date:              2017/04/26 19:46:23
 Update:            
 Problem:           Contains Duplicate II
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/contains-duplicate-ii/#/description

 */

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        return containsNearbyDuplicateFirst(nums, k);   
    }
    
    bool containsNearbyDuplicateFirst(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;
        
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            auto iter = hash.find(nums[i]);
            if(iter != hash.end())
                if(i - iter->second <= k)
                    return true;
                else 
                    iter->second = i;
            else
                hash.insert({nums[i], i});
        }
        
        return false;
    }
};
