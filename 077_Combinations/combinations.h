/*
 Author:            cuckoo
 Date:              2017/04/06 21:00:20
 Update:            
 Problem:           Combinations
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/combinations/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return combine_1(n, k);
    }
    
    void combineAux(int n, int k, int start, vector<int> &single, vector<vector<int>> &result)
    {
        if(single.size() == k)
        {
            result.push_back(single);
            return;
        }
        for(int i = start; i <= n; ++i)
        {
            single.push_back(i);
            combineAux(n, k, i + 1, single, result);
            single.pop_back();
        }
        
    }
    vector<vector<int>> combine_1(int n, int k)
    {
        if(n < k) return {};
        int factorial1 = 1, factorial2 = 1;
        for(int i = n - k - 1; i <= n; ++i)
            factorial1 *= i;
        for(int i = 1; i <= k; ++i)
            factorial2 *= i;
        int count = factorial1 / factorial2;
        
        vector<vector<int>> result;
        result.reserve(count);
        vector<int> single;
        single.reserve(k);
        combineAux(n, k, 1, single, result);
        
        return result;
    }
};
