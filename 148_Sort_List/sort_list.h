/*
 Author:            cuckoo
 Date:              2017/05/08 22:17:24
 Update:            
 Problem:           Sort List
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/sort-list/#/description

 */

#include <cstddef>          // for NULL
#include <climits>          // for INT_MIN

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortListFirst(head);
    }
    
    int GetLength(ListNode *head)
    {
        int length = 0;
        ListNode *current = head;
        while(current != NULL)
        {
            current = current->next;
            ++length;
        }
        
        return length;
    }
    ListNode *MergeTwoSortedList(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(INT_MIN);
        dummy.next = l1;
        ListNode *current = &dummy;
        
        while(l2 != NULL)
        {
            while(current->next && current->next->val <= l2->val)
                current = current->next;
            l1 = current->next;
            current->next = l2;
            l2 = l1;
        }
        
        return dummy.next;
    }
    ListNode * MergeSort(ListNode *head)
    {
        int length = GetLength(head);
        if(length <= 1)
            return head;
            
        int mid = length / 2;
        
        ListNode *l1 = head, *current = head;
        while(--mid)
            current = current->next;
        ListNode *l2 = current->next;
        current->next = NULL;
        
        ListNode *sorted_l1 = MergeSort(l1);
        ListNode *sorted_l2 = MergeSort(l2);
        return MergeTwoSortedList(sorted_l1, sorted_l2);
    }
    ListNode* sortListFirst(ListNode* head)
    {
        return MergeSort(head);
    }
};
