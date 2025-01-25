struct UnionFind
{
    vector<int> parent;
    vector<int> size;

    UnionFind(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int n)
    {
        return (parent[n] == n) ? n : parent[n] = Find(parent[n]);
    }

    void Union(int x, int y)
    {
        int px = Find(x);
        int py = Find(y);

        if (px == py)
        {
            return;
        }

        if (size[px] > size[py])
        {
            parent[py] = px;
            size[px] += size[py];
        }

        else
        {
            parent[px] = py;
            size[py] += size[px];
        }
    }
    
};


class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        UnionFind uf(points.size());
        vector<pair<int, pair<int, int>>> edges;

        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        int sum = 0;

        for(int i = 0; i < edges.size(); i++)
        {
            int d = edges[i].first;
            int x = edges[i].second.first;
            int y = edges[i].second.second;

            if(uf.Find(x) != uf.Find(y))
            {
                uf.Union(x, y);
                sum+=d;
            }
        }

        return sum;
    }
};
