/*
 Author:            cuckoo
 Date:              2017/07/01 10:27:56
 Update:            
 Problem:           Find Median From Data Stream
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/find-median-from-data-stream/#/description

 */

#include <vector>
using std::vector;

#include <iostream>

#include <algorithm>        // for heap

#include <queue>
using std::priority_queue;

#include <set>
using std::multiset;

/*
class MedianFinder {
public:
    // initialize your data structure here.
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 奇数时新数据插入最大堆
        if((max_heap.size() + min_heap.size()) & 1 == 1)
        {
            // 待插入的新数据大于最小堆的最小值，则将新数据插入最小堆，同时把最小堆的最小值弹出并插入最大堆
            if(min_heap.size() > 0 && num > min_heap[0])
            {
                max_heap.push_back(min_heap[0]);
                std::push_heap(max_heap.begin(), max_heap.end(), less<int>());
                
                std::pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.pop_back();
                
                min_heap.push_back(num);
                std::push_heap(min_heap.begin(), min_heap.end(), greater<int>());
            }
            else
            {
                max_heap.push_back(num);
                std::push_heap(max_heap.begin(), max_heap.end(), less<int>());
            }
        }
        else    // 偶数时新数据插入最小堆
        {
            // 待插入的新数据小于最大堆的最大值，则将新数据插入最大堆，同时把最大堆的最大值弹出并插入最小堆
            if(max_heap.size() > 0 && num < max_heap[0])
            {
                min_heap.push_back(max_heap[0]);
                std::push_heap(min_heap.begin(), min_heap.end(), greater<int>());
                
                std::pop_heap(max_heap.begin(), max_heap.end(), less<int>());
                max_heap.pop_back();
                
                max_heap.push_back(num);
                std::push_heap(max_heap.begin(), max_heap.end(), less<int>());
            }
            else
            {
                min_heap.push_back(num);
                std::push_heap(min_heap.begin(), min_heap.end(), greater<int>());
            }
        }
    }
    
    double findMedian() {
        int size = min_heap.size() + max_heap.size();
        if(size <= 0)
        {
            std::cerr << "No numbers are available" << endl;
            return 0;
        }
        
        return (size & 1) == 1 ? min_heap[0] : (static_cast<double>(max_heap[0]) + min_heap[0]) / 2;
    }
    
private:
    vector<int> max_heap;
    vector<int> min_heap;
};
*/

/*
class MedianFinder
{
public:
    MedianFinder()
    {
        
    }
    
    void addNum(int num)
    {
        max_heap.push(num);
        
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        if(max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian()
    {
        return max_heap.size() == min_heap.size()
                                ? (max_heap.top() + min_heap.top()) * 0.5
                                : static_cast<double>(max_heap.top());
    }
    
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
};
*/

class MedianFinder
{
public:
    MedianFinder()
    {
        low_median = data.end();
        high_median = data.end();
    }
    
    void addNum(int num)
    {
        int size = data.size();
        
        data.insert(num);
        
        if(size == 0)
            low_median = high_median = data.begin();
        else if((size & 1) == 0)            // 注意符号优先级
        {
            if(num < *low_median)
                --high_median;
            else if(num >= *high_median)
                ++low_median;
            else
            {
                --high_median;
                ++low_median;
            }
        }
        else
        {
            if(num < *low_median)
                --low_median;
            else
                ++high_median;
        }
        
        // cout << num << ": " << *low_median << " " << *high_median << endl;
    }
    
    double findMedian()
    {
        return (*low_median + *high_median) * 0.5;
    }
    
private:
    multiset<int> data;
    multiset<int>::iterator low_median, high_median;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
