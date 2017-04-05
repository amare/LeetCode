/*
 Author:            cuckoo
 Date:              2017/04/05 21:25:53
 Update:            
 Problem:           Linked List Cycle II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/linked-list-cycle-ii/#/description

 */

#include <cstddef>      // for NULL

#include <unordered_set>
using std::unordered_set;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return detectCycle_1(head);
    }
    
    ListNode *detectCycle_1(ListNode *head)
    {
        if(head == NULL || head->next == NULL) return NULL;
        unordered_set<ListNode *> hash;
        ListNode *current = head;
        while(current != NULL)
        {
            if(hash.find(current) != hash.end())
                return current;
            hash.insert(current);
            current = current->next;
        }
        
        return NULL;
    }

    ListNode *detectCycle_2(ListNode *head)
    {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head, *entry = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                while(entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        
        return NULL;
    }
};
