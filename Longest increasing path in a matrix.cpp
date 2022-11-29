#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& matrix, vector<vector<int>> &dp, int i, int j, int n, int m)
    {
        if(dp[i][j])
        {
            return dp[i][j];
        }
        
        dp[i][j] = 1;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int t=0; t<4; t++)
        {
            int nx = i + dx[t];
            int ny = j + dy[t];
            
            if(nx >= 0 and nx<n and ny >= 0 and ny<m and matrix[nx][ny] > matrix[i][j])
            {
                dp[i][j] = max(dp[i][j], 1+solve(matrix, dp, nx, ny, n, m));
            }
        }
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxPath = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                maxPath = max(maxPath, solve(matrix, dp, i, j, n, m));
            }
        }
        
        return maxPath;
    }

int main() {
    return 0;
}