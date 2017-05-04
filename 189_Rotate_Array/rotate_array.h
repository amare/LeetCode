/*
 Author:            cuckoo
 Date:              2017/05/03 19:00:30
 Update:            
 Problem:           Rotate Array
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/rotate-array/#/description

 */

#include <cstddef>          // for abs()

#include <algorithm>        // for reverse(), swap()

#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        return rotateFirst(nums, k);
    }
    
    // using extra space
    void rotateSecond(vector<int> &nums, int k)
    {
        int n = nums.size();
        if(k > n) k %= n;
        
        vector<int> clone(nums);
        int i = 0, j = n - k;
        while(j < n)
            nums[i++] = clone[j++];
        j = 0;
        while(i < n)
            nums[i++] = clone[j++];
    }
    
    // swap
    void rotateFirst(vector<int>& nums, int k)
    {
        int n = nums.size();
        if(k > n)
            k %= n;
        
        int count = 0;
        for(int start = 0; count < n; ++start)
        {
            int current = start;
            do
            {
                int next = (current + k) % n;
                std::swap(nums[next], nums[start]);
                current = next;
                ++count;
            }while(current != start);
        }
    }
    
    // reverse
    void rotateThird(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = std::abs(k);
        if(k > n) k %= n;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
