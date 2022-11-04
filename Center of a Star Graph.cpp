#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findCenter(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    unordered_map<int, list<int>> graph;
    
    for(long unsigned int i=0; i<edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(auto x : graph)
    {
        if(x.second.size() == edges.size())
        {
            return x.first;
        }
    }
    
    return -1;
}

int main()
{
    return 0;
}