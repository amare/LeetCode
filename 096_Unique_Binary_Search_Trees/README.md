
    Author:            cuckoo
    Date:              2017/04/03 16:29:32
    Update:            
    Problem:           Unique Binary Search Trees
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/unique-binary-search-trees/#/description

__Solution Step__:
 - [DP Solution](https://discuss.leetcode.com/topic/8398/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i)
 ```
    `G(n)`: the number of unique BST for a sequence of length n  
    `F(i, n)`, 1 <= i <= n: the number of unique BST, where the number i is the root of BST, 
    and the sequence ranges from 1 to n.

    G(n) = F(1, n) + F(2, n) + ... + F(n, n)    (1)
    F(i, n) = G(i-1) * G(n-i)   1 <= i <= n     (2)

    (1) + (2) = > G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)  
```
