// https://www.hackerrank.com/challenges/primsmstsub/problem

int prims(int n, vector<vector<int>> edges, int start) 
{
    unordered_map<int, vector<pair<int, int>>> graph;
    
    for(auto edge : edges)
    {
        graph[edge[0]].push_back({edge[2], edge[1]});
        graph[edge[1]].push_back({edge[2], edge[0]});
    }
    
    int weightMin = 0;
    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, start});
    
    while(!pq.empty())
    {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if(visited.count(node))
        {
            continue;
        }
        
        visited.insert(node);
        weightMin += weight;
        
        for(auto [w, neigh] : graph[node])
        {
            if(visited.count(neigh))
            {
                continue;
            }
            pq.push({w, neigh});
        }
    }
    return weightMin;
}
