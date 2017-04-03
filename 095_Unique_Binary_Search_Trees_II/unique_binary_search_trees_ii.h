/*
 Author:            cuckoo
 Date:              2017/04/03 19:14:05
 Update:            
 Problem:           Unique Binary Search Trees II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/unique-binary-search-trees-ii/#/description

 */

#include <vector>
using std::vector;

#include <cstddef>      // for NULL

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees_1(n);
    }
    
    TreeNode * clone(TreeNode *old_root)
    {
        if(old_root == NULL) return NULL;
        TreeNode *new_root = new TreeNode(old_root->val);
        new_root->left = clone(old_root->left);
        new_root->right = clone(old_root->right);
        
        return new_root;
    }
    
    vector<TreeNode*> generateTrees_1(int n)
    {
        if(n <= 0) return {};
        vector<TreeNode *> results;
        vector<TreeNode *> previous_result(1, NULL);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < previous_result.size(); ++j)
            {
                // The nth node is the new root
                TreeNode *new_root = new TreeNode(i);
                TreeNode *new_left_subtree = clone(previous_result[j]);
                new_root->left = new_left_subtree;
                results.push_back(new_root);
                
                // traverse the old tree, use new node to replace the old right child
                TreeNode *root = previous_result[j];
                TreeNode *root_temp = root;
                while(root_temp != NULL)
                {
                    TreeNode *old_right_subtree = root_temp->right;
                    TreeNode *new_right_subtree = new TreeNode(i);
                    new_right_subtree->left = old_right_subtree;
                    root_temp->right = new_right_subtree;
                    TreeNode *new_tree = clone(root);
                    results.push_back(new_tree);
                    
                    // reset
                    root_temp->right = old_right_subtree;
                    delete new_right_subtree;
                    new_right_subtree = NULL;
                    root_temp = root_temp->right;
                }
            }
            
            swap(results, previous_result);
            results.clear();
        }

        return previous_result;
    }

   // DP - top to bottom
    void generate(int start, int last, vector<TreeNode*> &result, vector<vector<vector<TreeNode *>>> &dp_table)
    {
        if(start > last)
        {
            result.push_back(NULL);
            return;
        }
        if(!dp_table[start-1][last-1].empty())
        {
            result = dp_table[start-1][last-1];
            return;
        }
        for(int i = start; i <= last; ++i)
        {
            vector<TreeNode *> left_subtree, right_subtree;
            generate(start, i - 1, left_subtree, dp_table);
            generate(i + 1, last, right_subtree, dp_table);
            for(int j = 0; j < left_subtree.size(); ++j)
            {
                for(int k = 0; k < right_subtree.size(); ++k)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_subtree[j];
                    root->right = right_subtree[k];
                    result.push_back(root);
                }
            }
        }
        dp_table[start-1][last-1] = result;
    }

    vector<TreeNode*> generateTrees_2(int n)
    {
        if(n <= 0) return {};
        vector<vector<vector<TreeNode *>>> dp_table(n, vector<vector<TreeNode *>>(n));
        vector<TreeNode *> result;
        generate(1, n, result, dp_table);
        
        return dp_table[0][n-1];
    }
};
