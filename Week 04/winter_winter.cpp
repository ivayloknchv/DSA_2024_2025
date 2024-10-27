#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// https://www.hackerrank.com/contests/practice-3-1/challenges/winterwinter/problem

bool check(const vector<long long>& clothes, long long time, long long K)
{
    long long totalDrierUses=0;
    
    for(long long el : clothes)
    {
        if(el<=0)
        {
            continue;
        }
        if(el-time>0)
        {
        long long drierMins = ceil((el-time)*1.00 / (K-1));
        totalDrierUses+=drierMins;
        }
    }
    
    return totalDrierUses <= time;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N = 0, K = 0, maxTime=LLONG_MIN;
    cin>>N>>K;
    
    vector<long long>clothes(N);
    
    for(long long i = 0; i < N; i++)
    {
        cin>>clothes[i];
        maxTime=max(maxTime, clothes[i]);
    }
    
    long long l = 0;
    long long r = maxTime;
    long long ans=LLONG_MAX;
    
    if(K==1)
    {
        cout<<maxTime;
        return 0;
    }
    
    while(l<=r)
    {
        long long mid = l + (r - l) / 2;
        
        if(check(clothes, mid, K))
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            l = mid + 1;
        }
    }
    
    cout<<ans;
    return 0;
}
