/*
 Author:            cuckoo
 Date:              2017/04/01 21:10:28
 Update:            
 Problem:           Best Time to Buy and Sell Stock
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description

 */

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit_1(prices);
    }
    
    int maxProfit_1(vector<int>& prices)
    {
        int size = prices.size();
        int max_profit = 0, buy_day = 0;
        for(int i = 1; i < size; ++i)
        {
            max_profit = max(max_profit, prices[i] - prices[buy_day]);
            if(prices[i] < prices[buy_day])
                buy_day = i;
        }
        
        return max_profit;
    }
};
