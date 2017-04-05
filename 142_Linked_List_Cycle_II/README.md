
    Author:            cuckoo
    Date:              2017/04/05 21:25:53
    Update:            
    Problem:           Linked List Cycle II
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/linked-list-cycle-ii/#/description

__Solution Step__:
 - hash table

======
 - [two pointer](https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description)

```
Step 1: Determine whether there is a cycle
    Using a slow pointer that move forward 1 step each time
    Using a fast pointer that move forward 2 steps each time
    If the slow pointer and fast pointer both point to the same location after several moving steps, there is a cycle;
    Otherwise, if (fast->next == NULL || fast->next->next == NULL), there has no cycle.

Step 2: If there is a cycle, return the entry location of the cycle
    L1 is defined as the distance between the head point and entry point
    L2 is defined as the distance between the entry point and the meeting point
    C is defined as the length of the cycle
    n is defined as the travel times of the fast pointer around the cycle When the first encounter of the slow pointer and the fast pointer

According to the definition of L1, L2 and C, we can obtain:
    the total distance of the slow pointer traveled when encounter is L1 + L2
    the total distance of the fast pointer traveled when encounter is L1 + L2 + n * C
    Because the total distance the fast pointer traveled is twice as the slow pointer, Thus:
    2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2)*

It can be concluded that the distance between the head location and entry location is equal to the 
distance between the meeting location and the entry location along the direction of forward movement.

So, when the slow pointer and the fast pointer encounter in the cycle, we can define a pointer 
"entry" that point to the head, this "entry" pointer moves one step each time so as the slow pointer.
 When this "entry" pointer and the slow pointer both point to the same location, this location is 
 the node where the cycle begins.
```
