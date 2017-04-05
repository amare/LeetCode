/*
 Author:            cuckoo
 Date:              2017/04/05 20:08:44
 Update:            
 Problem:           Reverse Linked List II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/reverse-linked-list-ii/#/description

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        return reverseBetween_2(head, m, n);
    }
    
    ListNode* reverseBetween_1(ListNode* head, int m, int n)
    {
        if(head == NULL || head->next == NULL || m >= n) return head;
        /*  handle with m < 0 || n > length of list
         *  if(m < 1) m = 1;
         *  int count = 0;
         *  ListNode *current_count = head;
         *  while(current_count != NULL)
         *  {
         *      ++count;
         *      current_count = current_count->next;
         *  }
         *  if(n > count) n = count;
        */
        
        int length = n - m;
        
        ListNode *current = head;
        ListNode *m_node_previous = NULL;
        while(current != NULL && --m)
        {
            m_node_previous = current;
            current = current->next;
        }
        
        ListNode *m_node = current;
        
        ListNode *previous = m_node_previous;
        while(current != NULL && length--)
        {
            ListNode *next_node = current->next;
            current->next = previous;
            previous = current;
            current = next_node;
        }
        
        m_node->next = current->next;
        current->next = previous;
        if(m_node_previous == NULL)
            return current;
        else
        {
            m_node_previous->next = current;
            return head;
        }
    }
    
    // using a dummy node
    ListNode* reverseBetween_2(ListNode* head, int m, int n)
    {
        if(head == NULL || head->next == NULL || m >= n) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *previous = &dummy;

        for(int i = 0; i < m - 1; ++i)
            previous = previous->next;
        ListNode *pivot = previous->next;
        ListNode *current = pivot->next;
        for(int i = 0; i < n - m; ++i)
        {
            pivot->next = current->next;
            current->next = previous->next;
            previous->next = current;
            current = pivot->next;
        }
        
        return dummy.next;
    }
};
