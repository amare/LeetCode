/*
 Author:            cuckoo
 Date:              2017/06/10 13:44:17
 Update:            
 Problem:           Binary Search Tree Iterator
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/binary-search-tree-iterator/#/description

 */

#include <stack>
using std::stack;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIteratorFirst {
public:
    BSTIteratorFirst(TreeNode *root) {
        while(root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *current = s.top();
        s.pop();
        
        TreeNode *node = current->right;
        while(node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        
        return current->val;
    }
    
private:
    stack<TreeNode *> s;
};

// Morris Traversal
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        current = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int result;
        while(current != NULL)
        {
            if(current->left)
            {
                TreeNode *node = current->left;
                while(node->right && node->right != current)
                    node = node->right;
                    
                if(node->right == NULL)
                {
                    node->right = current;
                    current = current->left;
                }
                else        // node->right == current
                {
                    node->right = NULL;
                    result = current->val;
                    current = current->right;
                    break;
                }
            }
            else
            {
                result = current->val;
                current = current->right;
                break;
            }
        }
        
        return result;
    }
    
private:
    TreeNode *current;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
