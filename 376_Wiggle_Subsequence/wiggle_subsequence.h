/*
 Author:            cuckoo
 Date:              2017/04/21 17:27:54
 Update:            
 Problem:           Wiggle Subsequence
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/wiggle-subsequence/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for max()

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        return wiggleMaxLength3(nums);
    }
    
    /* wrong - Compared to Editorial Solution Approach #5 Greedy
    int wiggleMaxLength1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size || 1 == size) return size;
        
        // skip repeated element to initialize varialbe max_length, is_positive and last
        int i = 1;
        while(i < size && nums[i] == nums[i-1]) ++i;
        if(i == size) return 1;
        
        bool is_positive = nums[0] - nums[i] > 0 ? true : false;
        int max_length = 2, last = nums[i];
        
        while(++i < size)
        {
            int difference = last - nums[i];
            if(difference == 0) continue;
            
            if(difference > 0 && !is_positive)
            {
                ++max_length;
                is_positive = true;
                last = nums[i];
            }
            if(difference < 0 && is_positive)
            {
                ++max_length;
                is_positive = false;
                last = nums[i];
            }
            
        }
        
        return max_length;
    }
    */
    
    // Dynamic Programming
    int wiggleMaxLength2(vector<int>& nums)
    {
        int n = nums.size();
        if(n < 2) return n;
        
        // up[i] represents the length of the longest wiggle subsequence obtained so far considering
        // ith element as the last element of the wiggle subsequence and ending with a rising wiggle.
        vector<int> up(n, 1), down(n, 1);
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                    up[i] = std::max(up[i], down[j] + 1);
                else if(nums[i] < nums[j])
                    down[i] = std::max(down[i], up[j] + 1);
            }
        }
        
        return std::max(up[n-1], down[n-1]);
    }
    
    // DP - Time Complexity: O(n)
    int wiggleMaxLength3(vector<int>& nums)
    {
        int n = nums.size();
        if(n < 2) return n;
        
        // up[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]},
        // with a positive difference between its last two numbers. This subsequence may 
        // or may not include nums[i] and there may be several such subsequences (of the 
        // same length). We call this a subsequence of type U.
        vector<int> up(n, 1), down(n, 1);
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > nums[i-1])
            {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1])
            {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else
            {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        
        return std::max(up[n-1], down[n-1]);
    }
    
    // Greedy
    int wiggleMaxLength4(vector<int>& nums)
    {
        int n = nums.size();
        if(n < 2) return n;
        
        int index = 1;
        while(index < n && nums[index] == nums[index-1]) ++index;
        if(index == n) return 1;
        
        int prev_diff = nums[index] - nums[0];
        int max_length = 2;
        while(++index < n)
        {
            int difference = nums[index] - nums[index-1];
            if(difference > 0 && prev_diff < 0 || difference < 0 && prev_diff > 0)
            {
                ++max_length;
                prev_diff = difference;
            }
        }
        
        return max_length;
    }
    
};
