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

#include <queue>
using std::priority_queue;

#include <algorithm>
using std::make_heap;
using std::pop_heap;
using std::push_heap;


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

    struct compare
    {
        bool operator()(const ListNode *l1, const ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };
    // priority_queue
    ListNode* mergeKLists_3(vector<ListNode*>& lists)
    {
        priority_queue<ListNode *, vector<ListNode*>, compare> q;
        for(auto l : lists)
            if(l)
                q.push(l);
        if(q.empty()) return NULL;

        ListNode head(INT_MIN);
        ListNode *tail = &head;
        while(!q.empty())
        {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next)
                q.push(tail->next);
        }

        return head.next;
    }
    // heap
    ListNode* mergeKLists_4(vector<ListNode*>& lists)
    {
        vector<ListNode *> heap;
        for(auto l : lists)
        {
            if(l) heap.push_back(l);
        }
        auto comp = [](ListNode * &a, ListNode * &b) -> bool { return a->val > b->val; };
        make_heap(heap.begin(), heap.end(), comp);
        if(heap.empty()) return NULL;

        ListNode head(INT_MIN);
        ListNode *tail = &head;
        while(!heap.empty())
        {
            tail->next = heap.front();
            pop_heap(heap.begin(), heap.end(), comp);
            heap.pop_back();
            tail = tail->next;
            if(tail->next)
            {
                heap.push_back(tail->next);
                push_heap(heap.begin(), heap.end(), comp);
            }
        }

        return head.next;
    }

    ListNode *partition(vector<ListNode*> &lists, int low, int high)
    {
        if(low == high)
            return lists[low];
        if(low < high)
        {
            int mid = (low + high) / 2;
            ListNode *l1 = partition(lists, low, mid);
            ListNode *l2 = partition(lists, mid + 1, high);
            return mergeTwoLists(l1, l2);
        }

        return NULL;
    }

    ListNode* mergeKLists_5(vector<ListNode*>& lists)
    {
        return partition(lists, 0, lists.size() - 1);
    }
};
