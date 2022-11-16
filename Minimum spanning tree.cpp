#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        int ans = 0;
        
        while(!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node])
            {
                continue;
            }
            
            ans += weight;
            vis[node] = 1;
            
            for(auto x : adj[node])
            {
                if(!vis[x[0]])
                {
                    pq.push({x[1] ,x[0]});
                }
            }
        }
        
        return ans;
    }

int main() {
    return 0;
}