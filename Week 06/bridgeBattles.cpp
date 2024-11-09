#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-5-2023/challenges/bridge-battle-1/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = 0;
    cin>>N;
    vector<int> v(N);
    
    for(int i = 0; i < N; i++)
    {
        cin>>v[i];
    }
    
    stack<int> s;
    
    for(int i = 0; i < N; i++)
    {
        if(v[i]>0)
        {
            s.push(v[i]);
        }
        else
        {
            while(!s.empty() && s.top()>0 && s.top()<abs(v[i]))
            {
                s.pop();
            }
            if(!s.empty() && s.top()+v[i] == 0)
            {
                s.pop();
            }
            else if(s.empty() || s.top()<0)
            {
                s.push(v[i]);
            }
        }
    }
    
    vector<int> res(s.size());
    int ctr = s.size()-1;
    while(!s.empty())
    {
        res[ctr--]=s.top();
        s.pop();
    }
    
    for(int i : res)
    {
        cout<<i<<' ';
    }
    return 0;
}
