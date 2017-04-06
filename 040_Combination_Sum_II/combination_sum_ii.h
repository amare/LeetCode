/*
 Author:            cuckoo
 Date:              2017/04/06 10:59:11
 Update:            
 Problem:           Combination Sum II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/combination-sum-ii/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>    // for sort()

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return combinationSum2_1(candidates, target);
    }
    
    void combinationSum2Aux(vector<int>& candidates, vector<vector<int>> &result, vector<int> &single, int start, int remain)
    {
        if(remain < 0) return;
        if(remain == 0)
        {
            result.push_back(single);
            return;
        }
        for(int i = start; i < candidates.size(); ++i)
        {
            if(i > start && candidates[i] == candidates[i-1])       // skip duplicates, candidates has been sorted
                continue;  
            single.push_back(candidates[i]);
            combinationSum2Aux(candidates, result, single, i + 1, remain - candidates[i]);
            single.pop_back();
        }
    }
    vector<vector<int>> combinationSum2_1(vector<int>& candidates, int target)
    {
        if(candidates.empty()) return {};
        vector<vector<int>> result;
        vector<int> single;
        sort(candidates.begin(), candidates.end());     // sort first
        combinationSum2Aux(candidates, result, single, 0, target);
        
        return result;
    }
};
