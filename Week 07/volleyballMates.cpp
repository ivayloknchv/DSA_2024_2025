#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-8/challenges/volleyball-friends/problem

int main() 
{
    set<int> friends;
    int start = 0, N = 0;
    cin>>start>>N;
    
    friends.insert(start);
    
    while(N--)
    {
        int x =0 , y=0;
        cin>>x>>y;
        
        if(friends.find(x)!=friends.end())
        {
            friends.insert(y);
        }
    }
    
    cout<<friends.size();
    
    return 0;
}
