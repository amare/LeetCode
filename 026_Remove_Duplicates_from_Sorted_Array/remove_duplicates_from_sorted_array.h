/*
 Author:            cuckoo
 Date:              2017/03/11 22:35:59
 Update:
 Problem:           Remove Duplicates from Sorted Array
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/remove-duplicates-from-sorted-array

 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates_1(nums);
    }

    int removeDuplicates_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return 0;
        int new_size = -1;
        for(int i = 0; i < size - 1; ++i)
        {
            if(nums[i] != nums[i+1])
            {
                nums[++new_size] = nums[i];
            }
        }

        nums[++new_size] = nums[size - 1];

        return ++new_size;
    }
};
