#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
        {
            return {};
        }
        if(n==1)
        {
            return {0};
        }
        
        unordered_map<int, list<int>> graph;
        vector<int> degree(n, 0);
        queue<int> q;
        vector<int> ans;
        
        for(int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(degree[i] == 1)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            ans.clear();
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                
                for(auto x : graph[node])
                {
                    degree[x]--;
                    if(degree[x] == 1)
                    {
                        q.push(x);
                    }
                }
            }
        }
        
        return ans;
    }

int main() {
    return 0;
}