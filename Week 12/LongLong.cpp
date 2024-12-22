#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-11/challenges/long-long/problem

struct Edge
{
    long long from = 0;
    long long  to = 0;
    long long  weight = 0;
};


int main() 
{
    long long  N = 0, M = 0, S = 0, T = 0;
    cin>>N>>M>>S>>T;
    
    vector<Edge> graph;
    
    for(long long  i = 0; i < M; i++)
    {
        long long  x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        graph.push_back({x, y, w});
    }
    
    vector<long long > maxDist(N+1, LLONG_MIN);
    maxDist[S]=0;
    
    for(long long  i = 0; i < N -1; i++)
    {
        for(auto& e : graph)
        {
            if(maxDist[e.from]!=LLONG_MIN && maxDist[e.to] < maxDist[e.from] + e.weight)
            {
                 maxDist[e.to] = maxDist[e.from] + e.weight;
            }
        }
    }
    
    if(maxDist[T]==LLONG_MIN)
    {
        cout<<-1;
    }
    else
    {
        cout<<maxDist[T];
    }
    return 0;
}
