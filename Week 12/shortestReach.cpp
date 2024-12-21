// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) 
{
    using pii = pair<int, int>;
    vector<vector<pii>> graph(n+1);
    
    for(int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<int> dist(n+1, INT_MAX);
    
    dist[s] = 0;
    
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, s});
    
    while(!pq.empty())
    {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if(w > dist[v])
        {
            continue;
        }
        
        for(auto& it : graph[v])
        {
            int neigh = it.first;
            int weight = it.second;
            
            if(dist[neigh] > weight + w)
            {
                dist[neigh] = weight + w;
                pq.push({weight+w, neigh});
            }
        }
    }
    
        
    vector<int> res;
    for (int i = 1; i <= n; i++) 
    {
        if (i != s) 
        {
            if(dist[i] == INT_MAX)
            {
                res.push_back(-1);
            }
            else 
            {
                res.push_back(dist[i]);
            }
            
        }
    }
    return res;
}
