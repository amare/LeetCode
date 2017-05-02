/*
 Author:            cuckoo
 Date:              2017/04/27 16:20:42
 Update:            
 Problem:           Intersection of Two Linked Lists
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/intersection-of-two-linked-lists/#/description

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return getIntersectionNodeFirst(headA, headB);
    }
    
    ListNode *getIntersectionNodeFirst(ListNode *headA, ListNode *headB)
    {
        // calculate the length of two lists
        int length_a = 0, length_b = 0;
        ListNode *current_a = headA, *current_b = headB;
        while(current_a != NULL)
        {
            ++length_a;
            current_a = current_a->next;
        }
        while(current_b != NULL)
        {
            ++length_b;
            current_b = current_b->next;
        }
        
        // List with longer length takes difference steps forward
        current_a = headA;
        current_b = headB;
        int forward_step = length_a - length_b;
        if(forward_step > 0)
        {
            while(forward_step--)
                current_a = current_a->next;
        }
        else
        {
            forward_step = 0 - forward_step;
            while(forward_step--)
                current_b = current_b->next;
        }
        
        // find the intersection of two lists
        while(current_a != NULL && current_a->val != current_b->val)
        {
            current_a = current_a->next;
            current_b = current_b->next;
        }
        
        return current_a;
    }
};
