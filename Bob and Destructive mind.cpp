#include<bits/stdc++.h>
using namespace std;

const int n = 1e6;
set<int> art_points;
vector<int> disc(n);
vector<int> low(n);
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


vector<bool> destructiveBob(int n, vector<vector<int>> edges, vector<int>queries)
{
    unordered_map<int, list<int>> graph;
    vector<int> visited(n+1, 0); 
    
    
    for(int i=0; i<edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    art_points.clear();
    
    dfs(1, 0, graph, visited);
    
    vector<bool> ans;
    
    for(int i=0; i<queries.size(); i++)
    {
        if(art_points.find(queries[i]) != art_points.end())
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }
    
    return ans;
}

int main() {
    return 0;
}