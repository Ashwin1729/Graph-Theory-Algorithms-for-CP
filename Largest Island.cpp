#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int r, int c)
    {
       visited[i][j] = true;
       
       int cost = 1;
       
       int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
       int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
       
       for(int k=0; k<8; k++)
       {
           int nx = i + dx[k];
           int ny = j + dy[k];
           
           if(nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] == 1 and !visited[nx][ny])
           {
               cost += dfs(grid, visited, nx, ny, r, c);
           }
       }
       
       return cost;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 1 and !visited[i][j])
                {
                    int area = dfs(grid, visited, i, j, r, c);
                    if(area > ans)
                    {
                        ans = area;
                    }
                }
                
            }
        }
        
        return ans;
    }

int main() {
    return 0;
}