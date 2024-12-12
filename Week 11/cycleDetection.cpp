#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


// https://www.hackerrank.com/contests/sda-homework-10/challenges/-1-12/problem

using namespace std;

unordered_map<int, unordered_set<int>> graph;

bool cycleHelper(unordered_map<int, unordered_set<int>>& graph,  unordered_set<int>& visited, 
                 unordered_set<int>& path, int curr)
{  
    visited.insert(curr);
    path.insert(curr);
    
    for(int neighbor : graph[curr])
    {     
        
        if (path.find(neighbor) != path.end())
        {
            return true;
        }

        if (visited.find(neighbor) != visited.end())
        {
            continue;
        }

        
        if(cycleHelper(graph, visited, path, neighbor))
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
    
    for (const auto& it : graph)
    {    
        if(visited.find(it.first)==visited.end() && cycleHelper(graph, visited, path, it.first))
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
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        int V = 0, E = 0;
        cin>>V>>E;
        
        
        for(int i = 1; i <= V; i++)
        {
            graph[i];
        }
        
        for(int j = 0; j < E; j++)
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
        graph.clear();
    }
    return 0;
}
