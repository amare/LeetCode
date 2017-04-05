/*
 Author:            cuckoo
 Date:              2017/04/05 17:16:58
 Update:            
 Problem:           Reverse Linked List
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/reverse-linked-list/#/description

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
    ListNode* reverseList(ListNode* head) {
        return reverseList_1_update(head);
    }
    
    ListNode* reverseList_1(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *new_head = reverseList_1(head->next);

        ListNode *temp = new_head;
        while(temp->next != NULL)
            temp = temp->next;
        head->next = NULL;
        temp->next = head;

        return new_head;
    }
    
    ListNode* reverseList_1_update(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *new_head = reverseList_1(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return new_head;
    }
    
    
    ListNode* reverseList_2(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *previous = NULL, *current = head;
        while(current != NULL)
        {
            ListNode *next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        return previous;
    }
};
