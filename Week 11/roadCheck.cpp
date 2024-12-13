#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// https://www.hackerrank.com/contests/sda-2019-2020-exam-2e3nr4rr/challenges/challenge-2353/problem

int main() 
{
    
    
    int N = 0;
    int M = 0;
    
    cin>>N>>M;
    
    vector<vector<int>> graph(N, vector<int>(N, -1));
    
    for(int i = 0; i < M; i++)
    {
        int u = 0, v = 0, w = 0;
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    
    int K = 0;
    cin>>K;
    
    int from = 0, to = 0;
    cin >> from;
    
    int sum = 0;
    
    for(int i = 0; i < K-1; i++)
    {
        cin>>to;
        
        if(graph[from][to]!=-1)
        {
            sum+=graph[from][to];
        }
        else
        {
            cout<<-1;
            return 0;
        }
        
        from=to;
        
    }
    
    cout<<sum; 
    
    return 0;
}
