/*
 Author:            cuckoo
 Date:              2017/04/17 21:11:16
 Update:            
 Problem:           Combination Sum III
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/combination-sum-iii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum3_1(k, n);
    }
    
    void backtracking(vector<vector<int>> &all_combinations, vector<int> &combination, int sum, int k, int start, int target)
    {
        if(k == 0)
        {
            if(sum == target)
                all_combinations.push_back(combination);
            return;
        }
        for(int i = start; i <= 9 && sum + i * k <= target; ++i)
        {
            sum += i;
            combination.push_back(i);
            backtracking(all_combinations, combination, sum, k - 1, i + 1, target);
            combination.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3_1(int k, int n)
    {
        if(n < (k + 1) * k / 2 || n > k * (19 - k) / 2) return {};      // (1 + 2 + ... + k) <= n <= ((10 - k) + (11 - k) + ... + 9)
        vector<vector<int>> all_combinations;
        vector<int> combination;
        backtracking(all_combinations, combination, 0, k, 1, n);
        
        return all_combinations;
    }
};
