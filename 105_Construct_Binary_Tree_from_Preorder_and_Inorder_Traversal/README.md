
    Author:            cuckoo
    Date:              2017/04/01 19:37:58
    Update:            
    Problem:           Construct Binary Tree from Preorder and Inorder Traversal
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description

__Solution Step__:
```
          root_pre_index  right-subtree_root_pre_index
                ↓           ↓
    preorder:   1   2   4   3   5   6   7   8   9
    inorder:   [2   4]  1  [6   5   8   7   9   3]
                ↑       ↑                       ↑
              start   root_in_index           last
```

======
 - [iterative](https://discuss.leetcode.com/topic/795/the-iterative-solution-is-easier-than-you-think) Need to be observed
