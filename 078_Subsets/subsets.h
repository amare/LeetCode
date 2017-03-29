/*
 Author:            cuckoo
 Date:              2017/03/28 20:43:54
 Update:            
 Problem:           Subsets
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/subsets/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>    // for sort()
#include <cmath>        // for pow()

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets_1(nums);
    }
    
    void subsetsAux(vector<int> &nums, vector<vector<int>> &result, int index)
    {
        size_t size = nums.size();
        if(index >= size)
        {
            result.push_back(vector<int>());
            return;
        }
        
        subsetsAux(nums, result, index + 1);
        
        vector<vector<int>> result_temp(result);
        for(auto &v : result_temp)
        {
            vector<int> temp(v);
            temp.push_back(nums[index]);
            result.push_back(std::move(temp));
        }
    }
    
    vector<vector<int>> subsets_1(vector<int>& nums)
    {
        int size = nums.size();
        vector<vector<int>> result;
        
        long n = 1;
        while(size--) n <<= 1;
        result.reserve(n);
        
        subsetsAux(nums, result, 0);
        
        return result;
    }
    // time complexity: 2的n次幂
    vector<vector<int>> subsets_2(vector<int>& nums)
    {
        int size = nums.size();
        vector<vector<int>> result(1, vector<int>());
        
        long n = 1;
        while(size--) n <<= 1;
        result.reserve(n);
        
        size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            vector<vector<int>> result_temp(result);
            for(auto &v : result_temp)
            {
                vector<int> temp(v);
                temp.push_back(nums[i]);
                result.push_back(std::move(temp));
            }
            /* alternative way for 'range for'
            size_t n = result.size();
            for(int j = 0; j < n; ++j)
            {
                result.push_back(result[j]);
                result.pop_back().push_back(nums[i]);
            }
            */
        }
        
        return result;
    }

    vector<vector<int>> subsets_3(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int num_subset = std::pow(2, nums.size()); 
        vector<vector<int> > res(num_subset, vector<int>());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < num_subset; j++)
                if ((j >> i) & 1)   // key code
                    res[j].push_back(nums[i]);
        return res;  
    }
};
