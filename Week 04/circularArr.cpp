#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

https://www.hackerrank.com/contests/sda-2020-2021-test3-trvdd/challenges/weird-array-1/problem

int binaryFind(const vector<int>& nums, int X)
{
    int l = 0;
    int r = nums.size() - 1;
    
    while (l <= r)
    {
        int mid =  l + (r - l) / 2;
        
        if(nums[mid] == X)
        {
            return mid;
        }
        
        if (nums[l]<=nums[mid])
        {
            if(nums[l] <= X && X <= nums[mid])
            {
                r=mid-1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (nums[mid]<=X && X<=nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    
    return -1;
}

int main() 
{
    int N = 0, Q = 0, X = 0;
    cin>>N;
    
    vector<int> nums(N);
    
    for(int i = 0 ; i < N; i++)
    {
        cin>>nums[i];
    }
    cin>>Q;
    while(Q--)
    {
        cin>>X;
        cout<<binaryFind(nums,X)<<'\n';
    }
    return 0;
}
