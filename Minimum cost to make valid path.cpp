#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, vector<vector<int>> &dist, queue<pair<int, int>> &q, int &cost, int x, int y)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] = 1;
        dist[x][y] = cost;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        q.push({x, y});
        
        int nextDir = grid[x][y]-1;
        int nx = x + dx[nextDir];
        int ny = y + dy[nextDir];
        
        if(nx >= 0 and nx < n and ny >= 0 and ny < m and !visited[nx][ny])
        {
            dfs(grid, visited, dist, q, cost, nx, ny);
        }
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cost = 0;
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 100000));
        
        dfs(grid, visited, dist, q, cost, 0, 0);
        
        while(!q.empty())
        {
            cost++;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                int dx[] = {0, 0, 1, -1};
                int dy[] = {1, -1, 0, 0};
                
                for(int t=0; t<4; t++)
                {
                    int nx = x + dx[t];
                    int ny = y + dy[t];
                    
                    if(nx >= 0 and nx < n and ny >= 0 and ny < m and !visited[nx][ny])
                    {
                        dfs(grid, visited, dist, q, cost, nx, ny);
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }

int main() {
    return 0;
}