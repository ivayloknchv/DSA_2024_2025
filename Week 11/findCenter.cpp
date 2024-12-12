// https://leetcode.com/problems/find-center-of-star-graph/description/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int n = edges.size() + 1;
        vector<int> deg(n+1, 0);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            deg[u]++;
            deg[v]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(deg[i]==n-1)
            {
                return i;
            }
        }

        return -1;
    }
};
