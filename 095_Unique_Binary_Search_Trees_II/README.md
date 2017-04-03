
    Author:            cuckoo
    Date:              2017/04/03 19:14:05
    Update:            
    Problem:           Unique Binary Search Trees II
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/unique-binary-search-trees-ii/#/description

__Solution Step__:
 - [DP solution](https://discuss.leetcode.com/topic/6711/share-a-c-dp-solution-with-o-1-space)

=====
 - [DP - top to bottom](https://discuss.leetcode.com/topic/17204/20ms-c-top-down-dp-solution)  

 >1.`dp_table[i-1][j-1]` represent all structurally unique BST's (binary search trees) that store values from i to j  
 2.Pick i-th node as root  
 3.The left subtree will contain elements 1 to (i-1)  
 4.And the right subtree will contain elements (i+1) to n
