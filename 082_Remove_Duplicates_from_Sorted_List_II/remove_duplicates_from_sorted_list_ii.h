/*
 Author:            cuckoo
 Date:              2017/04/05 10:08:44
 Update:            
 Problem:           Remove Duplicates from Sorted List II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description

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
    ListNode* deleteDuplicates(ListNode* head) {
        return deleteDuplicates_3(head);
    }
    
    ListNode* deleteDuplicates_1(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode *current = head;
        ListNode **pp_head = &head;
        while(current != NULL)
        {
            int value = current->val;
            if(current->next != NULL && current->next->val == value)
            {
                ListNode *temp = current;
                while(temp != NULL && temp->val == value)
                {
                    ListNode *temp_next = temp->next;
                    delete temp;
                    temp = NULL;
                    temp = temp_next;
                }
                current = temp;
                *pp_head = current;
            }
            else
            {
                pp_head = &(current->next);
                current = current->next;
            }
        }
        
        return head;
    }
    
    // 剑指offer
    ListNode* deleteDuplicates_2(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *previous = NULL;
        ListNode *current = head;
        
        while(current != NULL)
        {
            ListNode *next = current->next;
            bool need_delete = false;
            if(next != NULL && next->val == current->val)
                need_delete = true;
            
            if(!need_delete)
            {
                previous = current;
                current = next;
            }
            else
            {
                int value = current->val;
                ListNode *to_be_deleted = current;
                while(to_be_deleted != NULL && to_be_deleted->val == value)
                {
                    next = to_be_deleted->next;
                    delete to_be_deleted;
                    to_be_deleted = NULL;
                    to_be_deleted = next;
                }
                
                if(previous == NULL)
                {
                    head = next;
                }
                else
                {
                    previous->next = next;
                }
                current = next;
            }
        }
        
        return head;
    }
    
    // recursion version
    ListNode* deleteDuplicates_3(ListNode* head)
    {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        int value = head->val;
        ListNode *next = head->next;
        if(next->val != value)
        {
            head->next = deleteDuplicates_3(next);
            return head;
        }
        else
        {
            ListNode *temp = head;
            while(temp != NULL && temp->val == value)
            {
                ListNode *temp_next = temp->next;
                delete temp;
                temp = NULL;
                temp = temp_next;
            }
            return deleteDuplicates_3(temp);
        }
    }
};
