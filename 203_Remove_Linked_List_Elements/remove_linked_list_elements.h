/*
 Author:            cuckoo
 Date:              2017/04/05 22:51:02
 Update:            
 Problem:           Remove Linked List Elements
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/remove-linked-list-elements/#/description

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
    ListNode* removeElements(ListNode* head, int val) {
        return removeElements_2(head, val);
    }
    
    ListNode* removeElements_1(ListNode* head, int val)
    {
        if(head == NULL) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *previous = &dummy;
        ListNode *current = head;
        while(current != NULL)
        {
            while(current != NULL && current->val == val)
            {
                ListNode *temp = current->next;
                delete current;
                current = NULL;
                current = temp;                
            }
            previous->next = current;
            previous = current;
            if(current != NULL)
                current = current->next;
        }
        
        return dummy.next;
    }

    ListNode* removeElements_2(ListNode* head, int val)
    {
        if(head == NULL) return NULL;
        head->next = removeElements_2(head->next, val);
        return head->val == val ? head->next : head;
    }

    // no dummy, more concise
    ListNode* removeElements_3(ListNode* head, int val)
    {
        if(head == NULL) return NULL;
        ListNode *node = head;
        while(node->next != NULL)
        {
            if(node->next->val == val)
            {
                /* memory leak
                method 1
                node->next = node->next->next;
                
                method 2
                swap(node->next, node->next->next);
                */
                ListNode *next_temp = node->next;
                delete node->next;
                node->next = NULL;
                node->next = next_temp->next;
            }
            else
                node = node->next;
        }
        
        return head->val == val ? head->next : head;
    }
    
    // Pointer pointer
    ListNode* removeElements_4(ListNode* head, int val)
    {
        if(head == NULL) return NULL;
        ListNode **pp_head = &head;
        while(*pp_head != NULL)
        {
            if((*pp_head)->val == val)
            {
                ListNode *temp = *pp_head;
                *pp_head = (*pp_head)->next;
                delete temp;
                temp = NULL;
            }
            else
                pp_head = &(*pp_head)->next;
        }
        
        return head;
    }
};
