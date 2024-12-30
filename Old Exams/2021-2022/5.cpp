#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int curr, unordered_map<int, int>& sums)
{
    visited.insert(curr);
    
    for(int neigh : graph[curr])
    {
        sums[curr] += neigh;
        if(!visited.count(neigh))
        {
            dfs(graph, visited, neigh, sums);
        }                   
        sums[curr] += sums[neigh];
    }
}

int main() {
    unordered_map<int, vector<int>> graph;
    int N = 0, M = 0;
    cin>>N>>M;
    
    
    for(int i = 0; i < N; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        graph[x].push_back(y);
    }
     
    unordered_map<int, int> sums;
    unordered_set<int> visited;
    
    for(int i = 0; i < M; i++)
    {
        int q = 0;
        cin>>q;
        
        if(!visited.count(q))
        {
            dfs(graph, visited, q, sums);
        }
        cout<<sums[q]<<'\n';
    }
    return 0;
}
