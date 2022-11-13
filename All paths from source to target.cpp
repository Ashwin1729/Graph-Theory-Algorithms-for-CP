#include<iostream>
#include<bits/stdc++.h>

using namespace std;
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> &path, int node)
    {
        path.push_back(node);
        
        if(node == graph.size()-1)
        {
            ans.push_back(path);
        }
        
        for(auto nbrs : graph[node])
        {
            dfs(graph, ans, path, nbrs);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(graph, ans, path, 0);
        
        return ans;
    }

int main() {
    return 0;
}