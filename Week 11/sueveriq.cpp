// https://www.hackerrank.com/contests/sda-2021-2022-test-7-final/challenges/challenge-2817/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0, M = 0;
    cin >> N >> M;
    
    vector<vector<unordered_set<int>>> graph(N, vector<unordered_set<int>>(N));
    
    vector<vector<int>> edges(M, vector<int>(3, 0));
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        edges[i][0]=x;
        edges[i][1]=y;
        edges[i][2]=w;
    }
    
    int K = 0;
    cin>>K;
    
    unordered_set<int> nums;
    
    for(int i = 0; i < K; i++)
    {
        int curr = 0;
        cin >> curr;
        nums.insert(curr);
    }
    
    for(auto& edge : edges)
    {
        if(nums.count(edge[2]))
        {
            continue;
        }
        graph[edge[0]][edge[1]].insert(edge[2]);
    }
    
    int Q = 0;
    cin>>Q;
    
    while(Q--)
    {
        int L = 0;
        cin >> L;
        
        vector<int> path(L);
        
        for(int i = 0; i < L; i++)
        {
            cin>>path[i];
        }
        
        bool flag = true;
        
        for(int i = 0; i < L-1; i++)
        {
            int from = path[i];
            int to = path[i+1];
            
            if(graph[from][to].empty())
            {
                flag=false;
                break;
            }
        }
        
        if(flag)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    
    return 0;
}
