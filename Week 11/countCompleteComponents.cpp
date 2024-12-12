// https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution {
public:

    void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited,
    unordered_set<int>& componentNodes, int curr)
    {
        visited.insert(curr);
        componentNodes.insert(curr);

        for(int neighbour : graph[curr])
        {
            if(visited.count(neighbour) == 0)
            {
                dfs(graph, visited, componentNodes, neighbour);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int, unordered_set<int>> graph;

        for(int i = 0; i < n; i++)
        {
            graph[i];
        }

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].insert(v);
            graph[v].insert(u);
        }

        unordered_set<int> visited;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
           
            if(!visited.count(i))
            {
                unordered_set<int> componentNodes;
                dfs(graph, visited, componentNodes, i);

                int s = componentNodes.size();
                bool flag =true;

                for(int node : componentNodes)
                {
                    if(graph[node].size() != s - 1)
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag)
                {
                    ans++;
                }
            }    
        }

        return ans;
    }
};
