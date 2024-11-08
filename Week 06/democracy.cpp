#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-4-2024/challenges/challenge-3722/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N=0;
    cin>>N;
    
    vector<int> nums(N);
    
    for(int i = 0; i < N; i++)
    {
        cin>>nums[i];
    }
    
    stack<int> st;
    
    for(int i =0; i < N; i++)
    {
        if(nums[i]>0)
        {
            st.push(nums[i]);
        }
        else
        {
            while(!st.empty() && st.top()>0 && st.top()<abs(nums[i]))
            {
                st.pop();
            }
            if(!st.empty() && st.top()+nums[i]==0)
            {
                st.pop();
            }
            else if(st.empty() || st.top()<0)
            {
                st.push(nums[i]);
            }
        }
    }
    vector<int> res;
    
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    
    for(int i = res.size()-1; i>=0; i--)
    {
        cout<<res[i]<<' ';
    }
    return 0;
}
