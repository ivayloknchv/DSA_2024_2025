#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/exam-2020-02-06-sda/challenges/challenge-2855/problem

int main() 
{
    int K = 0, T = 0, B = 0, N = 0;
    cin>>K>>T>>B>>N;
    
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i = 1; i <= N; i++)
    {
        int curr = 0;
        cin>>curr;
        
        pq.push(curr);
        
        if(i % T == 0 || i == N)
        {
            for(int j = 0; j < K; j++)
            {
                cout<<pq.top()<<' ';
                pq.pop();
            }
            
            B--;
            
            if(B==0)
            {
                break;
            }
        }
    }
    
    int left = B * K;
    
    for(int i = 0; i < left; i++)
    {
        cout<<pq.top()<<' ';
        pq.pop();
    }
    
    return 0;
}
