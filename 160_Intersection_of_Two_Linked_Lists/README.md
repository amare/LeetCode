
    Author:            cuckoo
    Date:              2017/04/27 16:20:42
    Update:            
    Problem:           Intersection of Two Linked Lists
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/intersection-of-two-linked-lists/#/description

#### Solution Step
 - 剑指Offer 面试题37
 - [More Concise](https://discuss.leetcode.com/topic/16574/concise-48ms-c-solution-with-description-and-comment-on-trees)

#### Discuss
 - [Without knowing the difference in len](https://discuss.leetcode.com/topic/5527/my-accepted-simple-and-shortest-c-code-with-comments-explaining-the-algorithm-any-comments-or-improvements)
```
    L1: length of list 1, L1_H: length of list 1 before intersection node
    L2: length of list 2, L2_H: length of list 2 before intersection node

    |-- L1_H --|
    A - > B -> C
                 \
                  F -> G
                 /
          D -> E
          |L2_H|

    L = L1 - L2
    L1 + L2_H == L1 + L1_H - L
              == L1 - L + L1_H
              == L2 + L1_H
```

#### Editorial Solution
 - [Three Method](https://leetcode.com/articles/intersection-two-linked-lists/)
