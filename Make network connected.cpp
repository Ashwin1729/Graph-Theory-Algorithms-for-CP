#include<iostream>
#include<bits/stdc++.h>

using namespace std;

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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> parent(n, -1);
        int compCount = 0;
        int cycleCount = 0;
        
        for(int i=0; i<connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            
            int s1 = set_find(u, parent);
            int s2 = set_find(v, parent);
            
            if(s1 != s2)
            {
                set_union(u, v, parent);
            }
            else
            {
                cycleCount++;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(parent[i] == -1)
            {
                compCount++;
            }
        }
        
        if(compCount-1 > cycleCount)
        {
            return -1;
        }
        else if(compCount-1 < cycleCount)
        {
            return compCount-1;
        }
        else
        {
            return cycleCount;
        }
    }

int main() {
    return 0;
}