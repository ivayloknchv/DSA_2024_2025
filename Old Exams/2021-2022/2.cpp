#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void bfs(unordered_map<int, vector<int>>& graph, int start, vector<int>& dist)
{
    queue<int> q;
    q.push(start);
    vector<bool> visited(graph.size()+1);
    visited[start] = true;
    
    int currLevel = 6;
    
    while(!q.empty())
    {
        int s = q.size();
        
        for(int i = 0; i < s; i++)
        {
            int curr=q.front();
            q.pop();
            
            for(int neigh : graph[curr])
            {
                if(!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh]=true;
                    dist[neigh]=currLevel;
                }
            }
        }
        
        currLevel+=6;
    }
}

void func()
{
    unordered_map<int, vector<int>> graph;
    
    int N = 0, M = 0;
    cin>>N>>M;
    
    for(int i = 1; i <= N; i++)
    {
        graph[i];
    }
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    vector<int> dist(N+1, -1);
    
    int ivancho = 0;
    cin>>ivancho;
    
    dist[ivancho]=0;
    
    bfs(graph, ivancho, dist);
    
    for(int i = 1; i <= N; i++)
    {
        if(i==ivancho)
        {
            continue;
        }
        cout<<dist[i]<<' ';
    }
    
    cout<<'\n';
}

using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q = 0;
    
    cin>>Q;
    
    while(Q--)
    {
        func();
    }
    
    return 0;
}
