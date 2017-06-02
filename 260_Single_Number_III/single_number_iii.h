/*
 Author:            cuckoo
 Date:              2017/05/18 15:35:07
 Update:            
 Problem:           Single Number III
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/single-number-iii/#/description

 */

#include <vector>
using std::vector;

#include <numeric>        // for accumulate
#include <functional>       // for bit_xor

#include <limits>           // for numeric_limits

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        return singleNumberFirst(nums);
    }
    
    // a. sort and find
    // b. hash
    // c. bit manipulation
    vector<int> singleNumberFirst(vector<int>& nums)
    {
        vector<int> result(2, -1);
        
        int two_xor_result = 0;
        for(auto num : nums)
            two_xor_result ^= num;
        
        // the two single numbers are distinct, so there must be a different bit between them.
        // find the right-most bit which is set to 1 in two_xor_result
        int right_most_index = 0;
        for(int i = 0; i < 32; ++i)
        {
            if((two_xor_result >> i) & 1)
            {
                right_most_index = i;
                break;
            }
        }
        
        // divide the nums into two parts by right_most_index
        int single_xor_result = 0;
        for(auto num : nums)
            if((num >> right_most_index) & 1)
                single_xor_result ^= num;
        
        // a ^ b = c  =>  a = b ^ c;
        result[0] = single_xor_result;
        result[1] = single_xor_result ^ two_xor_result;
        
        return result;
    }

    // More concise
    vector<int> singleNumberSecond(vector<int>& nums)
    {
        // Get the XOR of the two numbers we need to find
        int two_xor_result = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        // get the last set bit
        int last_bit = two_xor_result & -two_xor_result;        // Corner Case: when two_xor_result == numeric_limits<int>::min()
        
        vector<int> result(2, 0);
        for(auto num : nums)
        {
            if((num & last_bit) == 0)       // the priority of '==' is higher than '&'
                result[0] ^= num;
            else
                result[1] ^= num;
        }

        return result;
    }
};
