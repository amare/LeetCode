/*
 Author:            cuckoo
 Date:              2017/04/26 19:23:23
 Update:            
 Problem:           Contains Duplicate
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/contains-duplicate/#/description

 */

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return containsDuplicateFirst(nums);
    }
    
    bool containsDuplicateFirst(vector<int>& nums)
    {
        unordered_set<int> hash;
        
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(hash.find(nums[i]) != hash.end())
                return true;
            hash.insert(nums[i]);
        }
        
        return false;
    }
};
