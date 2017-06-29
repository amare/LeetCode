/*
 Author:            cuckoo
 Date:              2017/06/28 22:16:47
 Update:            
 Problem:           Implement Stack using Queues
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/implement-stack-using-queues/#/description

 */

#include <queue>
using std::queue;

class MyStack0 {
public:
    /** Initialize your data structure here. */
    MyStack0() {
        p1 = &q1;
        p2 = &q2;
        top_element = INT_MIN;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        p1->push(x);
        top_element = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(p1->size() > 1)
        {
            top_element = p1->front();
            p2->push(top_element);
            p1->pop();
        }
        
        int result = p1->front();
        p1->pop();
        swap(p1, p2);
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return top_element;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return p1->empty();
    }
    
private:
    queue<int> q1, q2;
    queue<int> *p1, *p2;
    int top_element;
};

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int size = q.size();
        while(size > 1)
        {
            q.push(q.front());
            q.pop();
            --size;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = q.front();
        q.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
