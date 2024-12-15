// https://leetcode.com/problems/reachable-nodes-with-restrictions/description/

class Solution 
{
public:

    void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited,
    unordered_set<int>& restricted, int curr)
    {
        visited.insert(curr);

        for(int neighbour : graph[curr])
        {
            if(restricted.count(neighbour) == 0 && visited.count(neighbour) == 0)
            {
                dfs(graph, visited, restricted, neighbour);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r)
    {
        unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> visited;
        unordered_set<int> restricted(r.begin(), r.end());

        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        dfs(graph, visited, restricted, 0);

        return visited.size();
    }
};
