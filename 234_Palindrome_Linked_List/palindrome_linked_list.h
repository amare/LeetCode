/*
 Author:            cuckoo
 Date:              2017/04/27 22:15:00
 Update:            
 Problem:           Palindrome Linked List
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/palindrome-linked-list/#/description

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
    bool isPalindrome(ListNode* head) {
        return isPalindromeFirst(head);
    }
    
    bool isPalindromeFirst(ListNode* head)
    {
        if(head == NULL) return true;
        
        // reverse the left part    1 -> 2 -> 1 -> 2 -> 1  =>  1 <- 2 -> 1 -> 2 -> 1
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            
            ListNode *temp_next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp_next;
        }
        
        // judge if it is a palindrome and re-reverse the left part
        // 1 <- 2 -> 1 -> 2 -> 1  =>  1 <- 2 -> 1 -> 2 -> 1
        ListNode *right_head = slow->next, *left_head = NULL, *next = NULL;
        if(fast->next == NULL)
        {
            left_head = prev;
            next = slow;
        }
        else
        {
            left_head = slow;
            next = slow->next;
            slow->next = prev;
        }
        
        // 1 <- 2 -> 1 -> 2 -> 1  =>  1 -> 2 -> 1 -> 2 -> 1
        bool result = true;
        while(left_head != NULL)
        {
            if(left_head->val != right_head->val)
                result = false;
            
            ListNode *temp_next = left_head->next;
            left_head->next = next;
            next = left_head;
            left_head = temp_next;
            
            right_head = right_head->next;
        }
        
        return result;
    }

    bool check(ListNode *head, ListNode * &left)
    {
        if(head == NULL) return true;
        bool result = check(head->next, left) & (left->val == head->val);
        left = left->next;
        
        return result;
    }
    bool isPalindromeSecond(ListNode* head)
    {
        return check(head, head);
    }
};
