// https://leetcode.com/problems/find-the-town-judge/

class Solution 
{
public:
    bool dfs(unordered_map<int, unordered_set<int>>& graph,  unordered_set<int>& visited,
    int start, int dest)
    {
        visited.insert(start);

        if(start == dest)
        {
            return true;
        }

        for(int neighbour : graph[start])
        {
            if(!visited.count(neighbour))
            {
                bool ans = dfs(graph, visited, neighbour, dest);
                
                if(ans)
                {
                    return ans;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        unordered_map<int, unordered_set<int>> graph;

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].insert(v);
            graph[v].insert(u);
        }

        unordered_set<int> visited;

        return dfs(graph, visited, source, destination);
    }
};
