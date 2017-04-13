/*
 Author:            cuckoo
 Date:              2017/04/13 22:31:46
 Update:            
 Problem:           Copy List with Random Pointer
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/copy-list-with-random-pointer/#/description

 */

#include <cstddef>      // for NULL

#include <unordered_map>
using std::unordered_map;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList1(head);
    }
    
    RandomListNode *copyRandomList1(RandomListNode *head)
    {
        if(head == NULL)
            return NULL;
            
        RandomListNode *copy_head = new RandomListNode(head->label);
        
        unordered_map<RandomListNode *, RandomListNode *> hash;
        hash.insert({head, copy_head});
        
        RandomListNode *current = head->next, *copy_previous = copy_head;
        while(current != NULL)
        {
            RandomListNode *new_node = new RandomListNode(current->label);
            copy_previous->next = new_node;
            copy_previous = new_node;
            hash.insert({current, new_node});
            
            current = current->next;
        }
        
        current = head;
        while(current != NULL)
        {
            hash[current]->random = hash[current->random];
            current = current->next;
        }
        
        return copy_head;
    }
};
