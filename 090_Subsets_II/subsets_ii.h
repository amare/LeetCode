/*
 Author:            cuckoo
 Date:              2017/04/06 22:03:13
 Update:            
 Problem:           Subsets II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/subsets-ii/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>        // for sort()

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        return subsetsWithDup_2(nums);
    }
    
    void subsetsWithDupAux(vector<int> &nums, vector<vector<int>> &result, vector<int> &single, int start, int end)
    {
        result.push_back(single);
        
        for(int i = start; i < end; ++i)
        {
            if(i > start && nums[i] == nums[i-1]) continue;
            single.push_back(nums[i]);
            subsetsWithDupAux(nums, result, single, i + 1, end);
            single.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup_1(vector<int>& nums)
    {
        int size = nums.size();
        if(0 == size) return vector<vector<int>>(1, vector<int>());
        vector<vector<int>> result;
        vector<int> single;
        sort(nums.begin(), nums.end());
        subsetsWithDupAux(nums, result, single, 0, size);
        
        return result;
    }
    
    
    vector<vector<int> > subsetsWithDup_2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret = {{}};
        int size = 0, startIndex = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            startIndex = (i >= 1 && nums[i] == nums[i - 1]) ? size : 0;
            size = ret.size();
            for(int j = startIndex; j < size; j++)
            {
                vector<int> temp = ret[j];
                temp.push_back(nums[i]);
                ret.push_back(temp);
            }
        }
        
        return ret;
    }
};
