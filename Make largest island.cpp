#include<iostream>
#include<bits/stdc++.h>

using namespace std;

map<int, int> size;
    
    void dfs(int n, int m, vector<vector<int>>& grid, vector<vector<int>> &visited, int x, int y, int color)
    {
        visited[x][y] = 1;
        grid[x][y] = color;
        size[color]++;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        for(int k=0; k<4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == 1 and !visited[nx][ny])
            {
                dfs(n, m, grid, visited, nx, ny, color);
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int color = 0;
        int fin_ans = 0;
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 and !visited[i][j])
                {
                    color++;
                    dfs(n, m, grid, visited, i, j, color);
                }
            }
        }
        
        for(int i=1; i<=color; i++)
        {
            fin_ans = max(fin_ans, size[i]);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0)
                {
                    set<int> s;
                    int dx[] = {0, 0, 1, -1};
                    int dy[] = {1, -1, 0, 0};

                    for(int k=0; k<4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if(nx >= 0 and nx < n and ny >= 0 and ny < m)
                        {
                            s.insert(grid[nx][ny]);
                        }
                    }
                    
                    int ans = 1;
                    for(auto x : s)
                    {
                        ans += size[x];
                    }
                    
                    fin_ans = max(fin_ans, ans);
                }
            }
        }
        
        return fin_ans;
    }

int main() {
    return 0;
}