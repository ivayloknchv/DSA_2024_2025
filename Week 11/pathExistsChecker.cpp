#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-2020-2021-test9-wefnkcsdw/challenges/challenge-2763/problem

bool graph[1000][1000]{};

int main() 
{
    int M = 0;
    cin>>M;
    
    for(int i = 0; i < M; i++)
    {
        int neighboursCount = 0;
        cin>>neighboursCount;
        
        for(int j = 0; j < neighboursCount; j++)
        {
            int neighbour = 0;
            cin>>neighbour;
            graph[i][neighbour] = true;
            graph[neighbour][i] = true;
        }
    }
    
    int q = 0;
    cin>>q;
    
    while(q--)
    {
        int n = 0;
        cin>>n;
        vector<int> vec(n);
        
        for(int i = 0; i < n; i++)
        {
            cin>>vec[i];
        }
        
        bool flag=true;
        for(int i = 0; i < n-1; i++)
        {
            if(!graph[vec[i]][vec[i+1]])
            {
                flag = false;
                break;
            }
        }
        cout<<flag<<' ';
    }
    return 0;
}
