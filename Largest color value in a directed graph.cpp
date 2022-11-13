#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        unordered_map<int, list<int>> graph;
        vector<int> indegree(colors.size(), 0);
        
        for(int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        vector<vector<int>> clr(colors.size(), vector<int>(26, 0));
        queue<int> q;
        
        for(int i=0; i<colors.size(); i++)
        {
            if(indegree[i] == 0)
            {
                clr[i][colors[i]-'a'] = 1;
                q.push(i);
            }
        }
        
        int ans = 0, visited = 0;
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            
            int val = *max_element(clr[x].begin(), clr[x].end());
            ans = max(ans, val);
            visited++;
            
            for(auto nbrs : graph[x])
            {
                for(int i=0; i<26; i++)
                {
                    clr[nbrs][i] = max(clr[nbrs][i], clr[x][i]+(i == colors[nbrs] - 'a'));
                }
                indegree[nbrs]--;
                if(indegree[nbrs] == 0)
                {
                    q.push(nbrs);
                }
            }
        }
        
        return visited < colors.size() ? -1 : ans;
        
    }

int main() {
    return 0;
}