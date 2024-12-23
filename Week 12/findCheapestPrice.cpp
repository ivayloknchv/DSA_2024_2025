// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int i = 0; i < k + 1; i++)
        {
            vector<int> curr(dist);
            for(auto& f : flights)
            {
                if(dist[f[0]]!=INT_MAX && dist[f[0]] + f[2] < dist[f[1]])
                {
                    dist[f[1]] = dist[f[0]] + f[2];
                }
            }

            dist = std::move(curr);
        }

        if(dist[dst]==INT_MAX)
        {
            return -1;
        }

        return dist[dst];
    }
};
