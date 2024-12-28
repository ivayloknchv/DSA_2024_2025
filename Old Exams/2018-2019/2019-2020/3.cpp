#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr)
{
    visited.insert(curr);
    
    for(int neigh : graph[curr])
    {
        if(visited.count(neigh)==0)
        {
            dfs(graph, visited, neigh);
        }
    }
}

int countDistricts(unordered_map<int, unordered_set<int>>& graph)
{
    int counter = 0;
    unordered_set<int> visited;
    
    for(auto& it : graph)
    {
        if(visited.count(it.first)==0)
        {
            dfs(graph, visited, it.first);
            counter++;
        }
    }
    
    return counter;
}

int main() 
{
    unordered_map<int, unordered_set<int>> graph;
    
    int T = 0;
    cin>>T;
    
    while(T--)
    {
        int X = 0, Y = 0;
        cin>>X>>Y;
        
        for(int i = 0; i < X; i++)
        {
            graph[i];
        }
        
        for(int i = 0; i < Y; i++)
        {
            int u = 0, v = 0;
            cin>>u>>v;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        cout<<countDistricts(graph)<<' ';
        graph.clear();
    }
    
    return 0;
}
