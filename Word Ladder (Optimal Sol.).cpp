#include<iostream>
#include<bits/stdc++.h>

using namespace std;

        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        int cost = 1;
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i=0; i<n; i++)
            {
                string t = q.front();
                q.pop();
                
                if(t == endWord)
                {
                    return cost;
                }
                words.erase(t);
                for(int j=0; j<t.size(); j++)
                {
                    char c = t[j];
                    
                    for(int k=0; k<26; k++)
                    {
                        t[j] = 'a' + k;
                        
                        if(words.find(t) != words.end())
                        {
                            q.push(t);
                        }
                    }
                    
                    t[j] = c;
                }
            }
            cost++;
        }
        
        return 0;
    }

int main() {
        return 0;
}