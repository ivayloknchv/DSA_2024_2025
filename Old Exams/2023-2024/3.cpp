#include <bits/stdc++.h>
using namespace std;


void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int curr, int parent, bool& hasCycle)
{
    visited.insert(curr);
    
    for(int neigh : graph[curr])
    {
        if(!visited.count(neigh))
        {
            dfs(graph, visited, neigh, curr, hasCycle);
        }
        else if(parent!=neigh)
        {
            hasCycle=true;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T = 0;
    cin>>T;
    
    for(int i = 0; i < T; i++)
    {
        int V = 0, E = 0;
        cin>>V>>E;
        
        unordered_map<int, vector<int>> graph;
        
        for(int i = 0; i < V; i++)
        {
            graph[i];
        }
        
        for(int i = 0; i < E; i++)
        {
            int x = 0, y = 0;
            cin>>x>>y;
            
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        unordered_set<int> visited;
        
        int counter = 0;
        
        for(auto& it : graph)
        {
            if(!visited.count(it.first))
            {
                bool hasCycle=false;
                
                dfs(graph, visited, it.first, -1, hasCycle);
                
                if(hasCycle)
                {
                    counter++;
                }
            }
        }
        
        cout<<counter<<'\n';
    }

    return 0;
}
