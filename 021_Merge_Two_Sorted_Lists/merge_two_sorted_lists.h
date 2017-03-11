/*
 Author:            cuckoo
 Date:              2017/03/11 19:54:00
 Update:            2017/03/11 20:23:26
 Problem:           Merge Two Sorted Lists
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/merge-two-sorted-lists

 */

#include <cstddef>  // for NULL
#include <climits>  // for INT_MIN
#include <algorithm>    // for swap()
using std::swap;

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
        ListNode head(INT_MIN);
        ListNode *tail = &head;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return head.next;
    }

    ListNode* mergeTwoLists_2(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists_2(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists_2(l2->next, l1);
            return l2;
        }
    }

    ListNode* mergeTwoLists_3(ListNode* l1, ListNode* l2)
    {
        if(!l1 || l2 && l1->val > l2->val) swap(l1, l2);
        if(l1) l1->next = mergeTwoLists_3(l1->next, l2);
        return l1;
    }

    ListNode* mergeTwoLists_4(ListNode* l1, ListNode* l2)
    {
        ListNode head(INT_MIN);
        head.next = l1;
        ListNode *cur = &head;

        while(l2)
        {
            while(cur->next && cur->next->val <= l2->val) cur = cur->next;
            l1 = cur->next;
            cur->next = l2;
            l2 = l1;
        }

        return head.next;
    }
};
