#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    bool isOne(string str1, string str2)
    {
        int count = 0;
        
        for(int i=0; i<str1.size(); i++)
        {
            if(str1[i] != str2[i])
            {
                count++;
            }
        }
        
        if(count == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, list<string>> graph;
        
        for(int i=0; i<wordList.size(); i++)
        {
            if(isOne(beginWord, wordList[i]))
            {
                graph[beginWord].push_back(wordList[i]);
                graph[wordList[i]].push_back(beginWord);
            }
        }
        
        for(int i=0; i<wordList.size()-1; i++)
        {
            for(int j=i+1; j<wordList.size(); j++)
            {
                if(isOne(wordList[i], wordList[j]))
                {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        queue<string> q;
        unordered_map<string, bool> visited;
        unordered_map<string, int> dist;
        
        visited[beginWord] = false;
        dist[beginWord] = 0;
        visited[endWord] = false;
        dist[endWord] = 0;
        
        for(int i=0; i<wordList.size(); i++)
        {
            visited[wordList[i]] = false;
            dist[wordList[i]] = 0;
        }
        
        q.push(beginWord);
        visited[beginWord] = true;
        dist[beginWord] = 0;
        
        while(!q.empty())
        {
            string t = q.front();
            q.pop();
            
            for(auto nbrs : graph[t])
            {
                if(!visited[nbrs])
                {
                    q.push(nbrs);
                    visited[nbrs] = true;
                    dist[nbrs] = dist[t] + 1;
                }
            }
        }
        
        if(!visited[endWord])
        {
            return 0;
        }
        else
        {
            return dist[endWord] + 1;
        }     
    }

    int main() {
        return 0;
    }