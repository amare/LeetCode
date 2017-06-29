/*
 Author:            cuckoo
 Date:              2017/05/18 19:49:22
 Update:            2017/06/29 19:31:29
 Problem:           Min Stack
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/min-stack/#/description

 */

#include <stack>
using std::stack;

// using two stack
// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack() {
        
//     }
    
//     void push(int x) {
//         if(s2.empty() || x <= getMin())
//             s2.push(x);
//         s1.push(x);
//     }
    
//     void pop() {
//         if(s2.top() == s1.top())
//             s2.pop();
//         s1.pop();
//     }
    
//     int top() {
//         return s1.top();
//     }
    
//     int getMin() {
//         return s2.empty() ? INT_MIN : s2.top();
//     }
    
// private:
//     stack<int> s1;
//     stack<int> s2;
// };

// using only one stack - the best one
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_value = INT_MAX;
    }
    
    void push(int x) {
        if(x <= min_value)
        {
            s.push(min_value);
            min_value = x;
        }
        s.push(x);
    }
    
    void pop() {
        if(s.top() == min_value)
        {
            s.pop();
            min_value = s.top();
            s.pop();
        }
        else
            s.pop();
       
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_value;
    }
    
private:
    stack<int> s;
    int min_value;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

// update at 2017/06/29 19:34:41
class MinStack3 {
public:
    MinStack3() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if(s.empty() || number < s.top())
        {
            s.push(number);
            s.push(number);
        }
        else
        {
            int min_val = s.top();
            s.push(number);
            s.push(min_val);
        }
    }

    int pop() {
        // write your code here
        s.pop();
        int result = s.top();
        s.pop();
        
        return result;
    }
    
    int top(){
        int min_val = s.top();
        s.pop();
        int result = s.top();
        s.push(min_val);
        
        return result;
    }

    int getMin() {
        // write your code here
        return s.top();
    }
    
private:
    stack<int> s;
};
