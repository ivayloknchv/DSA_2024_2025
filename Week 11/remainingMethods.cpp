// https://leetcode.com/problems/remove-methods-from-project/description/

class Solution {
public:

    void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr)
    {
        visited.insert(curr);

        for(int neigh : graph[curr])
        {
            if(visited.count(neigh) == 0)
            {
                dfs(graph, visited, neigh);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        unordered_map<int, unordered_set<int>> graph;

        for(int i = 0; i < n; i++)
        {
            graph[i];
        }

        for(int i = 0; i < invocations.size(); i++)
        {
            graph[invocations[i][0]].insert(invocations[i][1]);
        }

        unordered_set<int> visited;

        dfs(graph, visited, k);

        bool canRemove = true;

        for(int i = 0; i < n; i++)
        {
            if(visited.count(i)==0)
            {
                for(int it : graph[i])
                {
                    if(visited.count(it))
                    {
                        canRemove=false;
                        break;
                    }
                }
            }
        }

        if(!canRemove)
        {
            vector<int> vec;

            for(int i = 0; i < n; i++)
            {
                vec.push_back(i);
            }

            return vec;
        }

        vector<int> vec;

        for(int i = 0; i < n; i++)
        {
            if(visited.count(i)==0)
            {
                vec.push_back(i);
            }
        }

        return vec;
    }
};
