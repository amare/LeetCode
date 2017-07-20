/*
 Author:            cuckoo
 Date:              2017/07/20 16:10:45
 Update:            
 Problem:           Majority Element II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/majority-element-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return MajorityElementFirst(nums);
    }
    
    vector<int> MajorityElementFirst(vector<int>& nums)
    {
        if(nums.empty())
            return {};
        
        // candidate1 and candidate2 are initialized to the same value?
        int candidate1 = nums[0], candidate2 = nums[0];
        int count1 = 0, count2 = 0;
        for(auto num : nums)
        {
            // attention the order of logic statement
            if(candidate1 == num)
                ++count1;
            else if(candidate2 == num)
                ++count2;
            else if(count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                --count1;
                --count2;
            }
        }
        
        vector<int> result;
        count1 = count2 = 0;
        for(auto num : nums)
        {
            if(num == candidate1)
                ++count1;
            else if(num == candidate2)
                ++count2;
        }
        
        if(count1 > nums.size() / 3)
            result.push_back(candidate1);
        if(count2 > nums.size() / 3)
            result.push_back(candidate2);
        
        return result;
    }
};
