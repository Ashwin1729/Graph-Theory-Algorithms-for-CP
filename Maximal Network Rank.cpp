#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, list<int>> ref;
        vector<vector<int>> vec(n, vector<int> (n, 0));
        int ans = 0;
        
        for(int i=0; i<roads.size(); i++)
        {
            ref[roads[i][0]].push_back(roads[i][1]);
            ref[roads[i][1]].push_back(roads[i][0]);
            vec[roads[i][0]][roads[i][1]] = 1;
            vec[roads[i][1]][roads[i][0]] = 1;
        }
        
        for(int i=0; i<=n-2; i++)
        {
            for(int j=i+1; j<=n-1; j++)
            {
                int lcount = 0;
                if(vec[i][j])
                {
                    lcount += ref[i].size() + ref[j].size() - 1;
                }
                else
                {
                    lcount += ref[i].size() + ref[j].size();
                }
                                     
                if(lcount > ans)
                {
                    ans = lcount;
                }
            }
        }
                             
        return ans;
    }

int main() {
    return 0;
}