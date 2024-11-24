// https://leetcode.com/problems/delete-greatest-value-in-each-row/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) 
    {
        vector<priority_queue<int>> v(grid.size());

        for(int i = 0; i < grid.size(); i++)
        {
            v[i] = priority_queue<int>(grid[i].begin(), grid[i].end());
        }    
        
        int ans = 0;
        int m = grid[0].size();

        for(int j = 0; j < m; j++)
        {
            int maxVal=0;
            for(int i  = 0; i<v.size(); i++)
            {
                maxVal=max(maxVal, v[i].top());
                v[i].pop();
            }
            ans+=maxVal;
        }

        return ans;
    }
};
