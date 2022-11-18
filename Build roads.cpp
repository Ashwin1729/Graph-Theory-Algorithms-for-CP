#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long set_find(long long int x, vector<long long int> &parent)
    {
        if(parent[x] == -1)
        {
            return x;
        }

        return parent[x] = set_find(parent[x], parent);
    }

    void set_union(long long int u, long long int v, vector<long long int> &parent, vector<long long int> &rank)
    {
        int s1 = set_find(u, parent);
        int s2 = set_find(v, parent);

        if(s1 != s2)
        {
            if(rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

long long buildRoads(vector<vector<long long>>Coordinates){
        int n = Coordinates.size();
        vector<vector<long long int>> edges;
        vector<long long int> parent(n, -1);
        vector<long long int> rank(n, 1);
        long long int ans = 0;
        
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                long long int manDist = min(abs(Coordinates[i][0] - Coordinates[j][0]), abs(Coordinates[i][1] - Coordinates[j][1]));
                vector<long long int> ref{manDist, i, j};
                edges.push_back(ref);
            }
        }
        
        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> pq;
        
        for(int i=0; i<edges.size(); i++)
        {
            pq.push(edges[i]);
        }
        // sort(edges.begin(), edges.end());
        int count = 0;
        
        while(!pq.empty())
        {
            vector<long long int> ref = pq.top();
            pq.pop();
            long long int u = ref[1];
            long long int v = ref[2];
            long long int cost = ref[0];

            long long int s1 = set_find(u, parent);
            long long int s2 = set_find(v, parent);

            if(s1 != s2)
            {
                set_union(u, v, parent, rank);
                ans += cost;
                count++;
                if(count == n-1)
                {
                    break;
                }
            } 
        }
        
        return ans;
}

int main() {
    return 0;
}