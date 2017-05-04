/*
 Author:            cuckoo
 Date:              2017/05/04 21:53:40
 Update:            
 Problem:           Add Two Numbers II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/add-two-numbers-ii/#/description

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersSecond(l1, l2);
    }
    
    /*
    ListNode* addTwoNumbersFirst(ListNode* l1, ListNode* l2)
    {
        ListNode *l1_current = l1, *l2_current = l2;
        int l1_length = 0, l2_length = 0;
        while(l1_current != NULL)
        {
            ++l1_length;
            l1_current = l1_current->next;
        }
        while(l2_current != NULL)
        {
            ++l2_length;
            l2_current = l2_current->next;
        }
        
        if(l2_length > l1_length)
            swap(l1, l2);
            
        l1_current = l1, l2_current = l2;
        int difference = std::abs(l2_length - l1_length);
        while(difference--)
        {
            l1_current = l1_current->next;
        }
            
            
        // 相加，并把各个进位存到一个新的链表中
        // 将结果与进位链表相加，得到新的结果链表和进位链表
        // 直到进位链表为空
      
        
        if(l2_length > l1_length)
            swap(l1, l2);
    }
    */
    
    ListNode * ReverseList(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *current = head, *previous = NULL;
        while(current != NULL)
        {
            ListNode *temp_next = current->next;
            current->next = previous;
            previous = current;
            current = temp_next;
        }
        
        return previous;
    }
    ListNode* addTwoNumbersSecond(ListNode* l1, ListNode* l2)
    {
        ListNode *new_l1 = ReverseList(l1), *new_l2 = ReverseList(l2);
        
        ListNode dummy(0);
        ListNode *current = &dummy;
        int carry = 0;
        
        ListNode *l1_current = new_l1, *l2_current = new_l2;
        while(l1_current != NULL || l2_current != NULL)
        {
            int a = l1_current == NULL ? 0 : l1_current->val;
            int b = l2_current == NULL ? 0 : l2_current->val;
            
            int sum = a + b + carry;
            carry = sum / 10;
            current = current->next = new ListNode(sum % 10);
            
            if(l1_current != NULL)
                l1_current = l1_current->next;
            if(l2_current != NULL)
                l2_current = l2_current->next;
        }
        
        if(carry == 1)
            current->next = new ListNode(1);
            
        l1 = ReverseList(new_l1), l2 = ReverseList(new_l2);
            
        return ReverseList(dummy.next);
        
    }
};
