#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-11-2021/challenges/discos/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N = 0, M = 0;
    cin>>N>>M;
    
    unordered_map<long long, vector<pair<long long, long long>>> graph;
    
    
    for(long long i = 0; i < M; i++)
    {
        long long x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        
        graph[x].push_back({w, y});
        graph[y].push_back({w, x});
    }
    
    
    long long K = 0;
    cin>>K;
    
    vector<long long> tSet(K);
    
    for(long long i = 0; i < K; i++)
    {
        long long curr = 0;
        cin>>curr;
        tSet[i] = curr;
    }
    
    using pll = pair<long long, long long>;
    vector<long long> dist(N, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<>> pq;
    
    
    for(long long t : tSet)
    {
        dist[t] = 0;
        pq.push({0, t});
        
    }
    
    while(!pq.empty())
    {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if(weight > dist[node])
        {
            continue;
        }
        
        for(auto [w, neigh] : graph[node])
        {
            long long currDist = w + weight;
            
            if(currDist < dist[neigh])
            {
                dist[neigh] = currDist;
                pq.push({currDist, neigh});
            }
        }
    } 
    
    
    long long Q = 0;
    cin>>Q;
    
    for(long long i = 0; i < Q; i++)
    {
        long long curr = 0;
        cin>>curr;
        
        cout<<dist[curr]<<'\n';
    }
    return 0;
}
