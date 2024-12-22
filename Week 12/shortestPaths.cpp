#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/contests/6-20232024/challenges/shortest-paths-2/problem

const long long MOD = (long long)(1e9+7);

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    using pll = pair<long long, long long>;
    
    long long N = 0, M = 0;
    cin>>N>>M;
    vector<vector<pll>> graph(N+1);
    
    for(int i = 0; i < M; i++)
    {
        long long x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        
        graph[x].push_back({y, w});
    }
    
    vector<long long> dist(N+1, LLONG_MAX);
    vector<long long> paths(N+1);
    
    dist[1]=0;
    paths[1]=1;
    
    priority_queue<pll, vector<pll>, greater<>> pq;
    
    pq.push({0,1});
    
    while(!pq.empty())
    {
        auto [w, n] = pq.top();
        pq.pop();
        
        if(dist[n] < w)
        {
            continue;
        }
        
        for(auto& [neigh, weight] : graph[n])
        {
            if(dist[neigh] > w + weight)
            {
                paths[neigh] = paths[n];
                dist[neigh] = w + weight;
                pq.push({w + weight, neigh});
            }
            else if(dist[neigh] == w + weight)
            {
                paths[neigh] = (paths[n] + paths[neigh]) % MOD;
            }
        }
    }
    
    if(dist[N]==LLONG_MAX)
    {
        cout<<-1<<' '<<0;
        return 0;
    }
    
    cout<<dist[N]<<' '<<paths[N];
    return 0;
}
