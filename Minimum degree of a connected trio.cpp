#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<set<int>> graph(n+1);
        vector<int> cnt(n+1);
        
        int result = INT_MAX;
        
        for(auto x : edges)
        {
            graph[min(x[0], x[1])].insert(max(x[0], x[1]));
            cnt[x[0]]++;
            cnt[x[1]]++;
        }
        
        for(int t = 1; t<=n; t++)
        {
            for(auto it1 = graph[t].begin(); it1 != graph[t].end(); it1++)
            {
                for(auto it2 = next(it1, 1); it2 != graph[t].end(); it2++)
                {
                    if(graph[*it1].count(*it2))
                    {
                        result = min(result, cnt[*it1]+cnt[*it2]+cnt[t] - 6);
                    }
                }
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }

int main() {
    return 0;
}