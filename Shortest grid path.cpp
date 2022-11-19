#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 100000));
    set<vector<int>> s;
    dist[0][0] = grid[0][0];
    s.insert({grid[0][0], 0, 0});
    
    while(!s.empty())
    {
        auto it = s.begin();
        vector<int> node = *it;
        int x = node[1];
        int y = node[2];
        int wt = node[0];
        s.erase(it);
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >=0 and nx < n and ny >=0 and ny < n)
            {
                if(wt + grid[nx][ny] < dist[nx][ny])
                {
                    
                    auto f = s.find({dist[nx][ny], nx, ny});
                    if(f != s.end())
                    {
                        s.erase(f);
                    }
                    
                    dist[nx][ny] = wt + grid[nx][ny]; 
                    
                    s.insert({dist[nx][ny], nx, ny});
                }
            }
        }
        
        
    }
    
    return dist[n-1][m-1];
    
}

int main() {
    return 0;
}