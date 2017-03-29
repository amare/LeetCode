/*
 Author:            cuckoo
 Date:              2017/03/29 10:17:03
 Update:            
 Problem:           Merge Sorted Array
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/merge-sorted-array/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        return merge_1(nums1, m, nums2, n);
    }
    
    void merge_1(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // nums1.resize(m + n);
        int tail = m + n - 1, index1 = m - 1, index2 = n - 1;
        while(index1 >= 0 && index2 >= 0)
            nums1[tail--] = nums1[index1] <= nums2[index2] ? nums2[index2--] : nums1[index1--];
        // if nums2 is longer than nums1 just copy the rest of nums2 to nums1 location
        while(index2 >= 0)
            nums1[tail--] = nums2[index2--];
        // nums1.resize(m);
    }
};
