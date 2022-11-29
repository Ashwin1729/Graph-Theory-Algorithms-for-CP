#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool levelGraph(vector<vector<int>> &graph, vector<vector<int>> &resEdges, vector<int> &level, int src, int sink, int n)
{
    level.clear();
    level.resize(n+1, -1);
    
    queue<int> q;
    q.push(src);
    level[src] = 1;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto x : graph[node])
        {
            int y = resEdges[x][1];
            int w = resEdges[x][2];
            
            if(w and level[y] == -1)
            {
                level[y] = level[node] + 1;
                q.push(y);
            }
        }
    }
    
    return (level[sink] != -1);
}

int augmentedPath(vector<vector<int>> &graph, vector<vector<int>> &resEdges, vector<int> &level, int src, int sink, vector<int> &resEdSize, int flow)
{
    if(src == sink)
    {
        return flow;
    }
    
    for(int &i = resEdSize[src]; i>=0; i--)
    {
        int edge_index = graph[src][i];
        int y = resEdges[edge_index][1];
        int w = resEdges[edge_index][2];
        
        if(w and level[y] == (level[src] + 1))
        {
            int bottleneckFlow = augmentedPath(graph, resEdges, level, y, sink, resEdSize, min(flow, w));
            
            if(bottleneckFlow)
            {
                resEdges[edge_index][2] -= bottleneckFlow;
                resEdges[edge_index^1][2] += bottleneckFlow;
                return bottleneckFlow;
            }
        }
    }
    
    return 0;
}

int solve(int n, vector<vector<int>> edges)
{
    vector<vector<int>> graph;
    int idx = 0;
    vector<vector<int>> resEdges;
    vector<int> level(n+1, -1);
    
    for(int i=0; i<edges.size(); i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int w = edges[i][2];
        
        resEdges.push_back({x, y, w});
        graph[x].push_back(idx++);
        resEdges.push_back({y, x, 0});
        graph[y].push_back(idx++);
    }
    
    int total_flow = 0;
    vector<int> resEdSize(n+1);
    
    while(levelGraph(graph, resEdges, level, 1, n, n))
    {
        for(int i=1; i<=n; i++)
        {
            resEdSize[i] = graph[i].size()-1;
        }
        while(int flow = augmentedPath(graph, resEdges, level, 1, n, resEdSize, INT_MAX))
        {
            total_flow += flow;
        }
    }
    
    return total_flow;
}

int main() {
    return 0;
}