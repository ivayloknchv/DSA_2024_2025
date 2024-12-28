#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int N = 0;
    cin>>N;
    vector<int> nums(N, 0);
    
    for(int i = 0; i < N; i++)
    {
        cin>>nums[i];
    }
    
    int Q = 0;
    cin>>Q;
    
    while(Q--)
    {
        int curr = 0;
        cin>>curr;
        auto lower = lower_bound(nums.begin(), nums.end(), curr);
        auto upper = upper_bound(nums.begin(), nums.end(), curr);
        
        if(lower==upper)
        {
            cout<<(upper-nums.begin())<<'\n';
        }
        else
        {
            cout<<lower-nums.begin()<<' '<<upper-nums.begin()-1<<'\n';
        }
    }
    return 0;
}
