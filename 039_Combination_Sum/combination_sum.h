/*
 Author:            cuckoo
 Date:              2017/04/06 11:00:27
 Update:            
 Problem:           Combination Sum
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/combination-sum/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSum_1(candidates, target);
    }
    
    void CombinationSumAux(vector<int> &candidates, vector<vector<int>> &result, vector<int> &single, int start, int remain)
    {
        if(remain < 0) return;
        if(remain == 0)
        {
            result.push_back(single);
            return;
        }
        // remain > 0
        for(int i = start; i < candidates.size(); ++i)
        {
            single.push_back(candidates[i]);
            CombinationSumAux(candidates, result, single, i, remain - candidates[i]);
            single.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum_1(vector<int>& candidates, int target)
    {
        if(candidates.empty()) return {};
        vector<vector<int>> result;
        vector<int> single;
        // sort(candidates.begin(), candidates.end());
        CombinationSumAux(candidates, result, single, 0, target);
        
        return result;
    }
};
