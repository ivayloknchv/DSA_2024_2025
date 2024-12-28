#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N = 0, M = 0;
    cin>>N>>M;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    
    for(int i = 0; i < M; i++)
    {
        int x = 0, y = 0, w = 0;
        cin>>x>>y>>w;
        graph[x][y] = w;
        graph[y][x] = w;
        
    }
    
    int K = 0;
    cin>>K;
    vector<int> nums(K);
    
    for(int i = 0; i < K; i++)
    {
        cin>>nums[i];
    }
    
    int sum = 0;
    for(int i = 0; i < K - 1; i++)
    {
        if(graph[nums[i]][nums[i+1]]==0)
        {
            cout<<-1;
            return 0;
        }
        
        sum += graph[nums[i]][nums[i+1]];
    }
    cout<<sum;
    return 0;
}
