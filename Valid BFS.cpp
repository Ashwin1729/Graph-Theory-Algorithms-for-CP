#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
    unordered_map<int, list<int>> graph;
    
    for(int i=0; i<edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    if(sequence[0] !=  1)
    {
        return false;
    }
    
    set<int> s;
    vector<bool> visited(n+1, false);
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    int index = 1;
    
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        
        for(auto nbr: graph[t])
        {
            if(!visited[nbr])
            {
                s.insert(nbr);
                visited[nbr] = true;
            }
        }
        
        for(auto x : s)
        {
            if(s.count(sequence[index]))
            {
                q.push(sequence[index]);
                index++;
            }
            else
            {
                return false;
            }
        }
        
        s.clear();
    }
    
    return true;
}

int main() {
    return 0;
}