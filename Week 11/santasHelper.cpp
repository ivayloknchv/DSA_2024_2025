#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://www.hackerrank.com/contests/5-2023-2024/challenges/challenge-4506/problem

void dfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& componentsInfo, vector<bool>& visited,
        int currNode, int currComponent)
{
    visited[currNode] = true;
    componentsInfo[currNode] = currComponent;
    
    for(int neighbour : graph[currNode])
    {
        if(!visited[neighbour])
        {
            dfs(graph, componentsInfo, visited, neighbour, currComponent);
        }
    }
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    unordered_map<int, unordered_set<int>> graph;
    
    int N = 0, M = 0;
    cin>>N>>M;
    
    for(int i = 1; i <= N; i++)
    {
        graph[i];
    }
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    
    
    vector<int> componentsInfo(N+1, 0);
    vector<bool> visited(N+1, false);
    
    int currComp = 0;
    
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            dfs(graph, componentsInfo, visited, i, currComp);
            currComp++;
        }
    }
    
    int Q = 0;
    cin>>Q;
    
    for(int i = 0; i < Q; i++)
    {
        int u = 0, w = 0;
        cin>>u>>w;
        
        cout<<(componentsInfo[u] == componentsInfo[w])<<' ';
    }
    return 0;
}
