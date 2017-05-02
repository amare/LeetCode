/*
 Author:            cuckoo
 Date:              2017/04/27 15:44:06
 Update:            
 Problem:           Reorder List
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/reorder-list/#/description

 */

#include <cstddef>          // for NULL

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        return reorderListFirst(head);
    }
    
    void reorderListFirst(ListNode* head)
    {
        if(head == NULL) return;
        
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // split to two lists and reverse the second list
        ListNode *current = slow->next, *prev = NULL;
        slow->next = NULL;
        while(current != NULL)
        {
            ListNode *temp = current->next;
            current->next = prev;
            
            prev = current;
            current = temp;
        }
        
        ListNode *head2 = prev;
        
        // merge two lists
        ListNode *first_current = head, *second_current = head2;
        while(second_current != NULL)       // length of list 1 is larger than or equal to list2's.
        {
            ListNode *second_next = second_current->next;
            second_current->next = first_current->next;
            first_current->next = second_current;
            
            first_current = second_current->next;
            second_current = second_next;
        }
    }
};
