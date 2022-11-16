#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int set_find(int x, vector<int> &parent)
    {
        if(parent[x] == -1)
        {
            return x;
        }

        return parent[x] = set_find(parent[x], parent);
    }

    void set_union(int u, int v, vector<int> &parent, vector<int> &rank)
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
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<int>> edges;
        vector<int> parent(n, -1);
        vector<int> rank(n, 1);
        int ans = 0;
        
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int manDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vector<int> ref{manDist, i, j};
                edges.push_back(ref);
            }
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for(int i=0; i<edges.size(); i++)
        {
            pq.push(edges[i]);
        }
        // sort(edges.begin(), edges.end());
        int count = 0;
        
        while(!pq.empty())
        {
            vector<int> ref = pq.top();
            pq.pop();
            int u = ref[1];
            int v = ref[2];
            int cost = ref[0];

            int s1 = set_find(u, parent);
            int s2 = set_find(v, parent);

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