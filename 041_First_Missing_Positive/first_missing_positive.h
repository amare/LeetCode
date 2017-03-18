/*
 Author:            cuckoo
 Date:              2017/03/17 21:39:08
 Update:
 Problem:           First Missing Positive
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/first-missing-positive

 */

#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        return firstMissingPositive_1(nums);
    }

    //  O(n) extra space
    int firstMissingPositive_1(vector<int>& nums)
    {
        int size = nums.size();
        vector<bool> exist_flag(size + 2, false);
        for(auto i : nums)
        {
            if(i > 0)
                exist_flag[i] = true;
        }
        for(int i = 1; i < size + 2; ++i)
        {
            if(!exist_flag[i])
                return i;
        }

        return 1;
    }

    // swap each positive integer you encounter to its "rightful" place at index (x-1)
    // where x is the integer
    int firstMissingPositive_2(vector<int>& nums)
    {
        int size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            // ^think: what is the condition of the end of while loop
            while(nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])   // ^core code
                std::swap(nums[i], nums[nums[i] - 1]);
        }

        for(int i = 0; i < size; ++i)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }

        return size + 1;
    }
};
