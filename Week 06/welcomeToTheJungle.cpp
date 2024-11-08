#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// https://www.hackerrank.com/contests/practice-4-sda/challenges/welcome-to-the-jungle/problem

int main() 
{
    int N = 0;
    cin>>N;
    
    vector<int> trees(N);
    
    for(int i = 0; i < N; i++)
    {
        cin>>trees[i];
    }
    
    int idx = N - 1;
    int maxSize = 0;
    stack<int> st;
    
    for (int i = N - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top()<=trees[i])
        {
            st.pop();
        }
        st.push(trees[i]);
        
        if(maxSize<=st.size())
        {
            maxSize=st.size();
            idx=i;
        }
    }
    
    cout<<idx;
    
    return 0;
}
