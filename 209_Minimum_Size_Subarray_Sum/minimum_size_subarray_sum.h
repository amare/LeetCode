/*
 Author:            cuckoo
 Date:              2017/05/07 15:18:07
 Update:            
 Problem:           Minimum Size Subarray Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/minimum-size-subarray-sum/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        return minSubArrayLenSecond(s, nums);
    }
    
    int minSubArrayLenFirst(int s, vector<int>& nums)
    {
        int min_length = INT_MAX, n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            for(int j = i; j < n; ++j)
            {
                sum += nums[j];
                if(sum >= s)
                {
                    min_length = std::min(min_length, j + 1 - i);
                    break;
                }
            }
        }
        
        return min_length == INT_MAX ? 0 : min_length;
    }
    
    int minSubArrayLenSecond(int s, vector<int>& nums)
    {
        int n = nums.size();
        int min_length = n + 1;
        
        int from = 0, to = 0, sum = 0;
        for(int to = 0; to < n; ++to)
        {
            sum += nums[to];
            while(sum >= s)
            {
                min_length = std::min(min_length, to + 1 - from);
                sum -= nums[from++];
            }
        }
        
        return min_length == n + 1 ? 0 : min_length;
        
    }

    // Binary Search - O(nlgn)
    vector<int> accumulate(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for(int i = 1; i <= n; ++i)
            sums[i] = sums[i - 1] + nums[i - 1];
        
        return sums;
    }
    int upper_bound(vector<int> &sums, int low, int high, int target)
    {
        while(low < high)
        {
            int mid = low + ((high - low) >> 1);
            if(sums[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }
        
        return sums[high] > target ? high : -1;
    }
    
    int minSubArrayLenThird(int s, vector<int>& nums)
    {
        int n = nums.size();
        int min_length = n + 1;
        
        vector<int> sums = accumulate(nums);
        for(int i = 1; i <= n; ++i)
        {
            if(sums[i] >= s)
            {
                int key = upper_bound(sums, 0, i, sums[i] - s);
                if(key != -1)
                    min_length = std::min(min_length, i + 1 - key);
            }
        }
        
        
        return min_length == n + 1 ? 0 : min_length;
    }
};
