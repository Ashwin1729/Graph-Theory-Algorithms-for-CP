#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, list<pair<int, int>>> graph;
        
        for(int i=0; i<flights.size(); i++)
        {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        vector<int> dist(n, INT_MAX);
        set<vector<int>> s;
        int refk = k+1;
        
        dist[src] = 0;
        s.insert({0, src, refk});
        
        while(!s.empty())
        {
            auto it = s.begin();
            vector<int> ref = *it;
            int minDist = ref[0];
            int node = ref[1];
            int stop = ref[2];
            s.erase(it);
            
            if(node == dst)
            {
                return minDist;
            }
            
            if(stop > 0)
            {
                for(auto nbrVec : graph[node])
                {
                    int nbr = nbrVec.first;
                    int cost = nbrVec.second;
                    
                    s.insert({minDist+cost, nbr, stop-1});
                } 
            }
        }
        
        return -1;
    }

int main() {
    return 0;
}