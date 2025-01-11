#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct DJS
{
    vector<int> parents;
    vector<int> sizes;
    
    DJS(int n)
    {
        parents.resize(n+1);
        sizes.resize(n+1, 1);
        
        for(int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
    }
    
    int findParent(int n)
    {
        if(parents[n] == n)
        {
            return n;
        }
        
        return parents[n] = findParent(parents[n]);
    }
    
    void unify(int x, int y)
    {
        int px = findParent(x);
        int py = findParent(y);
        
        if(px==py)
        {
            return;
        }
        
        if(sizes[px]>sizes[py])
        {
            parents[py] = px;
            sizes[px] += sizes[py];
        }
        
        else
        {
            parents[px] = py;
            sizes[py] += sizes[px];
        }
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0, M = 0;
    cin>>N>>M;
    
    int total=0;
    vector<pair<int, pair<int, int>>> edges;
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        
        total += w;
        edges.push_back({w, {x, y}});
    }
    
    sort(edges.rbegin(), edges.rend());

    
    DJS s(N);
    
 
    int sum = 0;
    
    for(int i = 0; i < M; i++)
    {
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        int w = edges[i].first;
        
       
        
        if(s.findParent(x)!=s.findParent(y))
        {
            s.unify(x, y);
            sum+=w;
        }
    }
    
    cout << total - sum;
    return 0;
}
