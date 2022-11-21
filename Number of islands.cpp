#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int n, int m, vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y)
    {
        visited[x][y] = 1;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        for(int k=0; k<4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == '1' and !visited[nx][ny])
            {
                dfs(n, m, grid, visited, nx, ny);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' and !visited[i][j])
                {
                    dfs(n, m, grid, visited, i, j);
                    ans++;
                }
            }
        }
        
        return ans;
    }

int main() {
    return 0;
}