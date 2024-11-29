#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// https://www.hackerrank.com/contests/sda-homework-9/challenges/0-1-1/problem

int main() 
{
    int n = 0;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        int num=0;
        cin>>num;
        
        if(num==0)
        {
            num=-1;
        }
        
        v[i]=num;
    }
    
    vector<int> prefSum(n);
    prefSum[0]=v[0];
    
    for(int i = 1; i < n; i++)
    {
        prefSum[i]=v[i]+prefSum[i-1];
    }
    
    unordered_map<int, int> m; // num -> first idx of occurance
    
    int maxSize=0;
    
    for(int i = 0; i<n; i++)
    {
        if(m.find(-prefSum[i])==m.end())
        {
            m[-prefSum[i]]=i;
        }
        else
        {
            maxSize=max(maxSize, i-m[-prefSum[i]]);
        }
    }
    cout<<maxSize;
    
    return 0;
}
