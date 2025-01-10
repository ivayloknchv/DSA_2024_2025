#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-11-2024/challenges/roads-5/problem

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

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0, M = 0;
    cin>>N>>M;
    
    UnionFind uf(N);
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        
        uf.Union(x, y);
    }
    
    int Q = 0;
    cin>>Q;
    
    for(int i = 0; i < Q; i++)
    {
        int q = 0, x = 0, y = 0;
        cin>>q>>x>>y;
        
        if(q==1)
        {
            cout<< (uf.Find(x) == uf.Find(y));
        }
        else if(q==2)
        {
            uf.Union(x, y);
        }
    }
    
    return 0;
}
