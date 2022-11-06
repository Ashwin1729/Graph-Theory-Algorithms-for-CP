#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int dfs(int node, unordered_map<int, list<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    int count = 0;
    for(auto nbrs: graph[node])
    {
        if(!visited[nbrs])
        {
            count += dfs(nbrs, graph, visited);
        }
    }
    
    return count+1;
}

int count_pairs(int N, vector<pair<int,int> > astronauts){
    unordered_map<int, list<int>> graph;
    vector<int> x;
    
    for(long unsigned int i=0; i<astronauts.size(); i++)
    {
        graph[astronauts[i].first].push_back(astronauts[i].second);
        graph[astronauts[i].second].push_back(astronauts[i].first);
    }
    
    vector<bool> visited(N, false);
    
    for(long unsigned int i=0; i<N; i++)
    {
        if(!visited[i])
        {
            int lcount = dfs(i, graph, visited);
            x.push_back(lcount);
        }
    }
    
    int x1 = N*(N-1)/2;
    int x2 = 0;
    
    for(long unsigned int i=0; i<x.size(); i++)
    {
        x2 += x[i]*(x[i]-1)/2;
    }
    return (x1-x2);
}

int main() {
    return 0;
}