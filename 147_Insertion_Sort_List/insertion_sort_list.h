/*
 Author:            cuckoo
 Date:              2017/05/10 20:17:45
 Update:            
 Problem:           Insertion Sort List
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/insertion-sort-list/#/description

 */

#include <cstddef>          // for NULL
#include <climits>          // for INT_MIN

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        return insertionSortListFirst(head);
    }
    
    ListNode* insertionSortListFirst(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        
        ListNode dummy(INT_MIN);
        
        ListNode *previous = &dummy, *sorted_current = head, *current = head->next;;
        previous->next = sorted_current;
        sorted_current->next = NULL;
        
        while(current != NULL)
        {
            previous = &dummy, sorted_current = previous->next;
            while(sorted_current && sorted_current->val <= current->val)
            {
                previous = sorted_current;
                sorted_current = sorted_current->next;
            }
            previous->next = current;
            current = current->next;
            previous->next->next = sorted_current;
        }
        
        return dummy.next;
    }
};
