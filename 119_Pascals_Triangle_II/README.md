
    Author:            cuckoo
    Date:              2017/04/25 21:40:38
    Update:            
    Problem:           Pascal's Triangle II
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/pascals-triangle-ii/#/description

#### Solution Step
 - [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/#/description)

#### Discuss
 - [Concise](https://discuss.leetcode.com/topic/2510/here-is-my-brief-o-k-solution)
```
    assume rowIndex is equal to 4

    i = 0    [1, 0, 0, 0, 0, 0, 0]       A[0] = 1

    i = 1    [1, 1, 0, 0, 0, 0, 0]       A[1] = pre_A[1] + pre_A[0]

    i = 2    [1, 1, 1, 0, 0, 0, 0]       A[2] = pre_A[2] + pre_A[1]
             [1, 2, 1, 0, 0, 0, 0]       A[1] = pre_A[1] + pre_A[0]

    i = 3    [1, 2, 1, 1, 0, 0, 0]       A[3] = pre_A[3] + pre_A[2]
             [1, 2, 3, 1, 0, 0, 0]       A[2] = pre_A[2] + pre_A[1]
             [1, 3, 3, 1, 0, 0, 0]       A[1] = pre_A[1] + pre_A[0]
```
