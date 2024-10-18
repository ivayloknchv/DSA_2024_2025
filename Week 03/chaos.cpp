#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-test1-2022-2023/challenges/challenge-3676/problem

bool compare(const pair<int,int>& lhs, const pair<int,int>& rhs)
{
    if(lhs.first==rhs.first)
    {
        return lhs.second<rhs.second;
    }
    
    return lhs.first<rhs.first;
}

int main() {
    
    int n=0;
    cin>>n;
    
    vector<pair<int,int>> votes(n);
    
    for(int i=0; i<n; i++)
    {
       cin>>votes[i].first;
        votes[i].second=i;
    }
    
    sort(votes.begin(), votes.end(), compare);
    
    vector<int> ans(n);
    
    for(int i=0;i<n;i++)
    {
        ans[votes[i].second]=i;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<' ';
    }
    

    return 0;
}
