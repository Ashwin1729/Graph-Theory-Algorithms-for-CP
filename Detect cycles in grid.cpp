#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int pi, int pj, int i, int j, int r, int c)
    {
        visited[i][j] = true;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int k=0; k<4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] == grid[i][j])
            {
                if(!visited[nx][ny])
                {
                    int cycle = dfs(grid, visited, i, j, nx, ny, r, c);
                    if(cycle)
                    {
                        return true;
                    }
                }
                else if(!(nx == pi and ny == pj))
                {
                    return true;
                }
            }
        }
     return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int ans = false;
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(!visited[i][j])
                {
                    ans = ans | dfs(grid, visited, -1, -1, i, j, r, c);
                }
            }
        }
        return ans;
    }

int main() {
    return 0;
}