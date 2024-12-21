// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) 
    {
        using pii = pair<int, int>;
        vector<vector<pii>> graph(n+1);

        for(int i = 0; i < t.size(); i++)
        {
            graph[t[i][0]].push_back({t[i][1], t[i][2]});
        }

        vector<int> times(n+1, INT_MAX);
        times[k] = 0;

        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();

            if(time > times[node])
            {
                continue;
            }

            for(auto& it : graph[node])
            {
                if(time + it.second < times[it.first])
                {
                    times[it.first] = time + it.second;
                    pq.push({time + it.second, it.first});
                }
            }
        }

        for(int i = 1; i <= n; i++)
        {
            if(times[i]==INT_MAX)
            {
                return -1;
            }
        }

        return *max_element(times.begin()+1, times.end());
    }
};
