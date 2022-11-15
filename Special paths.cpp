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

int specialPath(int n, vector<int> a, vector<vector<int>> edges,int start, int end)
{
    int start1 = 1;
    int end1 = 1000000;
    int ans = -1;
    
    while(start1 <= end1)
    {
        
        vector<int> parent(n+1, -1);
        
        int mid = (start1+end1)/2;
        
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(abs(a[u-1]-a[v-1]) > mid)
            {
                continue;
            }
            
            int s1 = set_find(u, parent);
            int s2 = set_find(v, parent);
            
            if(s1 != s2)
            {
                set_union(u, v, parent);
            }
        }
        
        if(set_find(start, parent) == set_find(end, parent))
        {
            ans = mid;
            end1 = mid-1;
        }
        else
        {
            start1 = mid+1; 
        }
    }
    
    return ans;
}

int main() {
    return 0;
}