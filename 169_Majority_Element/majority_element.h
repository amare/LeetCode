/*
 Author:            cuckoo
 Date:              2017/04/04 11:26:58
 Update:            
 Problem:           Majority Element
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/majority-element/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for count()

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement_1(nums);
    }
    
    // Divide and Conquer
    int majority_element_aux(vector<int> &nums, int start, int last)
    {
        if(start >= last)
            return nums[start];
        int mid = start + (last - start) / 2;
        int left_majority_element = majority_element_aux(nums, start, mid);
        int right_majority_element = majority_element_aux(nums, mid + 1, last);
        if(left_majority_element == right_majority_element) return left_majority_element;
        return count(nums.begin() + start, nums.begin() + last + 1, left_majority_element) > 
            count(nums.begin() + start, nums.begin() + last + 1, right_majority_element) ?
            left_majority_element : right_majority_element;
    }
    
    int majorityElement_1(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 0) return INT_MIN;
        return majority_element_aux(nums, 0, size - 1);
    }

   // Boyer-Moore Majority Vote Algorithm
    int majorityElement_2(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 0) return INT_MIN;
        
        int major = nums[0], count = 1;
        for(int i = 1; i < size; ++i)
        {
            if(0 == count )
            {
                ++count;
                major = nums[i];
            }
                
            else if(major == nums[i])
                ++count;
            else
                --count;
        }
        
        return major;
    }
};
