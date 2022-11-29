#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs1(int node, unordered_map<int, list<int>> &graph, vector<int> &visitedG, vector<int> &topSort)
{
    visitedG[node] = 1;
    
    for(auto x : graph[node])
    {
        if(!visitedG[x])
        {
            dfs1(x, graph, visitedG, topSort);
        }
    }
    
    topSort.push_back(node);
}

void dfs2(int node, unordered_map<int, list<int>> &graphR, vector<int> &visitedGR)
{
    visitedGR[node] = 1;
    
    for(auto x : graphR[node])
    {
        if(!visitedGR[x])
        {
            dfs2(x, graphR, visitedGR);
        }
    }
}

bool solve(int n, vector<vector<int>> roads) {
    
    unordered_map<int, list<int>> graph; 
    unordered_map<int, list<int>> graphR;
    vector<int> visitedG(n, 0);
    vector<int> visitedGR(n, 0);
        
    vector<int> topSort;
    
    int ans = 1;
    
    for(int i=0; i<roads.size(); i++)
    {
        graph[roads[i][0]].push_back(roads[i][1]);
        graphR[roads[i][1]].push_back(roads[i][0]);
    }
    
    for(int i=0; i<n; i++)
    {
        if(!visitedG[i])
        {
            dfs1(i, graph, visitedG, topSort);
        }
    }
    
    reverse(topSort.begin(), topSort.end());
    
    for(int i=0; i<n; i++)
    {
        if(!visitedGR[topSort[i]])
        {
            dfs2(topSort[i], graphR, visitedGR);
            ans++;
        }
    }
    
    return ((ans-1) == 1) ? true : false;
}

int main() {
    return 0;
}