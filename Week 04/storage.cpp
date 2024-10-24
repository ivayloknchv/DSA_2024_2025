#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/2-2023-2024/challenges/kosi/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 0, X = 0, N = 0;
    
    cin>>T;
    
    while(T--)
    {
        cin>>X>>N;
        
        vector<pair<int,int>> boxes;
        
        for(int i = 0; i < N; i++)
        {
            int W = 0;
            cin>>W;
            
            boxes.push_back({W, i + 1});
        }
        
        sort(boxes.begin(), boxes.end());
        
        int l = 0;
        int r = N - 1;
        
        while(l<=r)
        {
            int sum = boxes[l].first + boxes[r].first;
            
            if(sum==X)
            {
                int minPos = min(boxes[l].second, boxes[r].second);
                int maxPos = max(boxes[l].second, boxes[r].second);
                cout<<minPos<<' '<<maxPos<<'\n';
                break;
            }
            else if(sum<X)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    
    return 0;
}
