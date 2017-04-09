
    Author:            cuckoo
    Date:              2017/04/08 11:32:17
    Update:            
    Problem:           Maximal Square
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/maximal-square/#/description

__Solution Step__:

 - `dp[row][col]` represent the max-area from coordinate [row,col] to lower-right-corner of the matrix 
 - `Space Complexity` can be reduced to O(n)

======
 - [More concise, using edge length](https://discuss.leetcode.com/topic/18482/accepted-clean-java-dp-solution)

 >dp[i][j] represent the edge length of the largest square ENDING at position (i, j)
