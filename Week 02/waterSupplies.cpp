#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/practice-1-sda/challenges/challenge-2196/problem

int arr[100001]{};
int N;

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    
    int l=0, r=N-1;
    int maxWater=0;
    
    while(l<=r)
    {
        maxWater=max(maxWater, (r-l)*min(arr[l],arr[r]));
        
        if(arr[l]<arr[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    
    cout<<maxWater;
    
    return 0;
}
