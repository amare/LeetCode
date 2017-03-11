/*
 Author:            cuckoo
 Date:              2017/03/11 16:32:27
 Update:
 Problem:           Remove Nth Node From End of List
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/remove-nth-node-from-end-of-list

 */

#include <cstddef>  // for NULL

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEnd_1(head, n);
    }

    ListNode* removeNthFromEnd_1(ListNode* head, int n)
    {
        ListNode *advanced = head, *normal = head;
        // advanced points to the (n+1)th node from the start of list
        while(n--)
        {
            advanced = advanced->next;
        }
        // first node should to be removed
        if(NULL == advanced)
        {
            ListNode *new_head = normal->next;
            delete head;
            return new_head;
        }
        // normal points to the node followed by the node which should to be removed
        // when advanced points to the last node.
        while(advanced->next)
        {
            advanced = advanced->next;
            normal = normal->next;
        }
        ListNode *to_be_deleted = normal->next;
        normal->next = normal->next->next;
        delete to_be_deleted;

        return head;
    }
};

