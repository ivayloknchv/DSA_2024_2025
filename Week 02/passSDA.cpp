#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/practice-1-sda/challenges/mission-sda/problem

int N, M, arr[1000];

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int negativeIdx=0;
    long long negativeMark=0;
    
    
    cin>>M>>N;
    
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        
        if(arr[i]<0)
        {
            negativeIdx=i;
            negativeMark=arr[i];
        }
    }
    
    for(int i=0;i<N;i++)
    {
        if(i==negativeIdx)
        {
            continue;
        }
        if(arr[i]>M)
        {
            negativeMark+=arr[i]-M;
        }
    }
    
    if(negativeMark>=M)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    return 0;
}

