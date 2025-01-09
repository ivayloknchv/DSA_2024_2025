// https://www.hackerrank.com/challenges/kruskalmstrsub/problem

struct DisjointSet
{
  vector<int> parents;
  vector<int> size;
  
  DisjointSet(int n)
  {
    parents.resize(n+1);
    size.resize(n+1, 1);
    
    for(int i = 0; i <= n; i++)
    {
        parents[i] = i;
    }
  }
  
  int getParent(int node)
  {
    if(node == parents[node])
    {
        return node;
    }   
    return parents[node] = getParent(parents[node]);
  }  
  
  void Union(int x, int y)
  {
    int p_x = getParent(x);
    int p_y = getParent(y);
    
    if(p_x == p_y)
    {
        return;
    }
    
    if(size[p_x] > size[p_y])
    {
        parents[p_y] = p_x;
        size[p_x] += size[p_y];
    }
    else
    {
        parents[p_x] = p_y;
        size[p_y] += size[p_x];
    }
  }
};


int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) 
{
    vector<pair<int, pair<int, int>>> edges;
    
    DisjointSet djs(g_nodes);
    
    int weight = 0;
    
    for(int i = 0; i < g_to.size(); i++)
    {
        edges.push_back({g_weight[i], {g_from[i], g_to[i]}});
    }
    
    sort(edges.begin(), edges.end());
    
    for(int i = 0; i < edges.size(); i++)
    {
        if(djs.getParent(edges[i].second.first)!=djs.getParent(edges[i].second.second))
        {
            djs.Union(edges[i].second.first, edges[i].second.second);
            weight+=edges[i].first;
        }
    }
    
    return weight;
}
