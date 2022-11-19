#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;
        
        dist[S] = 0;
        s.insert({0, S});
        
        while(!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int minDist = it->first;
            
            s.erase(it);
            
            for(auto nbrPair : adj[node])
            {
                
                int nbr = nbrPair[0];
                int cost = nbrPair[1];
                
                if(minDist + cost < dist[nbr])
                {
                    auto f = s.find({dist[nbr], nbr});
                    if(f != s.end())
                    {
                        s.erase(f);
                    }
                    
                    dist[nbr] = minDist + cost;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        
        return dist;
    }

int main() {
    return 0;
}