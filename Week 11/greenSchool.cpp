#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// https://www.hackerrank.com/contests/sda-2019-2020-test-5/challenges/challenge-2299/problem

int main() 
{
    int N = 0, M = 0, K = 0;
    cin>>N>>M>>K;
    int startIdx = 0;
    
    unordered_map<int, unordered_set<int>> graph;
    
    for(int i = 0; i < M; i++)
    {
        int u = 0, w = 0;
        cin>>u>>w;
        
        graph[u].insert(w);
        graph[w].insert(u);
        
        startIdx = max(startIdx, u);
        startIdx = max(startIdx, w);
    }
    
    unordered_set<int> visited;
    queue<int> q;
    set<int> kDist;
    q.push(startIdx);
    visited.insert(startIdx);
    int currDist = 0;
    
    while(!q.empty())
    {
        if(currDist == K)
        {
            while(q.size())
            {
                kDist.insert(q.front());
                q.pop();
            }
            break;
        }
        
        
        int s = q.size();
        
        for(int i = 0; i < s; i++)
        {
            int currVertex = q.front();
            q.pop();
            
            for(int neighbour : graph[currVertex])
            {
                if(visited.find(neighbour)==visited.end())
                {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        currDist++;
    }
    
    for(auto& it : kDist)
    {
        cout<<it<<' ';
    }
    
    if(!kDist.size())
    {
        cout<<-1;
    }
    return 0;
}
