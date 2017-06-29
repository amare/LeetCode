/*
 Author:            cuckoo
 Date:              2017/06/23 10:06:36
 Update:            
 Problem:           Contains Duplicate III
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/contains-duplicate-iii/#/description

 */

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <cmath>        // for abs()

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        return containsNearbyAlmostDuplicateSecond(nums, k, t);
    }
    
    // Brute Force - TLE
    bool containsNearbyAlmostDuplicateFirst(vector<int>& nums, int k, int t)
    {
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i)
        {
            for(int j = i + 1; j < n && j - i <= k; ++j)
            {
                if(std::abs(static_cast<long>(nums[i]) - nums[j]) <= t)      // out of range of int type
                    return true;
            }
        }
        
        return false;
    }
    
    // O(n * logk)
    bool containsNearbyAlmostDuplicateSecond(vector<int>& nums, int k, int t)
    {
        // preserve a sliding window containing k nearest ordered numbers
        set<long> window;       
        for(int i = 0; i < nums.size(); ++i)
        {
            // keep the window contains at most k numbers
            if(i > k)
                window.erase(nums[i-k-1]);
                
            // |x - nums[i]| <= t   =>  nums[i] - t <= x <= nums[i] + t
            // when we find the first number  x1 in window which is not less than (nums[i] - t), the next step is 
            // to check if x1 is not larger than (nums[i] + t).
            // there is not necessary to check other numbers x2 following x1 in window, because if x1 > nums[i] + t, 
            // then x2 >= x1 > nums[i] + t
            auto iter = window.lower_bound(static_cast<long>(nums[i]) - t);
            if(iter != window.end() && *iter <= static_cast<long>(nums[i]) + t)
                return true;
            
            // add new number nums[i]
            window.insert(nums[i]);
        }
        
        return false;
    }
};
