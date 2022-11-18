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
    
    int mst(int n, vector<vector<int>>& edges, int blockEdge, int preEdge = -1)
    {
        vector<int> parent(n, -1);
        vector<int> rank(n, 1);
        
        int weight = 0;
        
        if(preEdge != -1)
        {
            weight += edges[preEdge][2];
            set_union(edges[preEdge][0], edges[preEdge][1], parent, rank);
        }
        
        for(int i=0; i<edges.size(); i++)
        {
            if(i == blockEdge)
            {
                continue;
            }
            
            if(set_find(edges[i][0], parent) != set_find(edges[i][1], parent))
            {
                 set_union(edges[i][0], edges[i][1], parent, rank);
                 weight += edges[i][2];
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(set_find(0, parent) != set_find(i, parent))
            {
                return INT_MAX;
            }
        }
        
        return weight;
    }
    
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> ans;
        vector<int> critical;
        vector<int> pseudo_critical;

        for(int i=0; i<edges.size(); i++)
        {
            edges[i].push_back(i);
        }
        
        sort(edges.begin(), edges.end(), comparator);
        
        int minSpanTree = mst(n, edges, -1);
        
        for(int i=0; i<edges.size(); i++)
        {
            if(minSpanTree < mst(n, edges, i))
            {
                critical.push_back(edges[i][3]);
            }
            else if(minSpanTree == mst(n, edges, -1, i))
            {
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        
        ans.push_back(critical);
        ans.push_back(pseudo_critical);
        
        return ans;
    }

int main() {
    return 0;
}