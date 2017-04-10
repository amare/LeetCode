
    Author:            cuckoo
    Date:              2017/04/10 20:20:22
    Update:            
    Problem:           Range Sum Query 2D - Immutable
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/range-sum-query-2d-immutable/#/description

__Solution Step__:

 - see [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/#/description)
 - sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1]

======
 - [Faster Solution](https://discuss.leetcode.com/topic/33841/very-clean-and-fast-java-solution)
