
    Author:            cuckoo
    Date:              2017/04/13 22:31:46
    Update:            
    Problem:           Copy List with Random Pointer
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/copy-list-with-random-pointer/#/description

#### Solution Step
 - using a unordered_map to map old node with copy node

#### Discuss
 - [More Concise](https://discuss.leetcode.com/topic/18086/java-o-n-solution)
 - &curren;[Constant Space And Linear Time](https://discuss.leetcode.com/topic/7594/a-solution-with-constant-space-complexity-o-1-and-linear-time-complexity-o-n)&curren;
 
 >1. Iterate the original list and duplicate each node. The duplicate
of each node follows its original immediately.
 >2. Iterate the new list and assign the random pointer for each
duplicated node.
 >3. Restore the original list and extract the duplicated nodes.
