#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int n = 1e5+10;

int set_find(int x, vector<int> &parent)
{
    if(parent[x] == -1)
    {
        return x;
    }
    
    return set_find(parent[x], parent);
}

void set_union(int u, int v, vector<int> &parent)
{
    int s1 = set_find(u, parent);
    int s2 = set_find(v, parent);
    
    if(s1 != s2)
    {
        parent[s2] = s1;
    }
}

bool solve(vector<vector<int>> edges) {
    
    vector<int> parent(n, -1);
    // map<int, int> parent;
    
    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        
        int s1 = set_find(u, parent);
        int s2 = set_find(v, parent);
        
        if(s1 != s2)
        {
            set_union(u, v, parent);
        }
        else
        {
            return false;
        }
    }
    
    return true;
    
}

int main() {
    return 0;
}