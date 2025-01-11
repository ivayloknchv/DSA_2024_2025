#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-test6-2022-2023-iythgbeu3/challenges/challenge-3826/problem

int main() 
{
    int N = 0, M = 0;
    cin>>N>>M;
    
    vector<vector<int>> adj(N, vector<int>(N, INT_MAX));
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        
        adj[x][y] = w;
        adj[y][x] = w;
    }
    
    int K = 0;
    cin>>K;
    
    vector<int> path(K);
    
    for(int i = 0; i < K; i++)
    {
        cin>>path[i];
    }
    
    int sum = 0;
    for(int i = 1; i < K; i++)
    {
        if(adj[path[i]][path[i-1]] != INT_MAX)
        {
            sum+=adj[path[i]][path[i-1]];
        }
        else
        {
            cout<<-1;
            return 0;
        }
    }
    
    cout<<sum;
    
    return 0;
}
