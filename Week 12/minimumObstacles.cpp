// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

struct Node
{
    int x = 0;
    int y = 0;
    int count = 0;

    bool operator<(const Node& other) const 
    {

        return this->count > other.count;

    }
};

class Solution 
{
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isValid(int x, int y, int m, int n)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:

    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> obstacles(m, vector<int>(n, INT_MAX));
        obstacles[0][0] = 0;

        priority_queue<Node> pq;
        pq.push({0,0,0});

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            if(curr.count>obstacles[curr.x][curr.y])
            {
                continue;
            }

            for(int i = 0 ; i < 4; i++)
            {
                int newX = curr.x + directions[i][0];
                int newY = curr.y + directions[i][1];

                if(!isValid(newX,newY,m,n))
                {
                    continue;
                }

                int obs = curr.count + grid[newX][newY];

                if(obs<obstacles[newX][newY])
                {
                    obstacles[newX][newY] = obs;
                    pq.push({newX, newY, obs});
                }
            }
        }

        return obstacles[m-1][n-1];
    }
};
