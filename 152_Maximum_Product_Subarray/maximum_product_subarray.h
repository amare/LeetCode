/*
 Author:            cuckoo
 Date:              2017/04/07 22:41:06
 Update:            
 Problem:           Maximum Product Subarray
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/maximum-product-subarray/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for max()

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return maxProduct_1(nums);
    }
    
    int maxProduct_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size)
            return 0;
            
        int result = nums[0];
        int max_current = nums[0];
        int min_current = nums[0];
        for(int i = 1; i < size; ++i)
        {
            if(nums[i] < 0)
                std::swap(max_current, min_current);
            
            max_current = std::max(max_current * nums[i], nums[i]);
            min_current = std::min(min_current * nums[i], nums[i]);
            
            result = std::max(result, max_current);
        }
        
        return result;
    }
};
