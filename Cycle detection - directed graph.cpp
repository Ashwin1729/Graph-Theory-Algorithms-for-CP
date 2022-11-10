#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, unordered_map<int, list<int>> &graph, vector<bool> &visited, vector<bool> &path)
{
    visited[node] = true;
    path[node] = true;
    
    for(auto nbr : graph[node])
    {
        if(path[nbr])
        {
            return true;
        }
        else if(!visited[nbr])
        {
            bool foundCycle = dfs(nbr, graph, visited, path);
            if(foundCycle)
            {
                return true;
            }
        }
    }
    
    path[node] = false;
    return false;
}

bool solve(int n, vector<vector<int>>edges) {
    unordered_map<int, list<int>> graph;
    vector<bool> visited(n+1, false); 
    vector<bool> path(n+1, false);
    
    bool ans = false;
    
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            ans = ans | dfs(i, graph, visited, path);
        }
    }
    
    return ans;
}

int main() {
    return 0;
}