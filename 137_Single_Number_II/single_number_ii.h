/*
 Author:            cuckoo
 Date:              2017/05/18 08:36:28
 Update:            
 Problem:           Single Number II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/single-number-ii/#/description

 */

#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return singleNumberSecond(nums);
    }
    
    // using a map
    int singleNumberFirst(vector<int>& nums)
    {
        unordered_map<int, int> hash;
        for(auto num : nums)
        {
            if(hash.find(num) == hash.end())
                hash[num] = 1;
            else
                ++hash[num];
        }
        // find target in map
        for(auto &elem : hash)
            if(elem.second == 1)
                return elem.first;
                
        return -1;
    }
    
    // bit manipulation
    int singleNumberSecond(vector<int>& nums)
    {
        int ones = 0, twos = 0;
        for(auto num : nums)
        {
            ones = ~twos & (ones ^ num);
            twos = ~ones & (twos ^ num);
        }
        
        return ones;
    }

    // More easy understand
    int singleNumberThird(vector<int>& nums)
    {
        int result = 0;
        for(int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for(auto num : nums)
            {
                if((num >> i) & 1 == 1)
                {
                    ++sum;
                    
                }
            }
            sum %= 3;
            
            // sum is 0 or 1
            if(sum != 0)
                result |= sum << i;
        }
        
        return result;
    }
};
