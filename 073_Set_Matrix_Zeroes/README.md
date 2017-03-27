
    Author:            cuckoo
    Date:              2017/03/27 10:53:13
    Update:            
    Problem:           Set Matrix Zeroes
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/set-matrix-zeroes/#/description

__Solution Step__:
 - For every element, check if the element has been accessed
 - if not, and its' value is zero, to next step
 - keep the element which is zero originally un-accessed state and set the element
 which is not zero to zero

======
 - [using the last zero row to control](https://discuss.leetcode.com/topic/7087/my-c-o-1-yoooooo)
 - [other](https://discuss.leetcode.com/topic/50145/in-place-solution-using-constant-space-in-c-best-submission)
