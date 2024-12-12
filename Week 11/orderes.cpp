#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

// https://www.hackerrank.com/contests/sda-test-5/challenges/2-61/problem

int main() {
    int n = 0;
    cin>>n;
    
    unordered_map<int, unordered_set<int>> graph;
    
    for(int i = 0; i < n; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    
    int sum = 0;
    int currLevel = 0;
    
    queue<int> q;
    q.push(0);
    
    unordered_set<int> visited;
    visited.insert(0);
    
    while(!q.empty())
    {
        int s = q.size();
        
        for(int i = 0; i < s; i++)
        {
            int v = q.front();
            q.pop();
            visited.insert(v);
            sum+=currLevel;
            
            for(int neighbour : graph[v])
            {
                if(visited.count(neighbour)==0)
                {
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
        
        currLevel++;
    }
    
    cout<<sum;
    
    return 0;
}
