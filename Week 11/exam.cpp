#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

// https://www.hackerrank.com/contests/exam-2022-part1-sda/challenges/sda-exam/problem

using namespace std;

void bfs(unordered_map<int, unordered_set<int>>& graph, int start, vector<int>& dist)
{
    unordered_set<int> visited;
    queue<int> q;
    
    q.push(start);
    visited.insert(start);
    dist[start] = 0;
    int nextDist = 1;
    
    while(!q.empty())
    {
        int s = q.size();
        
        for(int i = 0; i < s; i++)
        {
            int curr = q.front();
            q.pop();
            
            for(int neighbour : graph[curr])
            {
                if(visited.count(neighbour) == 0)
                {
                    visited.insert(neighbour);
                    dist[neighbour] = nextDist * 6;
                    q.push(neighbour);
                }
            }
        }
        nextDist++;
    }
    
}

void process()
{
    unordered_map<int, unordered_set<int>> graph;
    
    int N = 0, M = 0;
    
    cin>>N>>M;
    
    vector<int> ans(N+1, -1);
    
    for(int i = 1; i <= N; i++)
    {
        graph[i];
    }
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0;
        cin>>x>>y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    
    int start = 0;
    cin>>start;
    
    bfs(graph, start, ans);
    
    for(int i = 1; i <= N; i++)
    {
        if(i!=start)
        {
            cout<<ans[i]<<' ';
        }
    }
    cout<<'\n';
}

int main() 
{
    int q =0;
    cin>>q;
    
    while(q--)
    {
        process();
    }
   
    return 0;
}
