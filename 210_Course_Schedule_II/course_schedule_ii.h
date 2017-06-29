/*
 Author:            cuckoo
 Date:              2017/06/22 20:07:17
 Update:            
 Problem:           Course Schedule II
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/course-schedule-ii/#/description

 */

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <queue>
using std::queue;

#include <utility>
using std::pair;

#include <algorithm>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        return findOrderThird(numCourses, prerequisites);
    }
    
    // DFS
    vector<int> findOrderFirst(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        // make a graph from given data
        vector<unordered_set<int>> graph(numCourses);
        for(auto &prerequisite : prerequisites)
            graph[prerequisite.second].insert(prerequisite.first);
        
        vector<int> result;
        vector<bool> on_path(numCourses, false);        // if the node has ever been on the path, there is a cycle
        vector<bool> visited(numCourses, false);        // if the node has been visited, then skip it
        for(int i = 0; i < numCourses; ++i)
        {
            if(!visited[i] && HasCycle(graph, on_path, visited, i, result))
                return {};
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool HasCycle(vector<unordered_set<int>> &graph, vector<bool> &on_path, vector<bool> &visited, int node, vector<int> &result)
    {
        //cout << node << endl;
        if(visited[node])
            return false;
        
        visited[node] = true;
        
        on_path[node] = true;
        for(auto next_node : graph[node])
        {
            if(on_path[next_node] || HasCycle(graph, on_path, visited, next_node, result))
                return true;
        }
        on_path[node] = false;

        result.push_back(node);
        
        return false;
    }
    
    // BFS
    vector<int> findOrderSecond(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        // calculate in-degree of every node
        vector<int> indegree(numCourses);
        for(auto &prerequisite : prerequisites)
            ++indegree[prerequisite.first];
        
        // push all nodes whose in-degree is equal to zero(means this course don't need prerequisite course) into queue
        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
            if(0 == indegree[i])
                q.push(i);
        
        vector<int> result;
        int count = q.size();
        while(!q.empty())
        {
            int course = q.front();
            q.pop();                    // finish this prerequisite course already
            
            result.push_back(course);
            
            for(auto &prerequisite : prerequisites)
            {
                if(course == prerequisite.second)       // current course depends on the finished course
                {
                    --indegree[prerequisite.first];
                    if(0 == indegree[prerequisite.first])   // current course can be finished
                    {
                        ++count;
                        q.push(prerequisite.first);
                    }
                }
            }
        }
        
        return count == numCourses ? result : vector<int>();
    }
    
    // BFS - Faster
    vector<int> findOrderThird(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        // make a graph
        vector<unordered_set<int>> graph(numCourses);
        for(auto &prerequisite : prerequisites)
            graph[prerequisite.second].insert(prerequisite.first);
        
        // calculate in-degree of every node
        vector<int> indegree(numCourses);
        for(auto &neighbors : graph)
            for(auto &neighbor : neighbors)
                ++indegree[neighbor];
                
        // push all nodes whose in-degree is equal to zero(means this course don't need prerequisite course) into queue
        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
            if(0 == indegree[i])
                q.push(i);
        
        vector<int> result;
        int count = q.size();
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            
            result.push_back(course);
            
            for(auto neighbor : graph[course])
            {
                --indegree[neighbor];
                if(0 == indegree[neighbor])
                {
                    ++count;
                    q.push(neighbor);
                }
            }
        }
        
        return count == numCourses ? result : vector<int>();
    }
};
