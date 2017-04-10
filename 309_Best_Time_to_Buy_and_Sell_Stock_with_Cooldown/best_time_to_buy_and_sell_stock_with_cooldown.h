/*
 Author:            cuckoo
 Date:              2017/04/10 21:40:29
 Update:            
 Problem:           Best Time to Buy and Sell Stock with Cooldown
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/#/description

 */

#include <vector>
using std::vector;

#include <cmath>        // for max()

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit_1(prices);
    }
    
    int maxProfit_1(vector<int>& prices)
    {
        int size = prices.size();
        if(0 == size || 1 == size) return 0;
        
        // buy[i]: Max profit till index i. The series of transaction is ending with a buy.
        // sell[i]: Max profit till index i. The series of transaction is ending with a sell.
        vector<int> buy(size, 0);
        vector<int> sell(size, 0);
        buy[0] = -prices[0], buy[1] = std::max(buy[0], -prices[1]);
        sell[0] = 0, sell[1] = std::max(sell[0], buy[0] + prices[1]);
        for(int i = 2; i < size; ++i)
        {
            buy[i] = std::max(buy[i-1], sell[i-2] - prices[i]);
            sell[i] = std::max(sell[i-1], buy[i-1] + prices[i]);
        }
        
        return sell[size-1];
    }
};
