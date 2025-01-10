// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

struct UnionFind
{
    vector<int> parent;
    vector<int> size;

    UnionFind(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int n)
    {
        if(parent[n] == n)
        {
            return n;
        }

        return parent[n] = Find(parent[n]);
    }

    void Union(int x, int y)
    {
        int px = Find(x);
        int py = Find(y);

        if(px==py)
        {
            return;
        }

        if(size[px] > size[py])
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

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        UnionFind uf(n);

        for(auto& edge : edges)
        {
            uf.Union(edge[0], edge[1]);
        }

        
        return (uf.Find(source) == uf.Find(destination));    
    }
};
