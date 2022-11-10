#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, unordered_map<int, list<int>> &graph, vector<bool> &visited, int parent)
{
    visited[node] = true;
    
    for(auto nbr : graph[node])
    {
        if(!visited[nbr])
        {
            bool foundCycle = dfs(nbr, graph, visited, node);
            if(foundCycle)
            {
                return true;
            }
        }
        else if(nbr != parent)
        {
            return true;
        }
    }
    return false;
}

bool solve(int n, vector<vector<int> > edges) {

    unordered_map<int, list<int>> graph;
    vector<bool> visited(n+1, false);
    vector<bool> ref;
    bool ans = false;
    
    if(n == 1)
    {
        return false;
    }
    
    for(int i=0; i<edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                ref.push_back(dfs(i, graph, visited, -1));
            }
        }
        
        for(int i=0; i<ref.size(); i++)
        {
            ans = ans | ref[i];
        }

        return ans;
}

int main() {
    return 0;
}