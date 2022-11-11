#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited, int parent, int color)
    {
        visited[node] = color;
        
        for(auto nbrs : graph[node])
        {
            if(visited[nbrs] == 0)
            {
                bool isBipartite = dfs(nbrs, graph, visited, node, 3 - color);
                if(!isBipartite)
                {
                    return false;
                }
            }
            else if(nbrs != parent and color == visited[nbrs])
            {
                return false;
            }
        }
        
        return true;
    }

bool solve(vector<vector<int>> graph)
{
    vector<int> visited(graph.size(), 0);
    
    bool ans = true;
    
    for(int i=0; i<graph.size(); i++)
    {
        if(visited[i] == 0)
        {
            ans = ans and dfs(i, graph, visited, -1, 1);
        }
    }
    return !ans;
}

int main() {
    return 0;
}