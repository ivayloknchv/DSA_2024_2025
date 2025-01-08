// https://leetcode.com/problems/min-cost-to-connect-all-points/description/

class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        using pii= pair<int, int>;
        priority_queue<pii, vector<pii>, greater<>>pq;
        pq.push({0, 0});

        int total = 0;

        unordered_set<int> visited;

        while(!pq.empty())
        {
            auto [d, n] = pq.top();
            pq.pop(); 

            if(visited.count(n))
            {
                continue;
            }

            visited.insert(n);
            total += d;

            for(int i = 0; i < points.size(); i++)
            {
                if(visited.count(i))
                {
                    continue;
                }
                int dist = abs(points[n][0] - points[i][0]) + abs(points[n][1] - points[i][1]);
                pq.push({dist, i});
            }
        }

        return total;
    }
};
