/*
 Author:            cuckoo
 Date:              2017/05/19 16:51:08
 Update:            
 Problem:           Course Schedule
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/course-schedule/#/description

 */

#include <queue>
using std::queue;

#include <vector>
using std::vector;

#include <utility>
using std::pair;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        return CanFinishThird(numCourses, prerequisites);
    }
    /* wrong
    bool CanFinishFirst(int num_courses, vector<pair<int, int>>& prerequisites)
    {
        
        // sort(prerequisites.begin(), prerequisites.end(), [](pair<int, int> left, pair<int, int> right){
        //         return left.first < right.first;
        //     });
            
        // for(auto & prerequisite : prerequisites)
        //     cout << prerequisite.first << prerequisite.second << endl;
        
        
        unordered_map<int, vector<pair<int, int> > > hash;
        
        // 找到所有依赖于其他课程，同时不被任一课程依赖的所有课程
        vector<int> dependents;
        unordered_set<int> independents;
        for(auto & prerequisite : prerequisites)
        {
            hash[prerequisite.first].push_back(prerequisite);
            independents.insert(prerequisite.second);   
        }
        
        for(int i = 0; i < num_courses; ++i)
            if(independents.find(i) == independents.end())
                dependents.push_back(i);
        
        unordered_set<int> access;
        for(auto course : dependents)
        {
            queue<int> q;
            q.push(course);
            while(q.empty() == false)
            {
                int current = q.front();
                q.pop();
                
                if(access.find(current) == access.end())
                {
                    access.insert(current);
                    
                    if(hash.find(current) != hash.end())
                    {
                        for(auto &p : hash[current])
                        {
                            q.push(p.second);
                        }
                    }
                }
                else
                    return false;
            }
        }
        
        return access.size() == num_courses;
    }
    */
    
    // Kahn's algorithm - BFS
    bool CanFinishSecond(int num_courses, vector<pair<int, int>>& prerequisites)
    {
        if(num_courses == 0 || prerequisites.size() == 0)
            return true;
        
        // calculate the indegree of every node
        vector<int> indegree(num_courses);
        for(auto &prerequisite : prerequisites)
            ++indegree[prerequisite.first];
        
        // en-queue all courses which don't need prerequisites
        queue<int> q;
        for(int i = 0; i < num_courses; ++i)
            if(indegree[i] == 0)
                q.push(i);
                
        int count = q.size();
        while(q.empty() == false)
        {
            int course = q.front();
            q.pop();                    // finished this prerequisite course already
            
            for(auto &prerequisite : prerequisites)
            {
                if(prerequisite.second == course)       // current course depends on the finished course
                {
                    --indegree[prerequisite.first];
                    if(0 == indegree[prerequisite.first])       // current course can be finished
                    {
                        ++count;
                        q.push(prerequisite.first);
                    }
                }
            }
        }
        
        return count == num_courses;        // or check if the indegrees of all node are 0
    }
    
    // DFS
    bool CanFinishThird(int num_courses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int> > matrix(num_courses);
        for(auto &prerequisite : prerequisites)
            matrix[prerequisite.second].insert(prerequisite.first);
            
        unordered_set<int> visited;
        vector<bool> flag(num_courses, false);
        for(int i = 0; i < num_courses; ++i)
        {
            if(flag[i] == false)
            {
                if(HasCycle(matrix, visited, flag, i))
                    return false;
            }
        }
        
        return true;
    }
    
    bool HasCycle(vector<unordered_set<int> > &matrix, unordered_set<int> &visited, vector<bool> &flag, int node)
    {
        flag[node] = true;
        
        visited.insert(node);
        for(auto iter = matrix[node].begin(); iter != matrix[node].end(); ++iter)       // if  matrix[node].empty() == true
        {                                                                               // then matrix[node].begin() == matrix[node].end()
            if(visited.find(*iter) != visited.end() || HasCycle(matrix, visited, flag, *iter))
                return true;
        }
        visited.erase(node);
        
        return false;
    }
};
