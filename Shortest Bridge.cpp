#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    void dfs(int n, int m, vector<vector<int>>& grid, vector<vector<int>> &visited, int x, int y, queue<pair<int, int>> &q)
    {
        visited[x][y] = 1;
        q.push({x, y});
        grid[x][y] = -1;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        for(int k=0; k<4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >=0 and nx < n and ny >=0 and ny < m and !visited[nx][ny] and grid[nx][ny] == 1)
            {
                dfs(n, m, grid, visited, nx, ny, q);
            }
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        bool flag = false;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    flag=true;
                    dfs(n, m, grid, visited, i, j, q);
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        
        int ans = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0; i<size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                int dx[] = {0, 0, 1, -1};
                int dy[] = {1, -1, 0, 0};

                for(int k=0; k<4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >=0 and nx < n and ny >=0 and ny < m and grid[nx][ny] != -1 and !visited[nx][ny])
                    {
                        
                        if(grid[nx][ny] == 1)
                        {
                            return ans;
                        }
                        
                        grid[nx][ny] = -1;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                        
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }

int main() {
    return 0;
}