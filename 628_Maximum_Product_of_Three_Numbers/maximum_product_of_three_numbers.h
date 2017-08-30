/*
 Author:            cuckoo
 Date:              2017/08/02 14:41:33
 Update:            
 Problem:           Maximum Product of Three Numbers
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/maximum-product-of-three-numbers/description/

 */

#include <vector>
using std::vector;

#include <limits>
using std::numeric_limits;

#include <algorithm>                // for std::max(), std::min()

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        return MaximumProductFirst(nums);
    }
    
    int MaximumProductFirst(vector<int> &nums)
    {
        long long min1 = numeric_limits<int>::max(), min2 = numeric_limits<int>::max();
        long long max1 = numeric_limits<int>::min(), max2 = numeric_limits<int>::min(), max3 = numeric_limits<int>::min();
        for(auto num : nums)
        {
            if(num <= min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if(num <= min2)
                min2 = num;

            if(num >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num >= max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if(num >= max3)
                max3 = num;
        }

        return std::max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
