#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/practice-3-1/challenges/bibibi/problem

int main() {
    long long n = 0, q = 0;
    long long p = 0;
    cin>>n;
    
    vector<long long> arr(n);
    
    for(long long i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    cin>>q;
    
    while(q--)
    {
        cin>>p;
        
        auto low = lower_bound(arr.begin(), arr.end(), p);
        auto upper = upper_bound(arr.begin(), arr.end(), p);
        
        if(!(low!= arr.end() && *low==p))
        {
            cout<<-1<<' '<<-1<<'\n';
            continue;
        }
        
        cout<<low-arr.begin()+1<<' '<<upper-arr.begin()<<'\n';
    }
    
    return 0;
}
