#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-homework-12/challenges/challenge-2801/problem

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
        
        if(px == py)
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


int main() 
{
    vector<pair<int, int>> edges;
    
    int n = 0, m = 0;
    cin>>n>>m;
    
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    
    int cleaned = 0;
    
    UnionFind uf(n);
    
    for(int i = 1; i <= m; i++)
    {
        int u = 0, v = 0;
        cin>>u>>v;
        
        if(uf.Find(u) != uf.Find(v))
        {
            uf.Union(u, v);
            cleaned++;
        }
        
        if(cleaned == n-1)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
