#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2351/problem

unordered_map<int, unordered_set<int>> graph;


void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr)
{
    visited.insert(curr);
    
    for(int neighbour : graph[curr])
    {
        if(visited.count(neighbour)==0)
        {
            dfs(graph, visited, neighbour);
        }
    }
}

int countDistricts(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    int counter = 0;
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

int process(unordered_map<int, unordered_set<int>>& graph)
{
    int V = 0, E = 0;
    cin>>V>>E;
    
    for(int i = 0; i < V; i++)
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
    
    int ans = countDistricts(graph);
    graph.clear();
    
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q = 0;
    cin>>Q;
    
    while(Q--)
    {
        cout<<process(graph)<<' ';
    }
    return 0;
}
