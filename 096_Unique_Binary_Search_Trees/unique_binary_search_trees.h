/*
 Author:            cuckoo
 Date:              2017/04/03 16:29:32
 Update:            
 Problem:           Unique Binary Search Trees
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/unique-binary-search-trees/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int numTrees(int n) {
        return numTrees_1(n);
    }
    
    int numTrees_1(int n)
    {
        if(n < 0) return 1;
        
        vector<int> nums(n+1);
        nums[0] = nums[1] = 1;
        for(int i = 2; i <= n; ++i)
            for(int j = 0; j < i; ++j)
                nums[i] += nums[j] * nums[i-1-j];

        return nums[n];
    }
};
