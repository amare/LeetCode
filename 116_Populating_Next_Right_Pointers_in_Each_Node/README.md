
    Author:            cuckoo
    Date:              2017/04/01 17:33:39
    Update:            
    Problem:           Populating Next Right Pointers in Each Node
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/populating-next-right-pointers-in-each-node/#/description

__Solution Step__:
 - using a `stack` to implement a level traversal, not constant extra space

======
 - [using link information of current level to link the next level](https://discuss.leetcode.com/topic/2202/a-simple-accepted-solution)
```
         1 -> NULL
       /  \
      2 -> 3 -> NULL    when current_node->val == 2
     / \  / \
    4->5  6  7          current_node->left->next = current_node->right

         1 -> NULL
       /  \
      2 -> 3 -> NULL    if(current_node->next != NULL)
     / \  / \               current_node->right->next = current->next->left
    4->5->6  7

                        current_node = current_node->next;

         1 -> NULL
       /  \
      2 -> 3 -> NULL    when current_node->val == 3
     / \  / \
    4->5->6->7          current_node->left->next = current_node->right
```
 - [recurison version]

```
                 1
             /       \
         2      ->       3              connect(root)
      /     \         /     \
     4       5       6       7
   /  \    /  \    /  \    /  \
   8  9  10  11  12  13  14  15

                 1
             /       \
         2      ->       3              connect(root->left)
      /     \         /     \
     4  ->   5   ->  6       7
   /  \    /  \    /  \    /  \
   8  9  10  11  12  13  14  15

                 1
             /       \
         2      ->       3              connect(root->left->left)
      /     \         /     \
     4  ->   5  ->   6       7
   /  \    /  \    /  \    /  \
   8->9->10  11  12  13  14  15
```
