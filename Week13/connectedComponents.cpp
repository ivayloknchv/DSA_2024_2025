#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/6-20232024/challenges/1-579/problem

struct DJS
{
    vector<int> parents;
    vector<int> sizes;
    int n = 0;
    
    DJS(int n) : n(n)
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
            n--;
        }
        
        else
        {
            parents[px] = py;
            sizes[py] += sizes[px];
            n--;
        }
    }
};

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0;
    cin>>N;
    
    vector<pair<int, int>> edges;
    int x = 0, y = 0;
    
    
    while(cin>>x>>y)
    {       
        edges.push_back({x, y});
    }
    
    
    DJS s(N);
    
    for(int i = 0; i < edges.size(); i++)
    {
        int x = edges[i].first;
        int y = edges[i].second;
        
        if(s.findParent(x) != s.findParent(y))
        {
            s.unify(x, y);
            cout<<s.n<<'\n';
        }
        else
        {
            cout<<s.n<<' '<<"CYCLE FORMED!"<<'\n';
        }
    }
    return 0;
}
