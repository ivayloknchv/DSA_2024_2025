// https://leetcode.com/problems/find-the-town-judge/ 

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int curr)
    {
        visited[curr]=true;

        if(rooms[curr].size())
        {
            for(int i = 0; i < rooms[curr].size(); i++)
            {
                if(!visited[rooms[curr][i]])
                {
                    dfs(rooms, visited,rooms[curr][i]);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int component = 0;
        vector<bool> visited(rooms.size());

        for(int i = 0; i < rooms.size(); i++)
        {
            if(!visited[i])
            {
                dfs(rooms, visited, i);
                component++;
            }
            
        }
        return component == 1;
    }
};
