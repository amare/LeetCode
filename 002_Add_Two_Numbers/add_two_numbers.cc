/*
 Author:            cuckoo
 Date:              2017/02/25 16:39:08
 Update:
 Problem:           Add Two Numbers
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/add-two-numbers
 Note:
 You are given two non-empty linked lists representing two non-negative integers. The digits
 are stored in reverse order and each of their nodes contain a single digit. Add the two
 numbers and return it as a linked list.
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 Solution

 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x): val(x), next(nullptr){}
};

ListNode* addTwoNumbers_1(ListNode *list_a, ListNode *list_b)
{
    // calculate the size of ListNode
    int list_a_size = 1;
    int list_b_size = 1;

    ListNode *next_pointer = list_a->next;
    while(next_pointer)
    {
        ++list_a_size;
        next_pointer = next_pointer->next;
    }
    next_pointer = list_b->next;
    while(next_pointer)
    {
        ++list_b_size;
        next_pointer = next_pointer->next;
    }

    // main loop
    int smaller_size = list_a_size <= list_b_size ? list_a_size : list_b_size;
    auto list_c = new ListNode(0);
    auto current_node_a = list_a;
    auto current_node_b = list_b;
    auto current_node_c = list_c;

    int a = 0;
    int b = 0;
    int carry = 0;      // if a + b >= 10, carry should be 1
    int sum = 0;        // a + b + carry

    while(smaller_size--)
    {
        a = current_node_a->val;
        b = current_node_b->val;
        sum = a + b + carry;

        if(sum >= 10)
        {
            current_node_c->val = sum - 10;
            carry = 1;
        }
        else
        {
            current_node_c->val = sum;
            carry = 0;
        }

        current_node_a = current_node_a->next;
        current_node_b = current_node_b->next;
        current_node_c->next = new ListNode(0);
        current_node_c = current_node_c->next;
    }// note: the real size of list_c is one bigger than smaller_size after loop

    if(carry == 0 && list_a_size == list_b_size)   //delete the redundant element 0 of list_c
    {
        auto new_current_node_c = list_c;
        while(new_current_node_c->next != current_node_c)
        {
            new_current_node_c = new_current_node_c->next;
        }
        new_current_node_c->next = nullptr;
        delete current_node_c;

        return list_c;
    }
    else if(carry == 1 && list_a_size == list_b_size)   // list_a = [5] && list_b = [5]
    {
        current_node_c->val = 1;

        return list_c;
    }

    // handle the situation that list_a is longer than list_b or the opposite situation
    bool list_a_bigger_flag = false;
    if(list_a_size > list_b_size)
    {
        list_a_bigger_flag = true;
    }
    if(list_a_bigger_flag)
    {
        auto new_current_node_a = current_node_a;
        auto new_current_node_c = current_node_c;
        int new_a = 0;
        int new_sum_a = 0;    // new_a + carry
        while(new_current_node_a->next)
        {
            new_a = new_current_node_a->val;
            if(new_sum_a >= 10)
            {
                new_current_node_c->val = new_sum_a - 10;
                carry = 1;
            }
            else
            {
                new_current_node_c->val = new_sum_a;
                carry = 0;
            }

            new_current_node_a = new_current_node_a->next;
            new_current_node_c->next = new ListNode(0);
            new_current_node_c = new_current_node_c->next;
        }

        int final_a = new_current_node_a->val;
        if(final_a + carry >= 10)
        {
            new_current_node_c->val = final_a + carry - 10;
            new_current_node_c->next = new ListNode(0);
            new_current_node_c->next->val = 1;
            //new_current_node_c->next->next = nullptr:
        }
        else
        {
            new_current_node_c->val = final_a + carry;
            //carry = 0;
        }
    }
    else
    {
        auto new_current_node_b = current_node_b;
        auto new_current_node_c = current_node_c;
        int new_b = 0;
        int new_sum_b = 0;  // new_b + carry
        while(new_current_node_b->next)
        {
            new_b = new_current_node_b->val;
            if(new_sum_b >= 10)
            {
                new_current_node_c->val = new_sum_b - 10;
                carry = 1;
            }
            else
            {
                new_current_node_c->val = new_sum_b;
                carry = 0;
            }

            new_current_node_b = new_current_node_b->next;
            new_current_node_c->next = new ListNode(0);
            new_current_node_c = new_current_node_c->next;
        }

        int final_b = new_current_node_b->val;
        if(final_b + carry >= 10)
        {
            new_current_node_c->val = final_b + carry - 10;
            new_current_node_c->next = new ListNode(0);
            new_current_node_c->next->val = 1;
            //new_current_node_c->next->next = nullptr:
        }
        else
        {
            new_current_node_c->val = final_b + carry;
            //carry = 0;
        }
    }

    return list_c;
}

void insert(ListNode *List, vector<int> &data)
{
    ListNode *current_node = List;
    for(auto iter = data.begin(); iter != data.end(); ++iter)
    {
        current_node->val = *iter;
        current_node->next = new ListNode(0);
        current_node = current_node->next;
    }

    ListNode *new_current_node = List;
    while(new_current_node->next != current_node)
    {
        new_current_node = new_current_node->next;
    }
    new_current_node->next = nullptr;
    delete current_node;
}

void print(ListNode *List)
{
    ListNode *current_node = List;
    while(current_node)
    {
        cout << current_node->val << ' ';
        current_node = current_node->next;
    }
    cout << endl;
}

int main()
{
    vector<int> data_a{2, 4, 3};
    ListNode *list_a = new ListNode(0);
    insert(list_a, data_a);
    // print(list_a);

    vector<int> data_b{5, 6, 4};
    ListNode *list_b = new ListNode(0);
    insert(list_b, data_b);

    print(addTwoNumbers_1(list_a, list_b));

    return 0;
}
