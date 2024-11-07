#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// https://www.hackerrank.com/contests/kontrolno-3/challenges/challenge-4334/problem

bool isSymmetric(const vector<int>& nums)
{
    if(nums.size()%2==1)
    {
        return false;
    }
    stack<int> st;
    
    for(int n : nums)
    {
        if(!st.empty() && st.top()>0 && st.top()+n==0)
        {
            st.pop();
        }
        else
        {
            st.push(n);
        }
    }
    
    return st.empty();
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0; int K =0;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        cin>>K;
        vector<int> nums(K);
        
        for(int j = 0; j < K; j++)
        {
            cin>>nums[j];
        }
        
        if(isSymmetric(nums))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
