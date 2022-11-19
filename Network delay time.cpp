#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        
        unordered_map<int, list<pair<int, int>>> graph;
        
        for(int i=0; i<times.size(); i++)
        {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int> dist(n+1, INT_MAX);
        set<pair<int, int>> s;
        int ans = 0;
        
        dist[k] = 0;
        s.insert({0, k});
        
        while(!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int minDist = it->first;
            s.erase(it);
            
            for(auto nbrPair : graph[node])
            {
                int nbr = nbrPair.first;
                int cost = nbrPair.second;
                
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
        
        for(int i=1; i<dist.size(); i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
        }
        
        ans = *max_element(dist.begin()+1, dist.end());
        
        return ans;
    }

int main() {
    return 0;
}