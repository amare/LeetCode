/*
 Author:            cuckoo
 Date:              2017/03/12 10:02:15
 Update:
 Problem:           Merge k Sorted Lists
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/merge-k-sorted-lists

 */

#include <cstddef>  // for NULL
#include <vector>
using std::vector;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists_2(lists);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }

    ListNode* mergeKLists_1(vector<ListNode*>& lists)
    {
        ListNode *result = NULL;
        for(int i = 0; i < lists.size(); ++i)
        {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }

    ListNode* mergeKLists_2(vector<ListNode*>& lists)
    {
        int size = lists.size();
        if(0 == size) return NULL;
        while(size > 1)
        {
            for(int i = 0; i < size / 2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[size - 1 - i]);
            size = (size + 1) / 2;  // handle with odd and even case
        }

        return lists.front();
    }
};
