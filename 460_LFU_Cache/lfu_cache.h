/*
 Author:            cuckoo
 Date:              2017/07/18 20:14:03
 Update:            
 Problem:           LFU Cache
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/lfu-cache/#/description

 */

#include <unordered_map>
using std::unordered_map;

#include <list>
using std::list;

class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity), min_frequency_(0) {}
    
    int get(int key)
    {
        auto iter = basic.find(key);
        if(iter == basic.end())             // not found
            return -1;
            
        touch(iter, key);
        
        return iter->second.first;
    }
    
    void put(int key, int value)
    {
        if(capacity_ <= 0)
            return;
        
        auto iter = basic.find(key);
        if(iter != basic.end())                 // found
        {
            iter->second.first = value;         // update value
            touch(iter, key);
        }
        else                                    // not found
        {
            if(basic.size() == capacity_)
            {
                basic.erase(frequencies[min_frequency_].back());
                iterators.erase(frequencies[min_frequency_].back());
                frequencies[min_frequency_].pop_back();
                
                /*
                // update min_frequecy_
                if(frequencies[min_frequency_].empty())
                    ++min_frequency_;
                */
            }
            basic[key] = std::make_pair(value, 1);
            frequencies[1].push_front(key);
            min_frequency_ = 1;
            iterators[key] = frequencies[1].begin();
        }      
    }
    
private:
    int capacity_;
    int min_frequency_;
    
    unordered_map<int, std::pair<int, int> > basic;             // key to {value, frequency}
    unordered_map<int, list<int>::iterator> iterators;          // key to actural position in the list
    unordered_map<int, list<int> > frequencies;                 // similar to bucket sort - frequecny to a list
    
    // update the frequency of the key node
    void touch(unordered_map<int, std::pair<int, int> >::iterator iter, int key)
    {
        frequencies[iter->second.second].erase(iterators[key]);
        ++iter->second.second;
        frequencies[iter->second.second].push_front(key);
        iterators[key] = frequencies[iter->second.second].begin();
            
        // update min_frequecy_
        if(frequencies[min_frequency_].empty())
            ++min_frequency_;     
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
