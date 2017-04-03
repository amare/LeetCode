/*
 Author:            cuckoo
 Date:              2017/04/03 14:37:23
 Update:            
 Problem:           Swap Nodes in Pairs
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/swap-nodes-in-pairs/#/description

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
    ListNode* swapPairs(ListNode* head) {
        return swapPairs_1(head);
    }
    
    ListNode* swap(ListNode *previous_node, ListNode *current_node)
    {
        if(current_node == NULL) return previous_node;
        
        ListNode *next_node = current_node->next;
        current_node->next = previous_node;
        previous_node->next = next_node == NULL ? NULL : swap(next_node, next_node->next);
        
        return current_node;
    }
    
    ListNode* swapPairs_1(ListNode* head)
    {
        if(head == NULL) return NULL;
        return swap(head, head->next);
    }

    ListNode* swapPairs_2(ListNode* head)
    {
        ListNode **pp_head = &head, *current_node, *next_node;
        while((current_node = *pp_head) && (next_node = current_node->next))
        {
            current_node->next = next_node->next;
            next_node->next = current_node;
            *pp_head = next_node;
            pp_head = &(current_node->next);
        }
        
        return head;
    }
};
