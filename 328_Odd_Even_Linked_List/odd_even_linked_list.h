/*
 Author:            cuckoo
 Date:              2017/05/04 20:52:24
 Update:            
 Problem:           Odd Even Linked List
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/odd-even-linked-list/#/description

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
    ListNode* oddEvenList(ListNode* head) {
        return oddEvenListFirst(head);
    }
    
    ListNode* oddEvenListFirst(ListNode* head)
    {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
            
        ListNode *odd = head, *even = head->next, *even_head = head->next;
        while(even != NULL && even->next != NULL)
        {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        
        odd->next = even_head;
        
        return head;
    }
};
