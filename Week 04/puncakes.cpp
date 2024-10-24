#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/problem

bool check(const vector<long long>& times, long long norm, long long target)
{
    long long totalPancakes = 0;
    
    for(size_t i = 0; i<times.size(); i++)
    {
        totalPancakes+=norm/times[i];
    }
    
    return totalPancakes >= target;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, K=0;
    
    cin>>N>>K;
    
    vector<long long> times(K);
    
    cin>>times[0];
    long long maxTime=times[0];
    long long minTime=times[0];
    
    for(long long i = 1; i < K; i++)
    {
        cin>>times[i];
        
        maxTime=max(maxTime, times[i]);
        minTime=min(minTime, times[i]);
    }
    
    long long infimum = (N / K) * minTime;
    long long supremum = (N / K + 1) * maxTime;
    
    long long l = infimum;
    long long r = supremum;
    
    long long ans=0;
    
    while(l<=r)
    {
        long long mid = l + (r - l) / 2;
        
        if(check(times, mid, N))
        {
            ans=mid;
            r = mid - 1;
        }
        else
        {
            l = mid+1;
        }
    }
    
    cout<<ans;
    
    return 0;
}
