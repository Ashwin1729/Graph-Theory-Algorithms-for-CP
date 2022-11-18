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
    
    int calc(int n, vector<vector<int>>& edges, vector<vector<int>> &val, int ch)
    {
        vector<int> parent(n+1, -1);
        vector<int> rank(n+1, 1);
        int count = 0;
        
        priority_queue<vector<int>> pq;
        
        for(int i=0; i<edges.size(); i++)
        {
            if(edges[i][0] != ch)
            {
                pq.push(edges[i]);
            }
        }
        
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
                // ans += cost;
                vector<int> temp{cost, u, v};
                val.push_back(temp);
                count++;
                if(count == n-1)
                {
                    break;
                }
            } 
        }
        
        return count;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> red;
        vector<vector<int>> green;
        
        int alice = calc(n, edges, red, 2);
        if(alice != n-1)
        {
            return -1;
        }
        
        int bob = calc(n, edges, green, 1);
        if(bob != n-1)
        {
            return -1;
        }
        
        set<vector<int>> s;
        for(int i=0; i<red.size(); i++)
        {
            s.insert(red[i]);
        }
        for(int i=0; i<green.size(); i++)
        {
            s.insert(green[i]);
        }
        
        return edges.size() - s.size();
    }

int main() {
    return 0;
}