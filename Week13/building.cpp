#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/contests/sda-hw-11-2024/challenges/2-146/problem

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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long N = 0, M = 0;
    cin>>N>>M;
    
    vector<vector<long long>> edges(M, vector<long long>(5, 0));
    
    int counter = 0;
    
    for(auto& edge : edges)
    {
        cin>>edge[0]>>edge[1]>>edge[2]>>edge[3];
        edge[0]--;
        edge[1]--;
        edge[4] = counter++;
    }
    
    sort(edges.begin(), edges.end(), 
         [](const vector<long long>& a, const vector<long long>& b)
         {
             if(a[2] == b[2])
             {
                 return a[3] > b[3];
             }
             return a[2] < b[2];
         }
        );
    
    UnionFind uf(N);
    
    counter = 0;
    for(auto& edge : edges)
    {
        if(uf.Find(edge[0])!=uf.Find(edge[1]))
        {
            uf.Union(edge[0], edge[1]);
            cout<<edge[4] + 1<<'\n';
            counter++;
        }
        
        if(counter==N-1)
        {
            break;
        }
    }
    
    return 0;
}
