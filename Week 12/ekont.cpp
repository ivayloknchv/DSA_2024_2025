#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

// https://www.hackerrank.com/contests/test6sda-renfuvidbviw/challenges/challenge-2326/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    using pii = pair<int, int>;
    
    int N = 0, M = 0;
    cin>>N>>M;
    
    unordered_map<int, vector<pii>> graph; 
    
    for(int i = 1; i <= N; i++)
    {
        graph[i];
    }
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        graph[x].push_back({w, y});
        graph[y].push_back({w, x});
    }
    
    int S = 0;
    cin>>S;
    
    vector<int> dist(N+1, INT_MAX);
    dist[S] = 0;
    
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, S});
    
    while(!pq.empty())
    {
        auto [weight, curr] = pq.top();
        pq.pop();
        
        if(weight > dist[curr])
        {
            continue;
        }
        
        for(auto [w, n] : graph[curr])
        {
            if(w+weight < dist[n])
            {
                dist[n] = w + weight;
                pq.push({w+weight, n});
            }
        }
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(i==S)
        {
            continue;
        }
        if(dist[i]==INT_MAX)
        {
            cout<<-1<<' ';
            continue;
        }
        cout<<dist[i]<<' ';
    }
    
    return 0;
}
