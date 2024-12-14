#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// https://www.hackerrank.com/contests/sda-2020-2021-test9-wefnkcsdw/challenges/challenge-2762/problem

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr, int& nodesCount)
{
    visited.insert(curr);
    nodesCount++;
    
    for(auto& neighbour : graph[curr])
    {
        if(visited.count(neighbour) == 0)
        {
            dfs(graph, visited, neighbour, nodesCount);
        }
    }
}

int componentsCount(unordered_map<int, unordered_set<int>>& graph, int M)
{
    unordered_set<int> visited;
    int components = 0;
    
    for(int i = 0; i < M; i++)
    {
        if(visited.count(i)==0)
        {
            int nodesCount = 0;
            dfs(graph, visited, i, nodesCount);
            
            if(nodesCount>1)
            {
                components++;
            }
        }
    }
    
    return components;
}

int main() 
{
    unordered_map<int, unordered_set<int>> graph;
    
    int M = 0, N = 0;
    cin>>M>>N;
    
    for(int i = 0; i < M; i++)
    {
        graph[i];
    }
    
    for(int i = 0; i < N; i++)
    {
        int u = 0, v = 0;
        cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    
    cout<<componentsCount(graph, M);
    return 0;
}
