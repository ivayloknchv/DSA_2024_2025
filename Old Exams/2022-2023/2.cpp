#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int& nodes, int curr)
{
    visited[curr]=true;
    nodes++;
    
    for(int neigh : graph[curr])
    {
        if(!visited[neigh])
        {
            dfs(graph, visited, nodes, neigh);
        }
    }
}


int main() 
{
    unordered_map<int, vector<int>> graph;
    
    int n = 0, e = 0, k = 0;
    cin>>n>>e>>k;
    
    for(int i = 0; i < n; i++)
    {
        graph[i];
    }
    
    
    for(int i = 0; i < e; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    
    int counter = 0;
    
    vector<bool> visited(n);
    
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            int nodes = 0;
            dfs(graph, visited, nodes, i);
            
            if(nodes%k==0)
            {
                counter++;
            }
        }
    }
    
    
    cout<<counter;
    
    return 0;
}
