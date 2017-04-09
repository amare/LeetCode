/*
 Author:            cuckoo
 Date:              2017/04/09 15:27:54
 Update:            
 Problem:           Longest Increasing Subsequence
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/longest-increasing-subsequence/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for lower_bound()

#include <cmath>        // for max()

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLIS_2_update(nums);
    }
 
    int lengthOfLIS_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return 0;
        
        // dp[i] represents the length of longest increasing subsequence ending with nums[i]
        vector<int> dp(size, 0);
        dp[0] = 1;
        int result = dp[0];
        
        for(int i = 1; i < size; ++i)
        {
            dp[i] = 1;
            for(int j = i - 1; j >= 0; --j)
            {
                if(nums[j] < nums[i])       // means we can add nums[i] to the increasing subsequence ending with nums[j]
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    result = std::max(result, dp[i]);
                }
            }
        }
        
        return result;
    }
    
    // Time Complexity: O(nlog(n))
    int lengthOfLIS_2(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return 0;
        
        // tails is an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i]
        vector<int> tails(size, 0);
        int length = 0;
        for(int i = 0; i < size; ++i)
        {
            // binary search
            int start = 0, end = length;
            while(start < end)
            {
                int mid = start + (end - start) / 2;
                if(tails[mid] < nums[i])
                    start = mid + 1;
                else
                    end = mid;
            }
            tails[start] = nums[i];     // if tails[i-1] < x <= tails[i], update tails[i] 
            if(start == length)
                ++length;
        }
        
        return length;
    }
    
    int lengthOfLIS_2_update(vector<int>& nums)
    {
        vector<int> tails;
        for(auto i : nums)
        {
            auto iter = std::lower_bound(tails.begin(), tails.end(), i);
            if(iter == tails.end())
                tails.push_back(i);
            else
                *iter = i;
        }
        
        return tails.size();
    }
};
