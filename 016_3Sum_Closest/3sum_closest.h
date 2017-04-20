/*
 Author:            cuckoo
 Date:              2017/04/19 19:44:11
 Update:            
 Problem:           3Sum Closest
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/3sum-closest/#/description

 */

#include <climits>      // for LONG_MAX
#include <cmath>

#include <vector>
using std::vector;

#include <algorithm>    // for sort()

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return ThreeSumClosest1(nums, target);
    }
    
    int ThreeSumClosest1(vector<int>& nums, int target)
    {
        int size = nums.size();
        if(size < 3) return target;
        
        long abs_distance = LONG_MAX, distance = LONG_MAX;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; ++i)
        {
            long target_two_sum = target - nums[i], head = i + 1, tail = size - 1;
            
            long two_sum = 0;
            while(head < tail)
            {
                two_sum = nums[head] + nums[tail];      // sum is larger than INT_MAX?
                if(two_sum == target_two_sum)
                    return target;
                else if(two_sum > target_two_sum)
                    --tail;
                else
                    ++head;
                
                if(std::abs(two_sum - target_two_sum) < abs_distance)
                {
                    distance = two_sum - target_two_sum;
                    abs_distance = std::abs(distance);
                }
            }
            while(i + 1 < size && nums[i+1] == nums[i]) ++i;
        }
        
        return target + distance;
    }
};
