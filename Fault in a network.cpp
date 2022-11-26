#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int n = 1e6;
set<int> art_points;
vector<int> disc(n);
vector<int> low(n);
vector<vector<int>> edges;
int tme = 1;

void dfs(int node, int parent, unordered_map<int, list<int>> &graph, vector<int> &visited)
{
    visited[node] = 1;
    disc[node] = tme;
    low[node] = tme;
    tme++;
    int child = 0;
    
    for(auto x : graph[node])
    {
        if(!visited[x])
        {
            dfs(x, node, graph, visited);
            child++;
            low[node] = min(low[node], low[x]);
            
            //check articulation art_points
            if(parent != 0 and low[x] >= disc[node])
            {
                art_points.insert(node);
            }
            
            // check bridges
            if(low[x] > disc[node])
            {
                edges.push_back({node, x});
            }
            
        }
        else if(x != parent)
        {
            low[node] = min(low[node], disc[x]);
        }
    }
    
    if(parent == 0 and child > 1)
    {
        art_points.insert(node);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
    unordered_map<int, list<int>> graph;
    vector<int> visited(n, 0); 
    
    
    for(int i=0; i<connections.size(); i++)
    {
        graph[connections[i][0]].push_back(connections[i][1]);
        graph[connections[i][1]].push_back(connections[i][0]);
    }
    
    edges.clear();
    
    dfs(0, 0, graph, visited);
    
    return edges;
}

int main() {
    return 0;
}