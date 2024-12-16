//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool dfs(vector<vector<int>>& adj, unordered_set<int>& visited, int curr, int parent)
    {
        visited.insert(curr);
        
        for(int neighbour : adj[curr])
        {
            
            if(!visited.count(neighbour))
            {
                if(dfs(adj, visited, neighbour, curr))
                {
                    return true;
                }
            }
            
            else if(neighbour != parent)
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) 
    {
        unordered_set<int> visited;
        
        int v = adj.size();
        
        for(int i = 0; i < v; i++)
        {
            if(!visited.count(i) && dfs(adj, visited, i, -1))
            {
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
