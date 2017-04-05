/*
 Author:            cuckoo
 Date:              2017/04/05 21:03:25
 Update:            
 Problem:           Linked List Cycle
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/linked-list-cycle/#/description

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
    bool hasCycle(ListNode *head) {
        return hasCycle_1(head);
    }
    
    bool hasCycle_1(ListNode *head)
    {
        if(head == NULL || head->next == NULL) return false;
        ListNode *fast = head->next, *slow = head;
        while(fast != slow)
        {
            if(fast == NULL || fast->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }

    bool hasCycle_2(ListNode *head)
    {
        if(head == NULL || head->next == NULL) return false;
        unordered_set<ListNode *> hash;
        while(head != NULL)
        {
            if(hash.find(head) != hash.end())
                return true;
            hash.insert(head);
            head = head->next;
        }
        
        return false;
    }
};
