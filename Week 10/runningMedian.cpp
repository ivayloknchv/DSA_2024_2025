#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-20232024-test-4/challenges/challenge-4442/problem

void median(vector<int>& nums) 
{
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, greater<>> right;
    
    for(int n : nums)
    {
        if(left.empty() || left.top() > n)
        {
            left.push(n);
        }
        else
        {
            right.push(n);
        }

        if (left.size() > right.size() + 1) 
        {
            right.push(left.top());
            left.pop();
        } 
        else if (right.size() > left.size() + 1) 
        {
            left.push(right.top());
            right.pop();
        }

        if(left.size()==right.size())
        {
            double median = (1.0 * left.top() + right.top()) / 2.0;
            printf("%.1f\n", median);
        }
        else if(left.size()>right.size())
        {
            double median = 1.0 * left.top();
            printf("%.1f\n", median);
        }
        else
        {
            double median = 1.0 * right.top();
            printf("%.1f\n", median);
        }
    }    
    
}

int main() 
{
    int N = 0;
    cin>>N;
    vector<int> nums(N);
    
    for(int i =0; i < N; i++)
    {
        cin>>nums[i];
    }
    
    median(nums);
    return 0;
}
