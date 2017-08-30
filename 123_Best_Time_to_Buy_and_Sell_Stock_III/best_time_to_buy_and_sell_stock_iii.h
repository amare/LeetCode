/*
 Author:            cuckoo
 Date:              2017/08/03 10:25:40
 Update:            
 Problem:           Best Time to Buy and Sell Stock III
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

 */

#include <vector>
using std::vector;

#include <algorithm>            // for std::max()

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return MaxProfitFirst(prices);
    }
    
    // Dynamic Programming
    int MaxProfitFirst(vector<int>& prices)
    {
        if(prices.empty())
            return 0;
        
        // dp[k][i] represents the max profit up until prices[i] using at most k transaction. (Note: NOT ending with prices[i])
        // dp[k][i] = max(dp[k-1][i], prices[i] - prices[j] + dp[k-1][j]) {j is in range [0, i - 1]}
        //          = max(dp[k-1][i], prices[i] + max(dp[k-1][j] - prices[j]))
        // dp[0][i] = 0;    0 times transaction makes 0 profit
        // dp[k][0] = 0;    if there is only one price data point, you cann't make any money no matter how many times you can trade
        
        const int K = 2;
        vector<vector<int> > dp(K + 1, vector<int>(prices.size() , 0));
        for(int k = 1; k <= K; ++k)
        {
            int temp_max = dp[k-1][0] - prices[0];
            for(int i = 1; i < prices.size(); ++i)
            {
                dp[k][i] = std::max(dp[k][i-1], prices[i] + temp_max);
                temp_max = std::max(temp_max, dp[k-1][i] - prices[i]);
            }
        }
        
        return dp[K][prices.size() - 1];
    }
};
