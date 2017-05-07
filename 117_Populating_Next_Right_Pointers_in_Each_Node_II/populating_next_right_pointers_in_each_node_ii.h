/*
 Author:            cuckoo
 Date:              2017/05/05 22:46:09
 Update:            
 Problem:           Populating Next Right Pointers in Each Node II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/#/submissions/1

 */

#include <cstddef>      // for NULL

#include <queue>
using std::queue;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        return connectSecond(root);
    }
    
    // not constant extra space
    void connectFirst(TreeLinkNode *root)
    {
        if(root == NULL)
            return;
            
        queue<TreeLinkNode *> q;
        q.push(root);
        while(q.empty() == false)
        {
            auto n = q.size();
            
            TreeLinkNode *previous = q.front(), *current = NULL;
            q.pop();
            
            if(previous->left)
                q.push(previous->left);
            if(previous->right)
                q.push(previous->right);
            
            for(decltype(n) i = 1; i < n; ++i)
            {
                current = q.front();
                q.pop();
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
                
                previous->next = current;
                previous = current;
            }
            previous->next = NULL;
        }
    }
    
    TreeLinkNode * FindNextNode(TreeLinkNode * &current, TreeLinkNode *next_level_current)
    {
        if(current == NULL)
            return NULL;
        
        while(current != NULL)
        {
            if(current->left && current->left != next_level_current)
                return current->left;
            if(current->right)
            {
                TreeLinkNode *temp = current->right;
                current = current->next;
                return temp;
            }
            
            current = current->next;
        }
        
        return NULL;
    }
    void connectSecond(TreeLinkNode *root)
    {
        if(root == NULL)
            return;
            
        TreeLinkNode *current = root, *next_level_head = NULL, *next_level_current = NULL;
        while(current != NULL)
        {
            next_level_head = FindNextNode(current, next_level_current);
            next_level_current = next_level_head;
            while(next_level_current != NULL)
            {
                TreeLinkNode *next_node = FindNextNode(current, next_level_current);
                next_level_current->next = next_node;
                next_level_current = next_node;
            }
            
            current = next_level_head;
        }
    }

    // using dummy
    void connectThird(TreeLinkNode *root)
    {
        if(root == NULL)
            return;
            
        TreeLinkNode dummy(0);
        dummy.next = root;
        
        TreeLinkNode *current = NULL, *previous = NULL;
        while(dummy.next != NULL)
        {
            current = dummy.next, previous = &dummy;
            dummy.next = NULL;
            while(current != NULL)
            {
                if(current->left)
                    previous = previous->next = current->left;
                if(current->right)
                    previous = previous->next = current->right;
                
                current = current->next;
            }
        }
    }
};
