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

typedef long long ll;
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-7-2024/challenges/kosi/problem

void printPairs(const vector<ll>& nums, ll X)
{
    unordered_map<ll, ll> m; // key - whats's left from the sum (aka what num to find) value - last idx
    
    for(ll i = 0; i < nums.size(); i++)
    {
        if(m.find(nums[i])==m.end())
        {
            m[X-nums[i]]=i;
            continue;
        }
        else
        {
            cout<<m[nums[i]]+1<<' '<<i+1<<'\n';
            break;
        }
        m[X-nums[i]]=i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll T=0;
    cin>>T;
    
    while(T--)
    {
        ll X = 0, N = 0;
        cin>>X>>N;
        vector<ll> nums(N);
        
        for(ll i = 0; i < N; i++)
        {
            cin>>nums[i];
        }
        
        printPairs(nums,X);
    }
    return 0;
}
