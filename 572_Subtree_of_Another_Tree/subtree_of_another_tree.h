/*
 Author:            cuckoo
 Date:              2017/07/14 22:46:06
 Update:            
 Problem:           Subtree of Another Tree
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/subtree-of-another-tree/#/description

 */

#include <cstddef>          // for NULL

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>        // for max()

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return IsSubtreeSecond(s, t);
    }
    
    // the best one
    bool IsSubtreeFirst(TreeNode* s, TreeNode* t)
    {
        return IsSameTree(s, t) || s != NULL && (IsSubtreeFirst(s->left, t) || IsSubtreeFirst(s->right, t));
    }
    
    bool IsSameTree(TreeNode *s, TreeNode *t)
    {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL)
            return false;
        
        /* 上面两条语句等价于下面一条语句
        if (s == NULL || t == NULL) {
            return s == t;
        }
        */
        
        return s->val == t->val && IsSameTree(s->left, t->left) && IsSameTree(s->right, t->right);
    }
    
    //
    bool IsSubtreeSecond(TreeNode* s, TreeNode* t)
    {
        string s1 = PreOrderTraversal(s, true);
        string t1 = PreOrderTraversal(t, true);
        
        return t1.size() == LongestCommonSubstring(s1, t1);
    }
    
    string PreOrderTraversal(TreeNode *root, bool left)
    {
        if(root == NULL)
        {
            if(left)
                return "lnull";
            else
                return "rnull";
        }
        
        return "#" + std::to_string(root->val) + PreOrderTraversal(root->left, true) + PreOrderTraversal(root->right, false);
    }
    
    int LongestCommonSubstring(string &s1, string &s2)
    {
        int m = s1.size(), n = s2.size();
        vector<int> dp(n + 1, 0);
        
        int result = 0;
        for(int i = 1; i <= m; ++i)
        {
            int prev = 0;
            for(int j = 1; j <= n; ++j)
            {
                int temp = dp[j];
                dp[j] = s1[i-1] == s2[j-1] ? prev + 1 : 0;
                prev = temp;
                result = std::max(result, dp[j]);
            }
        }

        return result;
    }
};
