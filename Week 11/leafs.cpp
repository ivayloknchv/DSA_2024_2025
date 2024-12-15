#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/leafs/problem

unordered_map<int, unordered_set<int>> graph;
int nodesSum[200000+1]{};
bool visited[200000+1]{};

void dfs(int start)
{
    visited[start]=true;
    
    for(int neighbour : graph[start])
    {
        if(!visited[neighbour])
        {
            dfs(neighbour);
        }
        nodesSum[start] += neighbour + nodesSum[neighbour];
    }
}

int main() 
{
    int m = 0, t = 0;
    cin>>m>>t;
    
    for(int i = 0; i < m; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        
        graph[x].insert(y);
    }
    
    for(int i = 0; i < t; i++)
    {
        int q = 0;
        cin>>q;
        
        if(!visited[q])
        {
            dfs(q);
        }
        
        cout<<nodesSum[q]<<'\n';
    }
    return 0;
}
