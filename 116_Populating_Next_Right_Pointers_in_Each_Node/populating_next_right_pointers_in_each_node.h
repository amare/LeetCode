/*
 Author:            cuckoo
 Date:              2017/04/01 17:33:39
 Update:            
 Problem:           Populating Next Right Pointers in Each Node
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/populating-next-right-pointers-in-each-node/#/description

 */

#include <queue>
using std::queue;

#include <cstddef>      // for NULL


// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect_2(root);
    }
    
    // correct answer, not constant extra space
    void connect_1(TreeLinkNode *root)
    {
        if(root == NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto size = q.size();
            TreeLinkNode *current_node = q.front();
            TreeLinkNode *previous_node = current_node;
            if(current_node->left) q.push(current_node->left);
            if(current_node->right) q.push(current_node->right);
            q.pop();
            
            for(decltype(size) i = 1; i < size; ++i)
            {
                current_node = q.front();
                q.pop();
                if(current_node->left) q.push(current_node->left);
                if(current_node->right) q.push(current_node->right);
                
                previous_node->next = current_node;
                previous_node = current_node;
            }
            previous_node->next = NULL;
        }
    }

    // use link information of current level to link the next level
    void connect_2(TreeLinkNode *root)
    {
        if(root == NULL) return;
        TreeLinkNode *current_node = root;
        TreeLinkNode *current_level_head_node = NULL;
        while(current_node->left)
        {
            current_level_head_node = current_node;
            while(current_node)
            {
                current_node->left->next = current_node->right;
                if(current_node->next)
                    current_node->right->next = current_node->next->left;
                current_node = current_node->next;
            }
            current_node = current_level_head_node->left;
        }
    }

    // recursion version
    void connect_3(TreeLinkNode *root)
    {
        if(root == NULL) return;
        if(root->left) root->left->next = root->right;
        if(root->right && root->next) root->right->next = root->next->left;
        connect_3(root->left);
        connect_3(root->right);
    }
};
