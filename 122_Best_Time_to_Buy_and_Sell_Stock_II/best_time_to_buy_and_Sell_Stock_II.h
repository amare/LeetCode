/*
 Author:            cuckoo
 Date:              2017/04/03 13:18:51
 Update:            
 Problem:           Best Time to Buy and Sell Stock II
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description

 */

#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit_1(prices);
    }
    
    int maxProfit_1(vector<int>& prices)
    {
        int size = prices.size();
        if(0 == size) return 0;
        int valley = prices[0], peak = prices[0];
        int max_profit = 0;
        for(int i = 0; i < size - 1; ++i)
        {
            while(i + 1 < size && prices[i] >= prices[i+1]) ++i;
            valley = prices[i];
            while(i + 1 < size && prices[i] <= prices[i+1]) ++i;
            peak = prices[i];
            max_profit += peak - valley;
        }
        
        return max_profit;
    }
};
