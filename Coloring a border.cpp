#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int n, int m, vector<vector<int>>& grid, vector<vector<int>> &visited, int x, int y, int &initColor, int color)
    {
        visited[x][y] = 1;
        if(x == n-1 || y == m-1 || x == 0 || y == 0)
        {
            grid[x][y] = -grid[x][y];
        }
        else if(x > 0 and x < n-1 and y > 0 and y < m-1)
        {
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            int flag = false;
            for(int t=0; t<4; t++)
            {
                int tx = x + dx[t];
                int ty = y + dy[t];
                
                if(grid[tx][ty] != grid[x][y] and grid[tx][ty] != -grid[x][y])
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag)
            {
                grid[x][y] = -grid[x][y];
            }
        }
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        for(int k=0; k<4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == initColor and !visited[nx][ny])
            {
                dfs(n, m, grid, visited, nx, ny, initColor, color);
            }
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int initColor = grid[row][col];
        
        dfs(n, m, grid, visited, row, col, initColor, color);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] < 0)
                {
                    grid[i][j] = color;
                }
            }
        }
        
        return grid;
    }

int main() {
    return 0;
}