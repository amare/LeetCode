
    Author:            cuckoo
    Date:              2017/04/01 21:10:28
    Update:            
    Problem:           Best Time to Buy and Sell Stock
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description

__Solution__:
 - `buy_day` the day when we buy stock produces current max profit
 - loop
 - calcute current profit and update `max_profit`, and if current price is lower than buy_day, update it
 - until the last day

=====
 - [Kadane's Algorithm](https://discuss.leetcode.com/topic/19853/kadane-s-algorithm-since-no-one-has-mentioned-about-this-so-far-in-case-if-interviewer-twists-the-input)
 - [another general method](https://discuss.leetcode.com/topic/5863/sharing-my-simple-and-clear-c-solution)
 - [Dynamic Programming](https://discuss.leetcode.com/topic/24281/why-is-this-problem-tagged-with-dynamic-programming/3)
