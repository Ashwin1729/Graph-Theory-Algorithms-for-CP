#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int messageRoute(int n, vector<vector<int>>edges)
{
    unordered_map<int, list<int>> graph;
    
    for(auto x : edges)
    {
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }
    
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, 0);
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    dist[1] = 0;
    
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        
        for(auto nbrs : graph[t])
        {
            if(!visited[nbrs])
            {
                q.push(nbrs);
                visited[nbrs] = true;
                dist[nbrs] = dist[t] + 1;
            }
        }
    }
    
    if(!visited[n])
    {
        return -1;
    }
    else
    {
        return dist[n]+1;
    }
    
}

int main() {
    return 0;
}