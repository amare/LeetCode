/*
 Author:            cuckoo
 Date:              2017/04/13 09:25:04
 Update:            
 Problem:           Convert Sorted List to Binary Search Tree
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/#/description

 */

#include <cstddef>      // for NULL

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST_1(head);
    }
    
    ListNode * FindMiddleNode(ListNode *head)
    {
        ListNode *slow = head, *slow_previous = NULL, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow_previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow_previous;
    }
    
    TreeNode* sortedListToBST_1(ListNode* head)
    {
        if(head == NULL) 
            return NULL;
        /*
        if(head->next == NULL)
        {
            TreeNode *node = new TreeNode(head->val);
            node->left = NULL;
            node->right = NULL;
            return node;
        }
        */
        if(head->next == NULL)
            return new TreeNode(head->val);
        // head != NULL && head->next != NULL    
        ListNode *middle_node_prev = FindMiddleNode(head);      // middle_node_prev will never be NULL
        ListNode *current_node = middle_node_prev->next;        // current_node will also never be NULL
        middle_node_prev->next = NULL;                          // divided into two list
        
        TreeNode *root = new TreeNode(current_node->val);
        root->left = sortedListToBST_1(head);
        root->right = sortedListToBST_1(current_node->next);
        
        return root;
    }
};
