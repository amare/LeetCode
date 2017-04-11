/*
 Author:            cuckoo
 Date:              2017/04/11 22:59:11
 Update:            
 Problem:           Largest Divisible Subset
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/largest-divisible-subset/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return largestDivisibleSubset_1(nums);   
    }
    
    vector<int> largestDivisibleSubset_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return {};
        
        sort(nums.begin(), nums.end());
        
        // dp[i]: the length of the largest divisible subset whose largest number is nums[i]
        // parent[i]: index of the previous number of the current number
        int largest_length = 0, largest_subset_last_index = 0;
        vector<int> dp(size, 0);
        vector<int> parent(size, 0);
        
        for(int i = 0; i < size; ++i)
        {
            for(int j = i; j >= 0; --j)
            {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > largest_length)
            {
                largest_length = dp[i];
                largest_subset_last_index = i;
            }
        }
        
        vector<int> result;
        for(int i = 0; i < largest_length; ++i)
        {
            result.insert(result.begin(), nums[largest_subset_last_index]);
            largest_subset_last_index = parent[largest_subset_last_index];
        }
        
        
        return result;
    }
};
