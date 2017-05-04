/*
 Author:            cuckoo
 Date:              2017/05/04 20:19:56
 Update:            
 Problem:           Delete Node in a Linked List
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/delete-node-in-a-linked-list/#/description

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
    void deleteNode(ListNode* node) {
        return deleteNodeFirst(node);
    }
    
    void deleteNodeFirst(ListNode* node)
    {
        if(node != NULL)
        {
            ListNode *next = node->next;
            *node = *next;
            delete next;
        }
    }
};
