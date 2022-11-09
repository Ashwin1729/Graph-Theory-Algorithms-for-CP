#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    void dfs(int node, unordered_map<int, vector<int>> graph, bool* visited)
    {
        visited[node] = true;

        for(auto nbrs : graph[node])
        {
            if(!visited[nbrs])
            {
                dfs(nbrs, graph, visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       unordered_map<int, vector<int>> graph;
       bool *visited = new bool[rooms.size()]{false};

       for(int i=0; i<rooms.size(); i++)
       {
           graph[i] = rooms[i];
       }

       dfs(0, graph, visited);

       bool ans = true;

       for(int i=0; i<rooms.size(); i++)
       {
           if(!visited[i])
           {
               ans = false;
               break;
           }
       }

       return ans;
    }

int main() {
    return 0;
}