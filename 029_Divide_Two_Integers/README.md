    /*
     Author:            cuckoo
     Date:              2017/03/14 15:32:25
     Update:
     Problem:           Divide Two Integers
     Difficulty:        Medium
     Source:            https://leetcode.com/problems/divide-two-integers
     */

__解决思路__:

 - a / b = n  =>  $a = b\sum_{i=1}^n(1)$ (Time Limit Exceeded)

======
 - [移位操作符](https://discuss.leetcode.com/topic/38191/summary-of-3-c-solutions)

 - [移位without-long](https://discuss.leetcode.com/topic/23206/c-8ms-solution-without-long-long)

 - [log-based](https://discuss.leetcode.com/topic/11540/6-line-solution-c)
$$ a / b = e^{ln(a)} / e^{ln(b)} = e^ {ln(a)-ln(b)}$$

