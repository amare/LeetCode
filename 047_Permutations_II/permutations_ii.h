/*
 Author:            cuckoo
 Date:              2017/04/06 16:42:45
 Update:            
 Problem:           Permutations II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/permutations-ii/#/description

 */

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <algorithm>        // for sort()

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return permuteUnique_1(nums);
    }
    
    void permuteUniqueAux(vector<int> &nums, int start, int end, vector<vector<int>> &result)
    {
        if(start == end - 1)
        {
            result.push_back(nums);
            return;
        }
        unordered_set<int> hash;
        for(int i = start; i < end; ++i)
        {
            if(hash.find(nums[i]) == hash.end())
            {
                hash.insert(nums[i]);
                std::swap(nums[start], nums[i]);
                permuteUniqueAux(nums, start + 1, end, result);
                std::swap(nums[start], nums[i]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique_1(vector<int>& nums)
    {
        if(nums.empty()) return {};
        vector<vector<int>> result;
        // sort(nums.begin(), nums.end());
        permuteUniqueAux(nums, 0, nums.size(), result);
        
        return result;
    }

    // used flag
    void permuteUnique_2Aux(vector<int> &nums, vector<int> &single, vector<vector<int>> &result, vector<bool> &used, int length)
    {
        if(single.size() == length)
        {
            result.push_back(single);
            return;
        }
        for(int i = 0; i < length; ++i)
        {
            if(used[i] || i > 0 && !used[i-1] && nums[i] == nums[i-1]) continue;    // key code
            used[i] = true;
            single.push_back(nums[i]);
            permuteUnique_2Aux(nums, single, result, used, length);
            used[i] = false;
            single.pop_back();
        }
    }
    vector<vector<int>> permuteUnique_2(vector<int>& nums)
    {
        int length = nums.size();
        if(0 == length) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> single;
        vector<bool> used(length, false);
        permuteUnique_2Aux(nums, single, result, used, length);
       
        return result;
    }
};
