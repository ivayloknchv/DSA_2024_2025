#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

// https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2852/problem

using namespace std;

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, 
         vector<int>& componentsInfo, int curr, int component)
{
    visited.insert(curr);
    componentsInfo[curr]=component;
    
    for(int neighbour : graph[curr])
    {
        if(visited.count(neighbour) == 0)
        {
            dfs(graph, visited, componentsInfo, neighbour, component);
        }
    }
}


void inItGraph(unordered_map<int, unordered_set<int>>& graph, int N, int M)
{
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
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, unordered_set<int>> graph;
    
    int N = 0, M = 0;
    cin>>N>>M;
    
    inItGraph(graph, N, M);
    
    unordered_set<int> visited;
    vector<int> componentsInfo(N+1);
    int currComponent = 1;
    
    
    for(auto& it : graph)
    {
        if(visited.count(it.first)==0)
        {
            dfs(graph, visited, componentsInfo, it.first, currComponent);
            currComponent++;
        }
    }
    
    int Q = 0;
    
    cin>>Q;
    
    while(Q--)
    {
        int u = 0, w = 0;
        cin>>u>>w;
        
        cout<<(componentsInfo[u] == componentsInfo[w])<<' ';
    }
    
    return 0;
}
