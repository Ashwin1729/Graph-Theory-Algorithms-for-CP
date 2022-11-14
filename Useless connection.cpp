#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int set_find(int x, map<int, int> &parent)
{
    if(parent[x] == 0)
    {
        return x;
    }
    
    return set_find(parent[x], parent);
}

void set_union(int u, int v, map<int, int> &parent)
{
    int s1 = set_find(u, parent);
    int s2 = set_find(v, parent);
    
    if(s1 != s2)
    {
        parent[s2] = s1;
    }
}

vector<int> findUselessConnection(vector<vector<int>> edges) {
        map<int, int> parent;
        vector<vector<int>> ref;
        
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            int s1 = set_find(u, parent);
            int s2 = set_find(v, parent);
            
            set_union(u, v, parent);
            
            if(s1 == s2)
            {
                vector<int> t;
                t.push_back(u);
                t.push_back(v);
                ref.push_back(t);
            }
        }
        
        return ref[ref.size()-1];
}

int main() {
    return 0;
}