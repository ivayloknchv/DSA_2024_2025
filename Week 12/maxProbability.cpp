// https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, 
    int start_node, int end_node) {
        using pdi = pair<double, int>;

        vector<vector<pdi>> graph(n);

        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1;

        priority_queue<pdi, vector<pdi>, less<>> pq;
        pq.push({1, start_node});

        while(!pq.empty())
        {
            auto [prob, node] = pq.top();
            pq.pop();

            if(prob < maxProb[node])
            {
                continue;
            }

            for(auto& [p, neigh] : graph[node])
            {
                if(maxProb[neigh]< p * prob)
                {
                    maxProb[neigh] = p * prob;
                    pq.push({p*prob, neigh});
                }
            }
        }

        return maxProb[end_node];
    }
};
