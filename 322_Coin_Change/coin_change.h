/*
 Author:            cuckoo
 Date:              2017/04/09 22:48:21
 Update:            
 Problem:           Coin Change
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/coin-change/#/description

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
    int coinChange(vector<int>& coins, int amount) {
        return coinChange_2(coins, amount);
    }
    
    // DP, same as <279. Perfect Squares>
    int coinChange_1(vector<int>& coins, int amount)
    {
        if(amount <= 0) return 0;
        int size = coins.size();
        if(0 == size) return -1;
        
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                if(coins[j] <= 0 || coins[j] > i) continue;     // handle with negative and too large denominations
                int remain = i - coins[j];
                if(dp[remain] != -1)
                    dp[i] = std::min(dp[i], dp[remain] + 1);
            }
            if(dp[i] == INT_MAX)
                dp[i] = -1;
        }
        
        return dp[amount];
    }

    int coinChange_1_update(vector<int>& coins, int amount)
    {
        if(amount <= 0) return 0;
        int size = coins.size();
        if(0 == size) return -1;
        
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(auto denomination : coins)
            {
                if(denomination <= 0 || i < denomination) continue;
                if(dp[i - denomination] != -1)
                    dp[i] = dp[i] > 0 ? std::min(dp[i], dp[i - denomination] + 1) : dp[i - denomination] + 1;
            }
        }
        
        return dp[amount];
    }
    
    // BFS
    int coinChange_2(vector<int>& coins, int amount)
    {
        if(amount <= 0) return 0;
        
        int coins_size = coins.size();
        if(0 == coins_size) return -1;
        
        int length = 0;
        
        queue<int> q;
        q.push(0);
        
        unordered_set<int> is_visited;
        is_visited.insert(0);
        
        while(!q.empty())
        {
            ++length;
            int queue_size = q.size();
            while(queue_size--)
            {
                int sum = q.front();
                q.pop();
                for(int i = 0; i < coins_size; ++i)
                {
                    int new_sum = sum + coins[i];
                    if(new_sum > amount || new_sum <= sum)
                        continue;
                    if(new_sum == amount)
                        return length;
                    if(is_visited.find(new_sum) == is_visited.end())
                    {
                        is_visited.insert(new_sum);
                        q.push(new_sum);
                    }
                }
            }
        }
        
        return -1;
    }
};
