#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
int bfs(unordered_map<int, unordered_set<int>>& graph, 
        unordered_set<int>& banned, int beg, int end)
{
    if (beg == end) return 0; 

    unordered_set<int> visited;
    queue<int> q; 
    
    q.push(beg);
    visited.insert(beg);
    
    int len = 0;
    
    while (!q.empty())
    {
        int s = q.size();
        
        for (int i = 0; i < s; i++)
        {
            int curr = q.front();
            q.pop();
              
            
            for (int neigh : graph[curr])
            {
                if (neigh == end) 
                {
                    return len+1;
                }
                if (!visited.count(neigh) && !banned.count(neigh))
                {
                    visited.insert(neigh);
                    q.push(neigh);
                }
            }
        }
        
        len++;
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
        graph[y].insert(x);
    }
    
    int P = 0;
    cin>>P;
    
    vector<int> path(P);
    
    for(int i = 0; i < P; i++)
    {
        cin>>path[i];
    }
    
    unordered_set<int> banned(path.begin(), path.end());
    
    
    int K = 0;
    cin>>K;
    
    
    for(int i = 0; i < K; i++)
    {
        int curr = 0;
        cin>>curr;
        banned.insert(curr);
    }
    
    banned.erase(path[0]);
    int from = 0, to = 0;
    from = path[0];
    int res = 0;
    
    for(int i = 1; i < path.size(); i++)
    {
        to = path[i];
        banned.erase(to);
        res+=bfs(graph, banned, from, to);
        from = to;
    }
    
    cout<<res;
    
    return 0;
}
