
    Author:            cuckoo
    Date:              2017/04/12 20:03:43
    Update:            
    Problem:           Balanced Binary Tree
    Difficulty:        Easy
    Source:            https://leetcode.com/problems/balanced-binary-tree/#/description

#### Solution Step
 - left_subtree is balanced and right_subtree is balanced
 - obtain [Maximum Depths of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description) of the left_subtree and the right_subtree
 - make sure the depth of the two subtrees never differ by more than 1

#### Discuss
 - [Better Solution](https://discuss.leetcode.com/topic/7798/the-bottom-up-o-n-solution-would-be-better) - `Time Complexity O(n)`
 - [Extended Read](https://discuss.leetcode.com/topic/276/two-different-definitions-of-balanced-binary-tree-result-in-two-different-judgments)
