#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-2020-2021-test5-trgdcw/challenges/challenge-2712/problem

int main() 
{
    stack<int> nums;
    stack<int> removedNums;
    int N = 0;
    cin>>N;
    
    for(int i = 0; i < N; i++)
    {
        int curr = 0;
        cin>>curr;
        
        if(curr>=0)
        {
            nums.push(curr);
        }
        else if(curr == -1)
        {
            if(nums.empty())
            {
                continue;
            }
            int t = nums.top();
            nums.pop();
            removedNums.push(t);
        }
        else
        {
            if(removedNums.empty())
            {
                continue;
            }
            int f = removedNums.top();
            removedNums.pop();
            nums.push(f);
        }
    }
    
    int sum = 0;
    
    while(!nums.empty())
    {
        sum+=nums.top();
        nums.pop();
    }
    cout<<sum;
    return 0;
}
