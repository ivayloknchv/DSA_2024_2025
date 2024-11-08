#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-5-2022/challenges/challenge-3724/problem

int N = 0, M = 0, T = 0;
bool matrix[1000][1000]{};
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>T;
    
    queue<pair<int,int>> rotten;
    
    int x = 0, y = 0;
    
    while(cin>>x>>y)
    {
        rotten.push({x-1,y-1});
    }
    
    for(int i = 0; i<=T; i++)
    {
        int n = rotten.size();
        
        for(int j = 0; j < n; j++)
        {
            pair<int,int> curr = rotten.front();
            rotten.pop();
            
            if(curr.first<0 || curr.first>=N || curr.second <0 || curr.second >=M)
            {
                continue;
            }
            
            if(matrix[curr.first][curr.second])
            {
                continue;
            }
            
            matrix[curr.first][curr.second]=true;
            rotten.push({curr.first-1, curr.second});
            rotten.push({curr.first+1, curr.second});
            rotten.push({curr.first, curr.second-1});
            rotten.push({curr.first, curr.second+1});
        }
    }
    
    int counter=0;
    
    for(int i =0; i<N; i++)
    {
        for(int j =0; j<M; j++)
        {
            if(!matrix[i][j])
            {
                counter++;
            }
        }
    }
    
    cout<<counter;
    
    
    return 0;
}
