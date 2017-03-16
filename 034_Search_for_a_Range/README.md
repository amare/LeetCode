
    Author:            cuckoo
    Date:              2017/03/16 22:07:01
    Update:
    Problem:           Search for a Range
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/search-for-a-range

__解决思路__:
 - 找到第一个与目标值相同的索引
 - 找到最后一个与目标值相同的索引
 - 合并

=====
 - [improve the performance](https://discuss.leetcode.com/topic/5891/clean-iterative-solution-with-two-binary-searches-with-explanation/2)
>原来的代码在寻找最后一个索引时，重新遍历一遍，未能充分利用第一个索引结果

 - [lower_bound implementation](https://discuss.leetcode.com/topic/29643/c-binary-search-solution-lower_bound-implementation)

 - [Divide and Conquer](https://discuss.leetcode.com/topic/16486/9-11-lines-o-log-n)
