#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        
        vector<int> cnt(n+1), sorted_cnt(n+1), res;
        vector<unordered_map<int, int>> shared(n+1);
        
        for(int i=0; i<edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            sorted_cnt[x] = cnt[x] = cnt[x]+1;
            sorted_cnt[y] = cnt[y] = cnt[y]+1;
            
            shared[min(x, y)][max(x, y)]++;
        }
        
        sort(sorted_cnt.begin(), sorted_cnt.end());
        
        for(auto querie : queries)
        {
            res.push_back(0);
            for(int i=1, j=n; i<j;)
            {
                if((sorted_cnt[i]+sorted_cnt[j]) > querie)
                {
                    res.back() += (j - i);
                    j--;
                }
                else
                {
                    i++;
                }
            }

            for(int i=1; i<=n; i++)
            {
                for(auto x : shared[i])
                {
                    int j = x.first;
                    int num = x.second;
                    if((cnt[i]+cnt[j]) > querie and (cnt[i]+cnt[j]) <= (querie+num))
                    {
                        res.back()--;
                    }
                }
            }
        }
        
        return res;
    }

int main() {
    return 0;
}