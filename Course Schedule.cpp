#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    bool dfs(int node, unordered_map<int, list<int>> &graph, vector<bool> &visited, vector<bool> &path)
    {
        visited[node] = true;
        path[node] = true;
        
        for(auto nbrs : graph[node])
        {
            if(path[nbrs])
            {
                return true;
            }
            else if(!visited[nbrs])
            {
                bool cycle = dfs(nbrs, graph, visited, path);
                if(cycle)
                {
                    return true;
                }
            }
        }
        
        path[node] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> graph;
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        bool ans = false;
        
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                ans = ans | dfs(i, graph, visited, path);
            }
        }
        
        return !ans;
    }

int main() {
    return 0;
}