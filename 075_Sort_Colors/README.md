
    Author:            cuckoo
    Date:              2017/03/27 15:54:39
    Update:            
    Problem:           Sort Colors
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/sort-colors/#/description

__Solution Step__:
 - qsort

======
 - `two pass` First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

 - `one pass`
    - [Dutch national flag problem](https://discuss.leetcode.com/topic/8696/c-solution-in-8-lines-an-instance-of-the-dutch-national-flag-problem-by-edsger-dijkstra)
    - [another valid method](https://discuss.leetcode.com/topic/3228/my-c-solution-with-one-pass-and-o-n-time-and-o-n-space)
