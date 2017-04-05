/*
 Author:            cuckoo
 Date:              2017/04/05 11:23:26
 Update:            
 Problem:           Rotate List 
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/rotate-list/#/description

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
    ListNode* rotateRight(ListNode* head, int k) {
        return rotateRight_1(head, k);
    }
    
    ListNode* rotateRight_1(ListNode* head, int k)
    {
        if(k <= 0 || head == NULL || head->next == NULL)
            return head;
        
        // handle with situation that k is bigger than length of list
        int length = 0;
        ListNode *temp = head;
        while(temp != NULL)
        {
            ++length;
            temp = temp->next;
        }
        k = k % length;
        
        // quick and slow pointer
        ListNode *first = head, *second = head;
        while(second != NULL && k--)
        {
            second = second->next;
        }
        
        while(second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        
        second->next = head;
        head = first->next;
        first->next = NULL;
        
        return head;
    }
};
