#include <bits/stdc++.h>
using namespace std;

bool hasCycleHelper(unordered_map<int, unordered_set<int>>& graph, int curr, unordered_set<int>& visited, unordered_set<int>& path)
{
    visited.insert(curr);
    path.insert(curr);
    
    for(int neigh : graph[curr])
    {
        if(path.count(neigh))
        {
            return true;
        }
        
        
        if(visited.count(neigh))
        {
            continue;
        }
        
        if(hasCycleHelper(graph, neigh, visited, path))
        {
            return true;
        }
    }
    path.erase(curr);
    return false;
}

bool hasCycle(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    unordered_set<int> path;

    for(auto& it : graph)
    {
        if(!visited.count(it.first) && hasCycleHelper(graph, it.first, visited, path))
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N = 0;
    cin>>N;
    
    while(N--)
    {
        int V = 0, E = 0;
        cin>>V>>E;
        unordered_map<int, unordered_set<int>> graph;
        for(int i = 1; i <= V; i++)
        {
            graph[i];
        }
        
        for(int i = 0; i < E; i++)
        {
            int x = 0, y = 0, w = 0;
            cin>>x>>y>>w;
            
            graph[x].insert(y);
        }
        
        if(hasCycle(graph))
        {
            cout<<"true ";
        }
        else
        {
            cout<<"false ";
        }
    }
    return 0;
}
