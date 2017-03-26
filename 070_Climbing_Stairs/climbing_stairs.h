/*
 Author:            cuckoo
 Date:              2017/03/26 13:45:59
 Update:            
 Problem:           Climbing Stairs
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/climbing-stairs/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>    // for min()

class Solution {
public:
    int climbStairs(int n) {
        return climbStairs_2_recurison(n);
    }
    // backtracking - TLE
    void Jump(int index, int &result, int n)
    {
        if(index == n)
            result += 1;
        if(index > n)
            return;
        Jump(index + 1, result, n);
        Jump(index + 2, result, n);
    }
    int climbStairs_1(int n)
    {
        int result = 0;
        Jump(0, result, n);
        
        return result;
    }
    
    // DP: top-down
    // let memo[i]'s value be the count of distinct ways of climbing to the current star(say i) from zero star
    int climbStairs_2(int n)
    {
        vector<int> memo(n, 0);
        memo[0] = 1;
        memo[1] = 2;
        for(int i = 2; i < n; ++i)
            memo[i] = memo[i-1] + memo[i-2];
        
        return memo[n-1];
    }
    // DP: bottom-up
    // let memo[i]'s value be the count of distinct ways of climbing to the top from current star(say i)
    int climbStairs_3(int n)
    {
        vector<int> memo(n + 1, 0);
        memo[n] = 1;
        memo[n-1] = 1;
        for(int i = n - 2; i >= 0; --i)
            memo[i] = memo[i+1] + memo[i+2];
        
        return memo[0];
    }
    
    // DP: top-down - recurison version
    // let memo[i]'s value be the count of distinct ways of climbing to the current star(say i) from zero star
    vector<int> memo;
    int Jump(int position, int n)
    {
        if(memo[position] > 0)
            return memo[position];
        int furthest_jump = std::min(position + 2, n);
        for(int next_position = position + 1; next_position <= furthest_jump; ++next_position)
        {
            memo[position] += Jump(next_position, n);
        }
        return memo[position];
    }
    int climbStairs_2_recurison(int n)
    {
        memo.reserve(n + 1);
        for(int i = 0; i < n + 1; ++i)
            memo[i] = 0;
        memo[n] = 1;
        memo[n-1] = 1;
        
        return Jump(0, n);
    }
    
};
