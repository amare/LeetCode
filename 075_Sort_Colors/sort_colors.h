/*
 Author:            cuckoo
 Date:              2017/03/27 15:54:39
 Update:            
 Problem:           Sort Colors
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/sort-colors/#/description

 */

#include <vector>
using std::vector;

#include <iostream>     // for std::swap()

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sortColors_3(nums);
    }
    
    void MyQsort(vector<int> &nums, int start, int end)
    {
        if(start >= end)
            return;

        int pivot = nums[start];
        int i = start, j = end;
        while(i < j)
        {
            while(i < j && nums[j] > pivot) --j;
            std::swap(nums[i], nums[j]);
            while(i < j && nums[i] <= pivot) ++i;
            std::swap(nums[i], nums[j]);
        }
        MyQsort(nums, start, i - 1);
        MyQsort(nums, i + 1, end);
    }
    
    void sortColors_1(vector<int> &nums)
    {
        int size = nums.size();
        MyQsort(nums, 0, size - 1);
    }
    
    void sortColors_2(vector<int> &nums)
    {
        int zero = 0, two = nums.size() - 1;
        for(int i = 0; i <= two; ++i)
        {
            while(nums[i] == 0 && i > zero) std::swap(nums[i], nums[zero++]);
            while(nums[i] == 2 && i < two) std::swap(nums[i], nums[two--]);
        }
    }
    
    void sortColors_3(vector<int> &nums)
    {
        int low = 0, k = 0, high = nums.size() - 1;
        while(k <= high)
        {
            if(nums[k] < 1) std::swap(nums[low++], nums[k++]);
            else if(nums[k] > 1) std::swap(nums[high--], nums[k]);
            else ++k;
        }
    }
};
