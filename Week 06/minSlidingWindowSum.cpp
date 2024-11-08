#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

// https://www.hackerrank.com/contests/sda-hw-4-2024/challenges/challenge-3723/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0, K = 0;
    long long ans = 0;
    cin>>N>>K;
    
    vector<int> vec(N);
    
    for(int i = 0; i < N; i++)
    {
        cin>>vec[i];
    }
    
    deque<int> d;
    
    for(int i = 0; i < K; i++)
    {
        while(!d.empty() && d.back()>vec[i])
        {
            d.pop_back();
        }
        d.push_back(vec[i]);
    }
    
    ans+=d.front();
    
    for(int i = K; i < N; i++)
    {
        if(d.front()==vec[i-K])
        {
            d.pop_front();
        }
        
        while(!d.empty() && d.back()>vec[i])
        {
            d.pop_back();
        }
        d.push_back(vec[i]);
        ans+=d.front();
    }
    
    cout<<ans;
    return 0;
}
