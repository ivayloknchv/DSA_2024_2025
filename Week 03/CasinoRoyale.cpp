#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-2-2022/challenges/1-146-1/problem

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int>evens;
    vector<int>odds;
    
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        
        if(temp%2==0)
        {
            evens.push_back(temp);
        }
        else
        {
            odds.push_back(temp);
        }
        
    }
    
    for (size_t i=0;i<evens.size();i++)
    {
        cout<<evens[i]<<'\n';
    }
    
    for(size_t i=0;i<odds.size();i++)
    {
        cout<<odds[i]<<'\n';
    }
    return 0;
}
