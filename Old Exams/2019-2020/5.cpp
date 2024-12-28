#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


int bfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& pathSet, int from, int to)
{
    unordered_set<int> visited;
    queue<int> q;
    q.push(from);
    visited.insert(from);
    int counter = 0;
    
    while(!q.empty())
    {
        counter++;
        int s = q.size();
        
        for(int i = 0; i < s; i++)
        {
            int curr=q.front();
            q.pop();

            for(int neigh : graph[curr])
            {
                if(neigh==to)
                {
                    return counter;
                }
                if(!visited.count(neigh) && !pathSet.count(neigh))
                {
                    visited.insert(neigh);
                    q.push(neigh);
                }
            }
        }

    }
    
    return -1;
}


int main() 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0;
    int M = 0;
    cin>>N>>M;
    
    unordered_map<int, unordered_set<int>> graph;
    
    for(int i = 0; i < N; i++)
    {
        graph[i];
    }
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        graph[x].insert(y);
    }
    
    int K = 0;
    cin>>K;
    
    vector<int> path(K);
    
    for(int i = 0; i < K; i++)
    {
        cin>>path[i];
    }
    
    unordered_set<int> pathSet(path.begin(), path.end());
    int res = 0;
    pathSet.erase(path[0]);
    for(int i = 0; i < K - 1; i++)
    {
        pathSet.erase(path[i+1]);
        
        int len = bfs(graph, pathSet, path[i], path[i+1]);
        
        if(len==-1)
        {
            cout<<-1;
            return 0;
        }
        else
        {
           res+=len;
        }
    }
    cout<<res;
    
    return 0;
}
