/*
 Author:            cuckoo
 Date:              2017/04/09 16:10:41
 Update:            
 Problem:           Perfect Squares
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/perfect-squares/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for min()

#include <queue>
using std::queue;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int numSquares(int n) {
        return numSquares_2(n);
    }
    
    // DP
    int numSquares_1(int n)
    {
        if(n <= 0) return 0;
        
        // dp[n] represents the least number of perfect square numbers which sum to n
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1 * 1] + 1;
            for(int j = 2; i - j * j >= 0; ++j)
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
        
        return dp[n];
    }
    
    // BFS
    int numSquares_2(int n)
    {
        if(n <= 0) return 0;
        
        int depth = 0;
        queue<int> q;
        q.push(0);
        
        unordered_set<int> is_visited;      // it's not necessary, to avoid enqueueing of repeated element 
        is_visited.insert(0);
        while(!q.empty())
        {
            ++depth;
            int size = q.size();
            while(size--)
            {
                int sum = q.front();
                q.pop();
                for(int i = 1; sum + i * i <= n; ++i)
                {
                    int new_sum = sum + i * i;
                    if(new_sum == n)
                        return depth;
                    if(is_visited.find(new_sum) == is_visited.end())
                    {
                        is_visited.insert(new_sum);
                        q.push(new_sum);
                    }
                }   
            }
        }
        
        return depth;
    }
};
