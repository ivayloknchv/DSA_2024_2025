#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void dfs(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited,
         vector<int>& components, int curr, int componentsCounter)
{
    visited[curr]=true;
    components[curr]=componentsCounter;
    
    for(int neigh : graph[curr])
    {
        if(!visited[neigh])
        {
            dfs(graph, visited, components, neigh, componentsCounter);
        }
    }
}

int main() 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0, M = 0;
    cin>>N>>M;
    
    unordered_map<int, unordered_set<int>> graph;
    
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
    
    vector<int> components(N+1);
    int componentsCounter = 1;
    vector<bool> visited(N+1);
    
    for(auto& it: graph)
    {
        if(!visited[it.first])
        {
            dfs(graph, visited, components, it.first, componentsCounter);
            componentsCounter++;
        }
    }
    
    int Q = 0;
    cin>>Q;
    
    while(Q--)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        
        cout<<(components[x]==components[y])<<' ';
    }
    return 0;
}
