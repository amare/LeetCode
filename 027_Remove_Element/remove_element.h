/*
 Author:            cuckoo
 Date:              2017/04/19 20:51:23
 Update:            
 Problem:           Remove Element
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/remove-element/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for swap()

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return removeElement1(nums, val);
    }
    
    int removeElement1(vector<int>& nums, int val)
    {
        int start = 0, tail = nums.size() - 1;
        while(start <= tail)
        {
            if(nums[start] == val)
                std::swap(nums[start], nums[tail--]);
            else
                ++start;
        }
        
        return start;
    }
};
