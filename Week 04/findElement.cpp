#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-2019-2020-exam-2e3nr4rr/challenges/find-element-sda/problem

int main() 
{
    int N = 0;
    cin>>N;
    
    vector<int> nums(N);
    
    for(int i = 0; i < N; i++)
    {
        cin>>nums[i];
    }
    
    int Q = 0;
    cin>>Q;
    
    while(Q--)
    {
        int req=0;
        cin>>req;
        
        auto lower=lower_bound(nums.begin(), nums.end(),req);
        auto upper=upper_bound(nums.begin(), nums.end(), req);
        
        
        if(lower==upper )
        {
            cout<<lower-nums.begin()<<'\n';
        }
        else
        {
            int start=lower-nums.begin();
            int end=upper-nums.begin();
            cout<<start<<' '<<end - 1<<'\n';
        }
        
    }
    
    return 0;
}
