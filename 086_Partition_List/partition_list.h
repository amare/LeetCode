/*
 Author:            cuckoo
 Date:              2017/04/05 16:43:30
 Update:            
 Problem:           Partition List
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/partition-list/#/description

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
    ListNode* partition(ListNode* head, int x) {
        return partition_1(head, x);
    }
    
    ListNode* partition_1(ListNode* head, int x)
    {
        ListNode node_less(0), node_larger(0);
        ListNode *p1 = &node_less, *p2 = &node_larger;
        while(head)
        {
            if(head->val < x)
                p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }
        
        p2->next = NULL;
        p1->next = node_larger.next;
        return node_less.next;
    }
};
