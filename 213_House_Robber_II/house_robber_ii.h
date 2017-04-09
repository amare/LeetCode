/*
 Author:            cuckoo
 Date:              2017/04/08 10:22:53
 Update:            
 Problem:           House Robber II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/house-robber-ii/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for max()

class Solution {
public:
    int rob(vector<int>& nums) {
        return rob_1_update(nums);
    }
    
    int rob_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return 0;
        if(1 == size) return nums[0];
        
        // not rob the first house
        int previous_prev = 0, previous = 0;
        for(int i = 1; i < size; ++i)
        {
            int current = std::max(previous_prev + nums[i], previous);
            previous_prev = previous;
            previous = current;
        }
        
        // not rob the last hous
        int rob_previous_prev = 0, rob_previous = 0;
        for(int i = 0; i < size - 1; ++i)
        {
            int current = std::max(rob_previous_prev + nums[i], rob_previous);
            rob_previous_prev = rob_previous;
            rob_previous = current;
        }
        
        return std::max(previous, rob_previous);
    }
    
    int rob_1_update(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return 0;
        if(1 == size) return nums[0];
        
        return std::max(robAux(nums, 0, size - 1), robAux(nums, 1, size));
    }
    
private:
    int robAux(vector<int> &nums, int first, int last)
    {
        int previous_prev = 0, previous = 0;
        for(int i = first; i < last; ++i)
        {
            previous_prev = std::max(previous_prev + nums[i], previous);
            std::swap(previous_prev, previous);
        }
        
        return previous;
    }
};
