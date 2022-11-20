#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
     
        if(startFuel == target)
        {
            return 0;
        }
        
        priority_queue<int> pq;
        int ans = 0, prev = 0;
        
        for(auto x : stations)
        {
            int loc = x[0];
            int cap = x[1];
            startFuel -= loc - prev;
            
            while(!pq.empty() and startFuel < 0)
            {
                startFuel += pq.top();
                pq.pop();
                ans++;
            }
            
            if(startFuel < 0)
            {
                return -1;
            }
            
            prev = loc;
            pq.push(cap);
        }
        
        startFuel -= target - prev;
        
        while(!pq.empty() and startFuel < 0)
        {
            startFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        if(startFuel < 0)
        {
            return -1;
        }
        
        return ans;
    }

int main() {
    return 0;
}