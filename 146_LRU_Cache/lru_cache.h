/*
 Author:            cuckoo
 Date:              2017/07/18 13:33:00
 Update:            
 Problem:           LRU Cache
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/lru-cache/#/description

 */

#include <unordered_map>
using std::unordered_map;

#include <list>
using std::list;

class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {}
    
    int get(int key)
    {
        auto iter = cache.find(key);
        if(iter == cache.end())
            return -1;
        
        touch(iter);
        return iter->second.first;
    }
    
    // same key, value maybe be updated
    void put(int key, int value)
    {
        auto iter = cache.find(key);
        if(iter != cache.end())
        {
            touch(iter);
        }
        else
        {
            if(cache.size() == capacity_)
            {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = std::make_pair(value, used.begin());
    }
    
private:
    typedef unordered_map<int, std::pair<int, list<int>::iterator>> Cache;
    
    int capacity_;
    
    list<int> used;
    Cache cache;
    
    // After using recently, move the old node to the first position of the list, remove and then add
    void touch(Cache::iterator iter)
    {
        auto key = iter->first;
        used.erase(iter->second.second);
        used.push_front(key);
        iter->second.second = used.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
