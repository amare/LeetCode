/*
 Author:            cuckoo
 Date:              2017/05/18 21:30:35
 Update:            
 Problem:           Clone Graph
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/clone-graph/#/description

 */

#include <cstdio>           // for NULL

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

#include <queue>
using std::queue;

#include <vector>
using std::vector;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return cloneGraphSecond(node);
    }
    
    // BFS
    UndirectedGraphNode *cloneGraphFirst(UndirectedGraphNode *node)
    {
        if(node == NULL)
            return NULL;
        
        unordered_set<int> labels;
        unordered_map<int, UndirectedGraphNode *> label_to_address;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while(q.empty() == false)
        {
            int n = q.size();
            UndirectedGraphNode *current = NULL;
            for(int i = 0; i < n; ++i)
            {
                current = q.front();
                q.pop();
                
                int current_label = current->label;
                if(labels.find(current_label) == labels.end())
                {
                    labels.insert(current_label);
                    
                    UndirectedGraphNode *new_node = new UndirectedGraphNode(current_label);
                    label_to_address[current_label] = new_node;
                    
                    for(auto neighbor : current->neighbors)
                        if(neighbor != NULL && labels.find(neighbor->label) == labels.end())
                            q.push(neighbor);
                }
            }
        }
        
        labels.clear();
        q.push(node);
        while(q.empty() == false)
        {
            int n = q.size();
            UndirectedGraphNode *current = NULL;
            for(int i = 0; i < n; ++i)
            {
                current = q.front();
                q.pop();
                
                int current_label = current->label;
                if(labels.find(current_label) == labels.end())
                {
                    labels.insert(current_label);
                    
                    for(auto neighbor : current->neighbors)
                    {
                        if(neighbor != NULL)
                        {
                            if(labels.find(neighbor->label) == labels.end())
                                q.push(neighbor);
                            label_to_address[current_label]->neighbors.push_back(label_to_address[neighbor->label]);
                        }
                    }
                }
            }
        }
        
        
        return label_to_address[node->label];
    }
    
    // BFS - More concise
    UndirectedGraphNode *cloneGraphSecond(UndirectedGraphNode *node)
    {
        if(node == NULL)
            return NULL;
            
        hash[node] = new UndirectedGraphNode(node->label);
        
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while(q.empty() == false)
        {
            UndirectedGraphNode *current = q.front();
            q.pop();
            
            for(auto neighbor : current->neighbors)
            {
                if(hash.find(neighbor) == hash.end())
                {
                    hash[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                }
                hash[current]->neighbors.push_back(hash[neighbor]);
            }
        }
        
        return hash[node];
    }
    
    // DFS
    UndirectedGraphNode *cloneGraphThird(UndirectedGraphNode *node)
    {
        if(node == NULL)
            return NULL;
        
        if(hash.find(node) == hash.end())
        {
            hash[node] = new UndirectedGraphNode(node->label);
            for(auto neighbor : node->neighbors)
            {
                hash[node]->neighbors.push_back(cloneGraphThird(neighbor));
            }
        }
        
        return hash[node];
    }
    
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
};

