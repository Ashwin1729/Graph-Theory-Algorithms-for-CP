#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    void bfs(unordered_map<int, list<int>> &graph, vector<int> &ans, int numCourses)
    {
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        
        for(int i=0; i<numCourses; i++)
        {
            for(auto nbrs : graph[i])
            {
                indegree[nbrs]++;
            }
        }
        
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            
            for(auto nbrs : graph[x])
            {
                indegree[nbrs]--;
                if(indegree[nbrs] == 0)
                {
                    q.push(nbrs);
                }
            }
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> graph;
        vector<int> ans;
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        bfs(graph, ans, numCourses);
        
        if(ans.size() == numCourses)
        {
            return ans;
        }
        else
        {
            return vector<int>();
        }
        
    }

int main() {
    return 0;
}