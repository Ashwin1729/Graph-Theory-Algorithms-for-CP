#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i != j)
                {
                    dist[i][j] = 1000000;
                }
            }
        }
        
        for(int i=0; i<edges.size(); i++)
        {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        for(int k = 0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        map<int, vector<int>> mp;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    mp[i].push_back(j);
                }
            }
        }
        
        int ref;
        int mini = INT_MAX;
        
        for(auto x : mp)
        {
            if(x.second.size() <= mini)
            {
                mini = x.second.size();
                ref = x.first;
            }
        }
        
        return ref;
    }

int main() {
    return 0;
}