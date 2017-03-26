
    Author:            cuckoo 
    Date:              2017/03/26 14:52:54
    Update:            
    Problem:           Sqrt(x)
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/sqrtx/#/description

__Solution Step__:
 - binary search

 >what is the difference between "mid > x / mid" and "mid * mid > x" ?

 >answer: mid*mid will overflow the integer if mid is large enough. see [more](https://discuss.leetcode.com/topic/8680/a-binary-search-solution)

=====
 - [Integer Newton](https://discuss.leetcode.com/topic/8689/newton-s-iterative-method-in-c)
 - [bit manipulation](https://discuss.leetcode.com/topic/2671/share-my-o-log-n-solution-using-bit-manipulation)
