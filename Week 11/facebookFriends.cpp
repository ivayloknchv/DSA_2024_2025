#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// https://www.hackerrank.com/contests/sda-exam-20222023-part-1/challenges/challenge-3904/problem

void dfs(vector<unordered_set<int>>& graph,  vector<bool>& visited, int curr, int& nodesCounter)
{
    visited[curr]=true;
    nodesCounter++;
    
    for(int neighbour : graph[curr])
    {
        if(!visited[neighbour])
        {
            dfs(graph, visited, neighbour, nodesCounter);
        }
    }
}
    
int main() 
{
    int N = 0, E = 0, K = 0;
    cin>>N>>E>>K;
    
    vector<bool> visited(N);
    vector<unordered_set<int>> graph(N);

    
    for(int i = 0; i < E; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    
    int ans = 0;
    
    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            int nodesCounter = 0;
            dfs(graph, visited, i, nodesCounter);
            
            if(nodesCounter%K==0)
            {
                ans++;
            }
        }
    }
    
    cout<<ans;
    return 0;
}
