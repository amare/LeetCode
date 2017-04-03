
    Author:            cuckoo
    Date:              2017/04/03 14:37:23
    Update:            
    Problem:           Swap Nodes in Pairs
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/swap-nodes-in-pairs/#/description

__Solution Step__:
```
            1    ->     2    ->     3
            ↑           ↑
    previous_node   current_node


             -----------
            ↓           ↑
            1    ->     2           3           ListNode *next_node = current_node->next;
            ↑           ↑           ↑           current_node->next = previous_node;
    previous_node   current_node   next_node


             -----------
            ↓           ↑                       previous_node->next = next_node == NULL ?
            1           2           3                                              NULL : 
            ↓                       ↑                                              swap(next_node, next_node->next);
             -----------------------
```

======
 - [iterative](https://discuss.leetcode.com/topic/18860/7-8-lines-c-python-ruby)
 - brilliant but modify the values in the list
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* root = head;
        while(root && root->next) {
            swap(root->val, root->next->val);
            root = root->next->next;
        }
        return head;
    }
};
```
 - other recursion
```
public class Solution {
    public ListNode swapPairs(ListNode head) {
       
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode result = swapPairs(head.next.next);
        
        ListNode temp = head.next;
        head.next = result;
        temp.next = head;
        return temp;
        
    }
}
```
