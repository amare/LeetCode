/*
 Author:            cuckoo
 Date:              2017/07/21 10:45:07
 Update:            
 Problem:           Lowest Common Ancestor of a Binary Tree
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/#/description

 */

#include <cstddef>          // for NULL

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

#include <queue>
using std::queue;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LowestCommonAncestorSecond(root, p, q);
    }
    
    TreeNode* LowestCommonAncestorFirst(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // check input
        
        vector<TreeNode *> p_path, q_path;
        FindPath(root, p, p_path);
        FindPath(root, q, q_path);
        
        // Find the last common node of two paths
        int i = 0;
        while(i < p_path.size() && i < q_path.size() && p_path[i] == q_path[i])
            ++i;
        
        return p_path[i-1];
    }
    
    // find path from root to node
    bool FindPath(TreeNode *root, TreeNode *node, vector<TreeNode *> &result)
    {
        if(root == NULL)
            return false;
        
        result.push_back(root);
        if(root == node || FindPath(root->left, node, result) || FindPath(root->right, node, result))
            return true;
        result.pop_back();
        
        return false;
    }
    
    TreeNode* LowestCommonAncestorSecond(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL || root == p || root == q)
            return root;
        
        TreeNode *left = LowestCommonAncestorSecond(root->left, p, q);
        TreeNode *right = LowestCommonAncestorSecond(root->right, p, q);
        
        return left == NULL ? right : right == NULL ? left : root;
    }
   

    TreeNode* LowestCommonAncestorThird(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        unordered_map<TreeNode *, TreeNode *> parents;
        parents[root] = NULL;
        
        queue<TreeNode *> nodes;
        nodes.push(root);
        while(!parents.count(p)|| !parents.count(q))
        {
            int size = nodes.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode *node = nodes.front();
                nodes.pop();
                if(node->left != NULL)
                {
                    parents[node->left] = node;
                    nodes.push(node->left);
                }
                if(node->right != NULL)
                {
                    parents[node->right] = node;
                    nodes.push(node->right);
                }
            }
        }
        
        unordered_set<TreeNode *> ancestors;
        while(p != NULL)
        {
            ancestors.insert(p);
            p = parents[p];
        }
        
        while(q != NULL && !ancestors.count(q))
            q = parents[q];
        
        return q;
    }
};
