/*
 Author:            cuckoo
 Date:              2017/03/04 20:57:57
 Update:
 Problem:           Find Largest Value in Each Tree Row
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/find-largest-value-in-each-tree-row

 */

#include <cstddef>  // for NULL
#include <climits>  // for INT_MIN
#include <vector>
using std::vector;
#include <cmath>
using std::max;
#include <queue>
using std::queue;
#include <iostream>
using std::cout;
using std::endl;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        return largestValues_1(root);
    }

    /*// calculate the depth of the tree
    int DepthOfTree(TreeNode *root)
    {
        int left_depth = 0, right_depth = 0;
        if(root->left)
        {
            left_depth = DepthOfTree(root->left);
        }
        if(root->right)
        {
            right_depth = DepthOfTree(root->right);
        }

        return max(left_depth, right_depth) + 1;
    }
    */

    vector<int> largestValues_1(TreeNode *root)
    {
        if(!root)
            return vector<int>();   // ^attention root == NULL

        queue<TreeNode *> nodes;
        vector<int> results;

        nodes.push(root);
        int nums = 1;       // the numbers of each floor
        int result = 0;     // the max number of each floor
        //
        while(!nodes.empty())
        {
            TreeNode *cur;
            int k = nums;
            nums = 0;
            result = nodes.front()->val;    // ^attention the initialization of result
            for(int i = 0; i < k; ++i)  // k is the numbers of each floor
            {
                cur = nodes.front();
                if(result < cur->val)
                    result = cur->val;
                if(cur->left)
                {
                    ++nums;
                    nodes.push(cur->left);
                }
                if(cur->right)
                {
                    ++nums;
                    nodes.push(cur->right);
                }
                nodes.pop();
            }
            results.push_back(result);
        }

        return results;
    }
};
