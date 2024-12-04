#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-test4-2022-2023-343rrsdfs/challenges/challenge-3768/problem

int main() 
{
    vector<pair<long, long>> vec;
    int N = 0;
    
    cin>>N;
    
    for(int i = 0; i < N; i++)
    {
        long long beg = 0, end = 0;
        cin>>beg>>end;
        
        if(beg<end)
        {
            vec.push_back({beg, end});
        }
    }
    
    sort(vec.begin(), vec.end());
    
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    
    long long maxSize=0;
    
    for(size_t i = 0; i < vec.size(); i++)
    {
        while(!pq.empty() && pq.top()<=vec[i].first)
        {
            pq.pop();
        }
        
        pq.push(vec[i].second);
        
        maxSize=max(maxSize, (long long)(pq.size()));
    }
    
    cout<<maxSize;
    return 0;
}
