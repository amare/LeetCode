/*
 Author:            cuckoo
 Date:              2017/03/11 19:54:00
 Update:
 Problem:           Merge Two Sorted Lists
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/merge-two-sorted-lists

 */

#include <cstddef>  // for NULL

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return mergeTwoLists_1(l1, l2);
    }

    ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2)
    {
        ListNode *l1_cur = l1, *l2_cur = l2;
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while(l1_cur != NULL && l2_cur != NULL)
        {
            if(l1_cur->val <= l2_cur->val)
            {
                tail->next = l1_cur;
                tail = tail->next;
                l1_cur = l1_cur->next;
            }
            else
            {
                tail->next = l2_cur;
                tail = tail->next;
                l2_cur = l2_cur->next;
            }
        }


        if(NULL == l1_cur)
            tail->next = l2_cur;
        else if(NULL == l2_cur)
            tail->next = l1_cur;
        else
            return NULL;

        return head->next;
    }
};
