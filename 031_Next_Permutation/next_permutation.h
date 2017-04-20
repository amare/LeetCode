/*
 Author:            cuckoo
 Date:              2017/04/20 20:08:14
 Update:            
 Problem:           Next Permutation
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/next-permutation/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for reverse(), swap()

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        nextPermutation1(nums);
    }
    
    void nextPermutation1(vector<int>& nums)
    {
        int n = nums.size();
        // find the largest index k such that nums[k] < nums[k+1]
        int k = n - 1;
        for(; k > 0; --k)
            if(nums[k-1] < nums[k])
                break;
        
        // if no such index exists, the permutation is sorted in descending order, just reverse it to ascending order 
        if(k == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        // if exists
        if(k > 0)
        {
            // find the largest index l greater than k such that nums[k] < nums[l]
            int l = n - 1;
            for(; l > 0; --l)
                if(nums[l] > nums[k-1])
                    break;
            // swap the value of nums[k] with that of nums[i]
            std::swap(nums[k-1], nums[l]);
            // reverse the sequence from nums[k+1] up to and including the final element nums[nums.size() - 1]
            reverse(nums.begin() + k, nums.end());
            return;
        }
    }
};
