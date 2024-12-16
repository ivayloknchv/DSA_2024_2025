#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://www.hackerrank.com/contests/sda-test5-2022-2023-43wdst52/challenges/challenge-1761/problem

int dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr, int& res)
{
    if(!graph[curr].size())
    {
        return 1;
    }
    
    visited.insert(curr);
    int childrenNodes = 1;
    
    for(int neighbour : graph[curr])
    {
        if(visited.count(neighbour) == 0)
        {
            childrenNodes += dfs(graph, visited, neighbour, res);
        }
    }
    
    if(childrenNodes % 2 == 0)
    {
        res++;
        return 0;
    }
    
    return childrenNodes;
}

int main() 
{
    int V = 0, E = 0;
    cin>>V>>E;
    
    unordered_map<int, unordered_set<int>>graph;
    
    for(int i = 1; i <= V; i++)
    {
        graph[i];
    }
    
    for(int i = 0; i < E; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        
        graph[x].insert(y);
        graph[y].insert(x);
    }
    
    unordered_set<int> visited;
    int res = 0;
    dfs(graph, visited, 1, res);
    cout<<res-1;
}
