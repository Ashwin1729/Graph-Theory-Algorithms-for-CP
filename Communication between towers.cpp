#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int r, int c)
{
    visited[i][j] = true;
    
    for(int k=1; k<r; k++)
    {
        int p = (i+k)%r;
        int q = j;
        
        if(matrix[p][q] == 1 and !visited[p][q])
        {
            dfs(matrix, visited, p, q, r, c);
        }
    }
    
    for(int k=1; k<c; k++)
    {
        int p = i;
        int q = (j+k)%c;
        
        if(matrix[p][q] == 1 and !visited[p][q])
        {
            dfs(matrix, visited, p, q, r, c);
        }
    }
}

int solve(vector<vector<int>> matrix) {
    
    int r = matrix.size();
    int c = matrix[0].size();
    int count= 0;
    
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(matrix[i][j] == 1 and !visited[i][j])
            {
                dfs(matrix, visited, i, j, r, c);
                count++;
            }
        }
    }
    return count;
}

int main() {
    return 0;
}