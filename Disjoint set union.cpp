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

void set_unite(int u, int v, map<int, int> &parent)
{
    int s1 = set_find(u, parent);
    int s2 = set_find(v, parent);
    
    if(s1 != s2)
    {
        parent[s2] = s1;
    }
}

vector<bool> DSU(vector<vector<int>>query)
{
    map<int, int> parent;
    vector<bool> ans;
    
    for(int i=0; i<query.size(); i++)
    {
        int x = query[i][0];
        int u = query[i][1];
        int v = query[i][2];
        
        if(x == 2)
        {
            int s1 = set_find(u, parent);
            int s2 = set_find(v, parent);
            
            ans.push_back(s1 == s2);
        }
        else if(x == 1)
        {
            set_unite(u, v, parent);
        }
    }
    
    return ans;
}

int main() {
    return 0;
}