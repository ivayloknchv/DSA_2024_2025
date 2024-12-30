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

bool check(const vector<long long>& cooks, long long N, long long test)
{
    long long res = 0;
    
    for(long long i = 0; i < (long long)cooks.size(); i++)
    {
        res += test/cooks[i];
    }
    
    return res>=N;
}

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N = 0, K = 0;
    cin>>N>>K;
    vector<long long> cooks(K);
    
    long long maxTime=LLONG_MIN;
    
    for(long long i = 0; i < K; i++)
    {
        cin>>cooks[i];
        maxTime=max(maxTime, cooks[i]);
    }
    
    
    long long l = 0;
    long long r = maxTime*N;
    
    long long ans = 0;
    
    while(l<=r)
    {
        long long mid = l + (r-l)/2;
        if(check(cooks, N, mid))
        {
            ans = mid;
            r=mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    
    cout<<ans;
    return 0;
}
