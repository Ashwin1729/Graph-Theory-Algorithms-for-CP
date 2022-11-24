#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    bool isValid(int x, int y, int row, int col)
    {
        if(x < 0 || y < 0 || x >= row || y >= col)
        {
            return false;
        }
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        int ans = -1;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        
        if(q.empty() and fresh == 0)
        {
            return 0;
        }
        
        while(!q.empty())
        {
            int size = q.size();
            ans++;
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
                    
                    if(isValid(nx, ny, row, col) and grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        if(!fresh)
        {
            return ans;
        }
        
        return -1;
    }

int main() {
    return 0;
}