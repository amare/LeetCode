/*
 Author:            cuckoo
 Date:              2017/03/22 22:15:27
 Update:
 Problem:           Jump Game
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/jump-game

 */

#include <vector>
using std::vector;

#include <algorithm>    // for max()

class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump_2(nums);
    }

    // Time Limit Exceeded
    bool jump(vector<int> &nums, int index)
    {
        if(index == nums.size() - 1) return true;
        if(index >= nums.size()) return false;
        for(int i = 1; i <= nums[index]; ++i)
            if(jump(nums, index + i)) return true;
        return false;
    }
    bool canJump_1(vector<int>& nums)
    {
        return jump(nums, 0);
    }

    //  iterate and update the maximal index that I can reach
    bool canJump_2(vector<int>& nums)
    {
        int n = nums.size();
        int reach = 0, i = 0;
        while(i < n && i <= reach)
            reach = std::max(reach, nums[i] + i++);

        return i == n;
    }
};
