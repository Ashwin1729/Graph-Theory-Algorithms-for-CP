#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int n,vector<vector<int>> edges){
    unordered_map<int, list<int>> graph;
    
    for(int i=0; i<edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
        
    }
    
    int ans = INT_MAX;
    
    for(int i=0; i<n; i++)
    {
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);
        
        dist[i] = 0;
        
        queue<int> q;
        q.push(i);
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            
            for(auto nbrs : graph[x])
            {
                if(dist[nbrs] == INT_MAX)
                {
                    dist[nbrs] = dist[x] + 1;
                    parent[nbrs] = x;
                    q.push(nbrs);
                }
                else if(parent[nbrs] != x and parent[x] != nbrs)
                {
                    ans = min(ans, dist[nbrs]+dist[x]+1);
                }
            }
        }
    }
    
    if(ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
    
}

int main() {
    return 0;
}