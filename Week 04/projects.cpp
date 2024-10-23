#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-3-2023/challenges/-8/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N = 0, D = 0;
    
    cin>>N>>D;
    
    vector<long long>nums(N);
    
    for(long long i = 0; i < N; i++)
    {
        cin>>nums[i];
    }
    
    long long fast=0;
    long long slow=0;
    long long counter = 0;
    
    sort(nums.begin(), nums.end());
    
    while(fast < N && slow < N)
    {
        if(nums[fast]-nums[slow] == D)
        {
            counter++;
            fast++;
            slow++;
        }
        else if(nums[fast] - nums[slow] < D)
        {
            fast++;
        }
        else
        {
            slow++;
        }
    }
    
    cout<<counter;
    
    return 0;
}
