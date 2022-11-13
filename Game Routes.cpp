#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void top_sort(unordered_map<int, list<int>> &graph, vector<int> &indegree, int n)
{
    queue<int> q;
    for(int i=2; i<=n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int x = q.front();
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



int gameRoutes(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> graph;
    vector<int> indegree(n+1, 0);
    vector<int> cnt(n+1, 0);
    
    const int modb = 1e9+7;
    
    for(int i=0; i<edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    
    top_sort(graph, indegree, n);
    
    queue<int> q;
    q.push(1);
    cnt[1] = 1;
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for(auto nbrs : graph[x])
        {
            indegree[nbrs]--;
            cnt[nbrs] = cnt[nbrs] + cnt[x];
            cnt[nbrs] = cnt[nbrs]%modb;
            
            if(indegree[nbrs] == 0)
            {
                q.push(nbrs);
            }
        }
    }
    
    return cnt[n];
}

int main() {
    return 0;
}