#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-2020-2021-test7-8jfn4/challenges/challenge-2737/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0;
    cin>>N;
    
    priority_queue<int> pq;
    
    while(N--)
    {
        int num = 0;
        cin>>num;
        
        if(num==-1)
        {
            if(pq.size())
            {
                cout<<pq.top()<<' ';
                pq.pop();
            }
            continue;
        }
        pq.push(num);
    }
    return 0;
}
