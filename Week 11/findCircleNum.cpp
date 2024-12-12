// https://leetcode.com/problems/number-of-provinces/description/

class Solution 
{
public:

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int curr)
    {
        visited[curr] = true;

        for (int i = 0; i < isConnected[curr].size(); i++)
        {
            if(isConnected[curr][i] && !visited[i])
            {
                dfs(isConnected, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
       int components = 0;
       int n = isConnected.size();
       vector<bool> visited(n, false);

       for(int i = 0; i < n; i++)
       {
            if(!visited[i])
            {
                dfs(isConnected, visited, i);
                components++;
            }
       }

       return components;
    }
};
