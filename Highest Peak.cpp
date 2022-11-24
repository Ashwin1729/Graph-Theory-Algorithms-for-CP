#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int n = isWater.size();
        int m = isWater[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        int height = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(isWater[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                isWater[x][y] = height;
                
                int dx[] = {0, 1, 0, -1};
                int dy[] = {1, 0, -1, 0};
                
                for(int t=0; t<4; t++)
                {
                    int nx = x + dx[t];
                    int ny = y + dy[t];
                    
                    if(nx >= 0 and nx < n and ny >= 0 and ny < m and !visited[nx][ny] and isWater[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
            height++;
        }
        
        return isWater;
    }

int main() {
    return 0;
}