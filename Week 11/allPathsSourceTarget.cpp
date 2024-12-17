// https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& currPath, 
    int curr, int n)
    {
        currPath.push_back(curr);
        if(curr == n - 1)
        {
            res.push_back(currPath);
            currPath.pop_back();
            return;
        }

        for(int neighbour : graph[curr])
        {
            dfs(graph, res, currPath, neighbour, n);
        }

        currPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>>  res;
        vector<int> currPath;

        dfs(graph, res, currPath, 0, graph.size());

        return res;
    }
};
