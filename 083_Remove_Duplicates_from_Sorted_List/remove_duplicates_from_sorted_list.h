/*
 Author:            cuckoo
 Date:              2017/04/04 20:45:06
 Update:            
 Problem:           Remove Duplicates from Sorted List
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description

 */

#include <cstddef>      // for NULL

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode* deleteDuplicates_1(ListNode* head)
    {
        if(head == NULL) return NULL;
        ListNode *previous = head;
        ListNode *current = previous->next;
        while(current != NULL)
        {
            while(current != NULL && previous->val == current->val)
            {
                delete current;             // avoid memory leak
                current = current->next;
            }
            
            previous->next = current;
            if(current != NULL)
            {
                previous = current;
                current = current->next;
            }
        }
        
        return head;
    }
};
