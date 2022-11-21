#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int n, int m, vector<vector<int>>& image, vector<vector<int>> &visited, int x, int y, int &color, int initColor)
    {
        visited[x][y] = 1;
        image[x][y] = color;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        for(int k=0; k<4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 and nx < n and ny >= 0 and ny < m and image[nx][ny] == initColor and !visited[nx][ny])
            {
                dfs(n, m, image, visited, nx, ny, color, initColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int initColor = image[sr][sc];
        
        dfs(n, m, image, visited, sr, sc, color, initColor);
        
        return image;
    }

int main() {
    return 0;
}