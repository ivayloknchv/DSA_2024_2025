#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool check(const vector<long long>& speed, long long testTime, long long goal)
{
    long long res=0;
    
    for(size_t i = 0; i<speed.size();i++)
    {
        res+=testTime/speed[i];
    }
    
    return res>=goal;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n = 0, k = 0, minTime = 0, maxTime = 0;
    cin>>n>>k;
    
    vector<long long> speed(k);
    
    cin>>speed[0];
    
    minTime = maxTime = speed[0];
    
    for(int i=1; i<k; i++)
    {
        cin>>speed[i];
        
        minTime=min(speed[i], minTime);
        maxTime=max(speed[i], maxTime);
    }
    
    long long bestCase = (n / k) * minTime;
    long long worstCase=(n / k + 1) * maxTime;
    
    long long l = bestCase;
    long long r = worstCase;
    long long res = 0;
    
    while(l<=r)
    {
        long long mid = l + (r - l) / 2;
        
        if(check(speed,mid,n))
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        
    }
    
    cout<<res;
    
    
    return 0;
}
