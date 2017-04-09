/*
 Author:            cuckoo
 Date:              2017/04/09 13:03:32
 Update:            
 Problem:           Range Sum Query - Immutable
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/range-sum-query-immutable/#/description

 */

#include <vector>
using std::vector;

class NumArray {
public:
    NumArray(vector<int> nums)
    {
        sums.resize(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); ++i)
        {
            sums[i] = sums[i-1] + nums[i-1]; 
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }

private:
    vector<int> sums;

};
