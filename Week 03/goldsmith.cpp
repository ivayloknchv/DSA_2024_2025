#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-test/challenges/challenge-1604/problem

int main() {
    
    int N=0;
    cin>>N;
    
    vector<int> nums(N);
    
    for(int i=0;i<N;i++)
    {
        cin>>nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    
    for(int i=N-1; i>=2;i--)
    {
        int current=nums[i];
        
        int l=0;
        int r=i-1;
        
        while(l<r)
        {
            if(nums[l] + nums[r] == current)
            {
                cout<<"true";
                return 0;
            }
            
            else if(nums[l] + nums[r] > current)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    
    cout<<"false";
    return 0;
}
