#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-9-2023/challenges/challenge-4437/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> mp; // number -> first idx of occurance
    
    int N = 0;
    cin>>N;
    
    vector<int> v(N);
    
    for(int i = 0; i < N; i++)
    {
        cin>>v[i];
    }
    
    int dist=INT_MAX;
    
    for(int i = 0; i<v.size(); i++)
    {
        if(mp.find(v[i])==mp.end())
        {
            mp[v[i]] = i;
        }
        else
        {
            dist=min(dist, i-mp[v[i]]);
        }
    }
    
    cout<<dist;
    
    return 0;
}
