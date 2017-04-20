/*
 Author:            cuckoo
 Date:              2017/04/20 17:05:19
 Update:            
 Problem:           Search Insert Position
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/search-insert-position/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsert1(nums, target);
    }
    
    int searchInsert1(vector<int>& nums, int target)
    {
        int head = 0, tail = nums.size() - 1;
        while(head <= tail)
        {
            int mid = head + (tail - head) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                head = mid + 1;
            else
                tail = mid - 1;
        }
        
        return head;
    }
};
