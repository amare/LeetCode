
    Author:            cuckoo
    Date:              2017/04/05 20:08:44
    Update:            
    Problem:           Reverse Linked List II
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/reverse-linked-list-ii/#/description

__Solution Step__:
 - find the mth node
 - reverse [m, n] node
 - link nth node to (m-1)th node
 - link (n+1)th node to mth node

======
 - [dummy node](https://discuss.leetcode.com/topic/8976/simple-java-solution-with-clear-explanation)
 - [Pointer pointer](https://discuss.leetcode.com/topic/45392/6-10-lines-in-c)
 - [recursive version](https://discuss.leetcode.com/topic/64610/why-nobody-does-it-with-recursion-shouldn-t-the-code-be-simpler)
