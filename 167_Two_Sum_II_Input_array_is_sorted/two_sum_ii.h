/*
 Author:            cuckoo
 Date:              2017/04/20 15:11:21
 Update:            
 Problem:           Two Sum II - Input array is sorted
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        return twoSum1(numbers, target);
    }
    
    vector<int> twoSum1(vector<int>& numbers, int target)
    {
        if(numbers.empty()) return {};
        
        int head = 0, tail = numbers.size() - 1;
        while(head < tail)
        {
            int sum = numbers[head] + numbers[tail];
            if(sum > target)
                --tail;
            else if(sum < target)
                ++head;
            else
            {
                return {head + 1, tail + 1};
            }
        }
        return {};
    }
};
