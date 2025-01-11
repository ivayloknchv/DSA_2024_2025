#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-test6-2022-2023-iythgbeu3/challenges/challenge-2351/problem

struct UnionFind
{
    vector<int> parent;
    vector<int> size;
    int components = 0;
    
    UnionFind(int n) : components(n)
    {
        parent.resize(n);
        size.resize(n, 1);
        
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    
    int Find(int n)
    {
        if(parent[n]==n)
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
        
        if(size[px]>size[py])
        {
            parent[py] = px;
            size[px] += size[py];
        }
        else
        {
            parent[px] = py;
            size[py] += size[px];
        }
        
        --components;
    }
};


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 0;
    cin>>T;
    
    while(T--)
    {
        int N = 0, M = 0;
        cin>>N>>M;

        UnionFind uf(N);

        vector<pair<int, int>> edges(M);

        for(int i = 0; i < M; i++)
        {
            int x = 0, y = 0;
            cin>>x>>y;

            edges[i] = {x, y};
        }

        for(auto& [x, y] : edges)
        {
            if(uf.Find(x)!=uf.Find(y))
            {
                uf.Union(x, y);
            }
        }

        cout<<uf.components<<' ';
    }
    return 0;
}
