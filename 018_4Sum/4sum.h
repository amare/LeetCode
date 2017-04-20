/*
 Author:            cuckoo
 Date:              2017/04/19 20:11:14
 Update:            
 Problem:           4Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/4sum/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for sort()

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return fourSum1(nums, target);
    }
    
    vector<vector<int>> fourSum1(vector<int>& nums, int target)
    {
        int size = nums.size();
        if(size < 4) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < size; ++i)
        {
            for(int j = i + 1; j < size; ++j)
            {
                int target_two_sum = target - nums[i] - nums[j], head = j + 1, tail = size - 1;
                int two_sum = 0;
                
                while(head < tail)
                {
                    two_sum = nums[head] + nums[tail];
                    if(two_sum < target_two_sum)
                        ++head;
                    else if(two_sum > target_two_sum)
                        --tail;
                    else
                    {
                        vector<int> quadruplets = {nums[i], nums[j], nums[head], nums[tail]};
                        while(head < tail && nums[head] == quadruplets[2]) ++head;
                        while(head < tail && nums[tail] == quadruplets[3]) --tail;
                        result.push_back(std::move(quadruplets));
                    }
                }
                while(j + 1 < size && nums[j+1] == nums[j]) ++j;
            }
            while(i + 1 < size && nums[i+1] == nums[i]) ++i;
        }
        
        return result;
    }
};
